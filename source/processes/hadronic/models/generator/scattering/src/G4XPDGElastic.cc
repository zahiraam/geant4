//
// ********************************************************************
// * DISCLAIMER                                                       *
// *                                                                  *
// * The following disclaimer summarizes all the specific disclaimers *
// * of contributors to this software. The specific disclaimers,which *
// * govern, are listed with their locations in:                      *
// *   http://cern.ch/geant4/license                                  *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.                                                             *
// *                                                                  *
// * This  code  implementation is the  intellectual property  of the *
// * GEANT4 collaboration.                                            *
// * By copying,  distributing  or modifying the Program (or any work *
// * based  on  the Program)  you indicate  your  acceptance of  this *
// * statement, and all its terms.                                    *
// ********************************************************************
//
//
// $Id: G4XPDGElastic.cc,v 1.5 2002/12/12 19:17:53 gunter Exp $ //
// -------------------------------------------------------------------
//      
// PDG  Elastic cross section 
// PDG fits, Phys.Rev. D50 (1994), 1335
//
//
// -------------------------------------------------------------------

#include "globals.hh"
#include "G4ios.hh"
#include "G4XPDGElastic.hh"
#include "G4KineticTrack.hh"
#include "G4ParticleDefinition.hh"
#include "G4DataVector.hh"

#include "G4AntiProton.hh"
#include "G4AntiNeutron.hh"
#include "G4Proton.hh"
#include "G4Neutron.hh"
#include "G4PionPlus.hh"
#include "G4PionMinus.hh"
#include "G4KaonMinus.hh"
#include "G4KaonPlus.hh"

const G4double G4XPDGElastic::_lowLimit = 5. * GeV;
const G4double G4XPDGElastic::_highLimit = DBL_MAX;

// Parameters of the PDG Elastic cross-section fit (Rev. Particle Properties, 1998)
// Columns are: lower and higher fit range, X, Y1, Y2
const G4int G4XPDGElastic::nPar = 7;
// p pi+
const G4double G4XPDGElastic::pPiPlusPDGFit[7] =  { 2.,     200.,   0.,   11.4, -0.4,  0.079,  0. };
// p pi-
const G4double G4XPDGElastic::pPiMinusPDGFit[7] = { 2.,     360.,   1.76, 11.2, -0.64, 0.043,  0. };
// p K+
const G4double G4XPDGElastic::pKPlusPDGFit[7] =   { 2.,     175.,    5.0,  8.1, -1.8,  0.16,  -1.3 }; 
// p K-
const G4double G4XPDGElastic::pKMinusPDGFit[7] =  { 2.,     175.,    7.3,  0.,   0.,   0.29,  -2.40 };
// p p
const G4double G4XPDGElastic::ppPDGFit[7] =       { 2.,    2100.,   11.9, 26.9, -1.21, 0.169, -1.85 };
// p pbar
const G4double G4XPDGElastic::ppbarPDGFit[7] =    { 5., 1730000.,   10.2, 52.7, -1.16, 0.125, -1.28 };
// n pbar
const G4double G4XPDGElastic::npbarPDGFit[7] =    { 1.1,      5.55, 36.5,  0.,   0.,   0.,    -11.9 };


G4XPDGElastic::G4XPDGElastic() 
{
  G4String proton = G4Proton::ProtonDefinition()->GetParticleName();
  G4String neutron = G4Neutron::NeutronDefinition()->GetParticleName();
  G4String piPlus = G4PionPlus::PionPlusDefinition()->GetParticleName();
  G4String piMinus = G4PionMinus::PionMinusDefinition()->GetParticleName();
  G4String KPlus = G4KaonPlus::KaonPlusDefinition()->GetParticleName();
  G4String KMinus = G4KaonMinus::KaonMinusDefinition()->GetParticleName();
  G4String antiproton = G4AntiProton::AntiProtonDefinition()->GetParticleName();
  
  G4std::pair<G4String,G4String> pp(proton,proton);
  G4std::pair<G4String,G4String> pn(proton,neutron);
  G4std::pair<G4String,G4String> piPlusp(piPlus,proton);
  G4std::pair<G4String,G4String> piMinusp(piMinus,proton);
  G4std::pair<G4String,G4String> KPlusp(KPlus,proton);
  G4std::pair<G4String,G4String> KMinusp(KMinus,proton);
  G4std::pair<G4String,G4String> nn(neutron,neutron);
  G4std::pair<G4String,G4String> ppbar(proton,antiproton);
  G4std::pair<G4String,G4String> npbar(antiproton,neutron);

  G4std::vector<G4double> ppData;
  G4std::vector<G4double> pPiPlusData;
  G4std::vector<G4double> pPiMinusData;
  G4std::vector<G4double> pKPlusData;
  G4std::vector<G4double> pKMinusData;
  G4std::vector<G4double> ppbarData;
  G4std::vector<G4double> npbarData;

  G4int i;
  for (i=0; i<2; i++) 
    {      
      ppData.push_back(ppPDGFit[i] * GeV); 
      pPiPlusData.push_back(pPiPlusPDGFit[i] * GeV); 
      pPiMinusData.push_back(pPiMinusPDGFit[i] * GeV); 
      pKPlusData.push_back(pKPlusPDGFit[i] * GeV); 
      pKMinusData.push_back(pKMinusPDGFit[i] * GeV); 
      ppbarData.push_back(ppbarPDGFit[i] * GeV);
      npbarData.push_back(npbarPDGFit[i] * GeV);
    }

  for (i=2; i<nPar; i++) 
    {      
      ppData.push_back(ppPDGFit[i]); 
      pPiPlusData.push_back(pPiPlusPDGFit[i]); 
      pPiMinusData.push_back(pPiMinusPDGFit[i]); 
      pKPlusData.push_back(pKPlusPDGFit[i]); 
      pKMinusData.push_back(pKMinusPDGFit[i]); 
      ppbarData.push_back(ppbarPDGFit[i]);
      npbarData.push_back(npbarPDGFit[i]);
    }

  xMap[nn] = ppData;
  xMap[pp] = ppData;
  xMap[pn] = ppData;
  xMap[piPlusp] = pPiPlusData;
  xMap[piMinusp] = pPiMinusData;
  xMap[KPlusp] = pKPlusData;
  xMap[KMinusp] = pKMinusData;
  xMap[ppbar] = ppbarData;
  xMap[npbar] = npbarData;
}


