//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
// $Id: G4BetheBlochModel.cc,v 1.13 2007/05/22 17:34:36 vnivanch Exp $
// GEANT4 tag $Name: geant4-09-00 $
//
// -------------------------------------------------------------------
//
// GEANT4 Class header file
//
//
// File name:     G4BetheBlochModel
//
// Author:        Vladimir Ivanchenko on base of Laszlo Urban code
//
// Creation date: 03.01.2002
//
// Modifications:
//
// 04-12-02 Fix problem of G4DynamicParticle constructor (V.Ivanchenko)
// 23-12-02 Change interface in order to move to cut per region (V.Ivanchenko)
// 27-01-03 Make models region aware (V.Ivanchenko)
// 13-02-03 Add name (V.Ivanchenko)
// 24-03-05 Add G4EmCorrections (V.Ivanchenko)
// 11-04-05 Major optimisation of internal interfaces (V.Ivantchenko)
// 11-02-06 ComputeCrossSectionPerElectron, ComputeCrossSectionPerAtom (mma)
// 12-02-06 move G4LossTableManager::Instance()->EmCorrections() 
//          in constructor (mma)
//
// -------------------------------------------------------------------
//


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#include "G4BetheBlochModel.hh"
#include "Randomize.hh"
#include "G4Electron.hh"
#include "G4LossTableManager.hh"
#include "G4EmCorrections.hh"
#include "G4ParticleChangeForLoss.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

using namespace std;

G4BetheBlochModel::G4BetheBlochModel(const G4ParticleDefinition* p, 
                                     const G4String& nam)
  : G4VEmModel(nam),
  particle(0),
  tlimit(DBL_MAX),
  twoln10(2.0*log(10.0)),
  bg2lim(0.0169),
  taulim(8.4146e-3),
  isIon(false)
{
  if(p) SetParticle(p);
  theElectron = G4Electron::Electron();
  corr = G4LossTableManager::Instance()->EmCorrections();  
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4BetheBlochModel::~G4BetheBlochModel()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4double G4BetheBlochModel::MinEnergyCut(const G4ParticleDefinition*,
                                         const G4MaterialCutsCouple* couple)
{
  return couple->GetMaterial()->GetIonisation()->GetMeanExcitationEnergy();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void G4BetheBlochModel::Initialise(const G4ParticleDefinition* p,
                                   const G4DataVector&)
{
  if (!particle) SetParticle(p);
  G4String pname = particle->GetParticleName();
  if (particle->GetParticleType() == "nucleus" &&
     pname != "deuteron" && pname != "triton") isIon = true;

  if (pParticleChange) 
    fParticleChange = reinterpret_cast<G4ParticleChangeForLoss*>
                                                              (pParticleChange);
  else 
    fParticleChange = new G4ParticleChangeForLoss();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4double G4BetheBlochModel::ComputeCrossSectionPerElectron(
                                           const G4ParticleDefinition* p,
                                                 G4double kineticEnergy,
                                                 G4double cutEnergy,
                                                 G4double maxKinEnergy)						  
{
  G4double cross = 0.0;
  G4double tmax = MaxSecondaryEnergy(p, kineticEnergy);
  G4double maxEnergy = min(tmax,maxKinEnergy);
  if(cutEnergy < maxEnergy) {

    G4double totEnergy = kineticEnergy + mass;
    G4double energy2   = totEnergy*totEnergy;
    G4double beta2     = kineticEnergy*(kineticEnergy + 2.0*mass)/energy2;

    cross = 1.0/cutEnergy - 1.0/maxEnergy - beta2*log(maxEnergy/cutEnergy)/tmax;

    // +term for spin=1/2 particle
    if( 0.5 == spin ) cross += 0.5*(maxEnergy - cutEnergy)/energy2;

    cross *= twopi_mc2_rcl2*chargeSquare/beta2;
  }
  
   // G4cout << "BB: e= " << kineticEnergy << " tmin= " << cutEnergy 
   //        << " tmax= " << tmax << " cross= " << cross << G4endl;
  
  return cross;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4double G4BetheBlochModel::ComputeCrossSectionPerAtom(
                                           const G4ParticleDefinition* p,
                                                 G4double kineticEnergy,
						 G4double Z, G4double,
                                                 G4double cutEnergy,
                                                 G4double maxEnergy)
{
  G4double cross = Z*ComputeCrossSectionPerElectron
                                         (p,kineticEnergy,cutEnergy,maxEnergy);
  return cross;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4double G4BetheBlochModel::CrossSectionPerVolume(
					   const G4Material* material,
                                           const G4ParticleDefinition* p,
                                                 G4double kineticEnergy,
                                                 G4double cutEnergy,
                                                 G4double maxEnergy)
{
  G4double eDensity = material->GetElectronDensity();
  G4double cross = eDensity*ComputeCrossSectionPerElectron
                                         (p,kineticEnergy,cutEnergy,maxEnergy);
  return cross;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4double G4BetheBlochModel::ComputeDEDXPerVolume(const G4Material* material,
						 const G4ParticleDefinition* p,
						 G4double kineticEnergy,
						 G4double cut)
{
  G4double tmax      = MaxSecondaryEnergy(p, kineticEnergy);
  G4double cutEnergy = min(cut,tmax);

  G4double tau   = kineticEnergy/mass;
  G4double gam   = tau + 1.0;
  G4double bg2   = tau * (tau+2.0);
  G4double beta2 = bg2/(gam*gam);

  G4double eexc  = material->GetIonisation()->GetMeanExcitationEnergy();
  G4double eexc2 = eexc*eexc;
  G4double cden  = material->GetIonisation()->GetCdensity();
  G4double mden  = material->GetIonisation()->GetMdensity();
  G4double aden  = material->GetIonisation()->GetAdensity();
  G4double x0den = material->GetIonisation()->GetX0density();
  G4double x1den = material->GetIonisation()->GetX1density();

  G4double eDensity = material->GetElectronDensity();

  G4double dedx = log(2.0*electron_mass_c2*bg2*cutEnergy/eexc2)
                - (1.0 + cutEnergy/tmax)*beta2;

  if(0.5 == spin) {
    G4double del = 0.5*cutEnergy/(kineticEnergy + mass);
    dedx += del*del;
  }

  // density correction
  G4double x = log(bg2)/twoln10;
  if ( x >= x0den ) {
    dedx -= twoln10*x - cden ;
    if ( x < x1den ) dedx -= aden*pow((x1den-x),mden) ;
  }

  // shell correction
  dedx -= 2.0*corr->ShellCorrection(p,material,kineticEnergy);

  // now compute the total ionization loss

  if (dedx < 0.0) dedx = 0.0 ;

  dedx *= twopi_mc2_rcl2*chargeSquare*eDensity/beta2;

  //High order correction only for hadrons
  if(!isIon) dedx += corr->HighOrderCorrections(p,material,kineticEnergy);

  return dedx;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void G4BetheBlochModel::SampleSecondaries(vector<G4DynamicParticle*>* vdp,
					  const G4MaterialCutsCouple*,
					  const G4DynamicParticle* dp,
					  G4double minKinEnergy,
					  G4double maxEnergy)
{
  G4double kineticEnergy = dp->GetKineticEnergy();
  G4double tmax = MaxSecondaryEnergy(dp->GetDefinition(),kineticEnergy);

  G4double maxKinEnergy = min(maxEnergy,tmax);
  if(minKinEnergy >= maxKinEnergy) return;

  G4double totEnergy     = kineticEnergy + mass;
  G4double etot2         = totEnergy*totEnergy;
  G4double beta2         = kineticEnergy*(kineticEnergy + 2.0*mass)/etot2;

  G4double deltaKinEnergy, f;

  // sampling follows ...
  do {
    G4double q = G4UniformRand();
    deltaKinEnergy = minKinEnergy*maxKinEnergy
                    /(minKinEnergy*(1.0 - q) + maxKinEnergy*q);

    f = 1.0 - beta2*deltaKinEnergy/tmax;
    if( 0.5 == spin ) f += 0.5*deltaKinEnergy*deltaKinEnergy/etot2;

    if(f > 1.0) {
        G4cout << "G4BetheBlochModel::SampleSecondary Warning! "
               << "Majorant 1.0 < "
               << f << " for Edelta= " << deltaKinEnergy
               << G4endl;
    }

  } while( G4UniformRand() > f );

  G4double totMomentum = totEnergy*sqrt(beta2);
  G4double deltaMomentum =
           sqrt(deltaKinEnergy * (deltaKinEnergy + 2.0*electron_mass_c2));
  G4double cost = deltaKinEnergy * (totEnergy + electron_mass_c2) /
                                   (deltaMomentum * totMomentum);
  if(cost > 1.0) {
    G4cout << "### G4BetheBlochModel WARNING: cost= " 
	   << cost << " > 1 for "
	   << dp->GetDefinition()->GetParticleName()
	   << " Ekin(MeV)= " <<  kineticEnergy
	   << " p(MeV/c)= " <<  totMomentum
	   << " delEkin(MeV)= " << deltaKinEnergy
	   << " delMom(MeV/c)= " << deltaMomentum
	   << " tmin(MeV)= " << minKinEnergy
	   << " tmax(MeV)= " << maxKinEnergy
           << " dir= " << dp->GetMomentumDirection()
	   << G4endl;
    cost = 1.0;
  }
  G4double sint = sqrt((1.0 - cost)*(1.0 + cost));

  G4double phi = twopi * G4UniformRand() ;


  G4ThreeVector deltaDirection(sint*cos(phi),sint*sin(phi), cost);
  G4ThreeVector direction = dp->GetMomentumDirection();
  deltaDirection.rotateUz(direction);

  // create G4DynamicParticle object for delta ray
  G4DynamicParticle* delta = new G4DynamicParticle(theElectron,
                                                 deltaDirection,deltaKinEnergy);

  vdp->push_back(delta);

  // Change kinematics of primary particle
  kineticEnergy       -= deltaKinEnergy;
  G4ThreeVector finalP = direction*totMomentum - deltaDirection*deltaMomentum;
  finalP               = finalP.unit();
  
  fParticleChange->SetProposedKineticEnergy(kineticEnergy);
  fParticleChange->SetProposedMomentumDirection(finalP);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......