G4XPDGElastic::~G4XPDGElastic()
{ }


G4bool G4XPDGElastic::operator==(const G4XPDGElastic &right) const
{
  return (this == (G4XPDGElastic *) &right);
}


G4bool G4XPDGElastic::operator!=(const G4XPDGElastic &right) const
{
  return (this != (G4XPDGElastic *) &right);
}


G4double G4XPDGElastic::CrossSection(const G4KineticTrack& trk1, const G4KineticTrack& trk2) const
{
  // Elastic Cross-section fit, 1994 Review of Particle Properties, (1994), 1

  G4double sigma = 0.;

  G4ParticleDefinition* def1 = trk1.GetDefinition();
  G4ParticleDefinition* def2 = trk2.GetDefinition();
  G4String name1 = def1->GetParticleName();
  G4String name2 = def2->GetParticleName();     
  
  G4double sqrtS = (trk1.Get4Momentum() + trk2.Get4Momentum()).mag();
  G4double m1 = def1->GetPDGMass();
  G4double m2 = def2->GetPDGMass();
  G4double m = G4std::max(m1,m2);
  //  if (m1 > m) m = m1;
  
  G4double pLab = 0.;

  if (m > 0. && sqrtS > (m1 + m2)) 
    {
      pLab = sqrt( (sqrtS*sqrtS - (m1+m2)*(m1+m2) ) * (sqrtS*sqrtS - (m1-m2)*(m1-m2)) ) / (2*m);
      
      // The PDG fit formula requires p in GeV/c
      
      G4double enc1 = def1->GetPDGEncoding();
      G4double enc2 = def2->GetPDGEncoding();
      G4double coeff = -1.;
      if ( (enc1 < 0 && enc2 >0) || (enc2 < 0 && enc1 >0) ) coeff = 1.;
      
      // Order the pair: first is the lower mass particle, second is the higher mass one
      G4std::pair<G4String,G4String> trkPair(def1->GetParticleName(),def2->GetParticleName());
      if (def1->GetPDGMass() > def2->GetPDGMass())
	trkPair = G4std::pair<G4String,G4String>(def2->GetParticleName(),def1->GetParticleName());
      
      G4std::vector<G4double> data; 
      G4double pMinFit = 0.;
      G4double pMaxFit = 0.;
      G4double aFit = 0.;
      G4double bFit = 0.;
      G4double cFit = 0.;
      G4double dFit = 0.;
      G4double nFit = 0.;

      // Debug
//      G4cout << "Map has " << xMap.size() << " elements" << G4endl;
      // Debug end
 
      if (xMap.find(trkPair) != xMap.end())
	{
	  PairDoubleMap::const_iterator iter;
	  for (iter = xMap.begin(); iter != xMap.end(); ++iter)
	    {
	      G4std::pair<G4String,G4String> thePair = (*iter).first;
	      if (thePair == trkPair)
		{
		  data = (*iter).second;
		  pMinFit = data[0];
		  pMaxFit = data[1];
		  aFit = data[2];
		  bFit = data[3];
		  cFit = data[5];
		  dFit = data[6];
		  nFit = data[4];
	      
		  if (pLab < pMinFit) return 0.0;
		  if (pLab > pMaxFit )
		    G4cout << "WARNING! G4XPDGElastic::PDGElastic " 
			   << trk1.GetDefinition()->GetParticleName() << "-" 
			   << trk2.GetDefinition()->GetParticleName() 
			   << " elastic cross section: momentum " 
			   << pLab / GeV << " GeV outside valid fit range " 
			   << pMinFit /GeV << "-" << pMaxFit / GeV
			   << G4endl;
		  
		  pLab /= GeV;
		  if (pLab > 0.) 
		    {
		      G4double logP = log(pLab);
		      sigma = aFit + bFit * pow(pLab, nFit) + cFit * logP*logP + dFit * logP;
		      sigma = sigma * millibarn;
		    }
		}
	    }
	}
      else
	{
	  G4cout << "G4XPDGElastic::CrossSection - Data not found in Map" << G4endl;
	}
    }
  
  if (sigma < 0.)
    {
      G4cout << "WARNING! G4XPDGElastic::PDGElastic "      
	     << name1 << "-" << name2
	     << " elastic cross section: momentum " 
	     << pLab << " GeV, negative cross section " 
	     << sigma / millibarn << " mb set to 0" << G4endl;
      sigma = 0.;
    }
  
  return sigma;
}


G4String G4XPDGElastic::Name() const
{
  G4String name = "PDGElastic ";
  return name;
}


G4bool G4XPDGElastic::IsValid(G4double e) const
{
  G4bool answer = InLimits(e,_lowLimit,_highLimit);

  return answer;
}











