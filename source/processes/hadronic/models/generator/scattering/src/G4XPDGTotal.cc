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
// PDG fits, 1998 Review of Particle Properties, European Phys. J. 3(1998), 1
// -------------------------------------------------------------------

#include "globals.hh"
#include "G4ios.hh"
#include "G4XPDGTotal.hh"
#include "G4KineticTrack.hh"
#include "G4ParticleDefinition.hh"
#include "G4DataVector.hh"
#include "G4AntiProton.hh"
#include "G4AntiNeutron.hh"
#include "G4Proton.hh"
#include "G4Neutron.hh"
#include "G4PionPlus.hh"
#include "G4PionMinus.hh"
#include "G4Gamma.hh"
#include "G4KaonMinus.hh"
#include "G4KaonPlus.hh"

const G4double G4XPDGTotal::_lowLimit = 2.99999 * GeV;
const G4double G4XPDGTotal::_highLimit = DBL_MAX;

// Parameters of the PDG total cross-section fit (Rev. Particle Properties, 1998)
// Columns are: lower and higher fit range, X, Y1, Y2
const G4int G4XPDGTotal::nFit = 5;
// p p 
const G4double G4XPDGTotal::ppPDGFit[5] =       { 3., 40000., 18.256,   60.19,   33.43 };
// n p 
const G4double G4XPDGTotal::npPDGFit[5] =        { 3.,     40., 18.256,   61.14,   29.80 };
// pi p
const G4double G4XPDGTotal::pipPDGFit[5] =       { 3.,     40., 11.568,   27.55,    5.62 }; 
// K p
const G4double G4XPDGTotal::KpPDGFit[5] =        { 3.,     40., 10.376,   15.57,   13.19 };
// K n
const G4double G4XPDGTotal::KnPDGFit[5] =        { 3.,     40., 10.376,   14.29,    7.38 };
// gamma p
const G4double G4XPDGTotal::gammapPDGFit[5] =    { 3.,    300.,  0.0577,   0.1171,  0. };
//gamma gamma
const G4double G4XPDGTotal::gammagammaPDGFit[5] = { 3.,    300.,  0.000156, 0.00032, 0. };


G4XPDGTotal::G4XPDGTotal() 
{
  G4std::pair<G4String,G4String> pp(G4Proton::ProtonDefinition()->GetParticleName(),
				    G4Proton::ProtonDefinition()->GetParticleName());
  G4std::pair<G4String,G4String> pn(G4Proton::ProtonDefinition()->GetParticleName(),
				    G4Neutron::NeutronDefinition()->GetParticleName());
  G4std::pair<G4String,G4String> piPlusp(G4PionPlus::PionPlusDefinition()->GetParticleName(),
					 G4Proton::ProtonDefinition()->GetParticleName());
  G4std::pair<G4String,G4String> piMinusp(G4PionMinus::PionMinusDefinition()->GetParticleName(),
					  G4Proton::ProtonDefinition()->GetParticleName());
  G4std::pair<G4String,G4String> KPlusp(G4KaonPlus::KaonPlusDefinition()->GetParticleName(),
					G4Proton::ProtonDefinition()->GetParticleName());
  G4std::pair<G4String,G4String> KPlusn(G4KaonPlus::KaonPlusDefinition()->GetParticleName(),
					G4Neutron::NeutronDefinition()->GetParticleName());
  G4std::pair<G4String,G4String> KMinusp(G4KaonMinus::KaonMinusDefinition()->GetParticleName(),
					 G4Proton::ProtonDefinition()->GetParticleName());
  G4std::pair<G4String,G4String> KMinusn(G4KaonMinus::KaonMinusDefinition()->GetParticleName(),
					 G4Neutron::NeutronDefinition()->GetParticleName());
  G4std::pair<G4String,G4String> gp(G4Gamma::GammaDefinition()->GetParticleName(),
				    G4Proton::ProtonDefinition()->GetParticleName());
  G4std::pair<G4String,G4String> gg(G4Gamma::GammaDefinition()->GetParticleName(),
				    G4Gamma::GammaDefinition()->GetParticleName());
  G4std::pair<G4String,G4String> nn(G4Neutron::NeutronDefinition()->GetParticleName(),
				    G4Neutron::NeutronDefinition()->GetParticleName());
 
  G4std::vector<G4double> nnData;
  G4std::vector<G4double> ppData;
  G4std::vector<G4double> pnData;
  G4std::vector<G4double> pipData;
  G4std::vector<G4double> KpData;
  G4std::vector<G4double> KnData;
  G4std::vector<G4double> gpData;
  G4std::vector<G4double> ggData;

  G4int i;
  for (i=0; i<2; i++) 
    {   
      nnData.push_back(ppPDGFit[i] * GeV); 
      ppData.push_back(ppPDGFit[i] * GeV); 
      pnData.push_back(npPDGFit[i] * GeV); 
      pipData.push_back(pipPDGFit[i] * GeV); 
      KpData.push_back(KpPDGFit[i] * GeV); 
      KnData.push_back(KnPDGFit[i] * GeV); 
      gpData.push_back(gammapPDGFit[i] * GeV); 
      ggData.push_back(gammagammaPDGFit[i] * GeV); 
    }
  for (i=2; i<nFit; i++) 
    {   
      nnData.push_back(ppPDGFit[i]); 
      ppData.push_back(ppPDGFit[i]); 
      pnData.push_back(npPDGFit[i]); 
      pipData.push_back(pipPDGFit[i]); 
      KpData.push_back(KpPDGFit[i]); 
      KnData.push_back(KnPDGFit[i]); 
      gpData.push_back(gammapPDGFit[i]); 
      ggData.push_back(gammagammaPDGFit[i]); 
    }

  xMap[pp] = ppData;
  xMap[pn] = pnData;
  xMap[piPlusp] = pipData;
  xMap[piMinusp] = pipData;
  xMap[KPlusp] = KpData;
  xMap[KPlusn] = KnData;
  xMap[KMinusp] = KpData;
  xMap[KMinusn] = KnData;
  xMap[gp] = gpData;
  xMap[gg] = ggData;
  xMap[nn] = nnData;
}


G4XPDGTotal::~G4XPDGTotal()
{ }


G4bool G4XPDGTotal::operator==(const G4XPDGTotal &right) const
{
  return (this == (G4XPDGTotal *) &right);
}


G4bool G4XPDGTotal::operator!=(const G4XPDGTotal &right) const
{
  return (this != (G4XPDGTotal *) &right);
}


G4double G4XPDGTotal::CrossSection(const G4KineticTrack& trk1, 
				   const G4KineticTrack& trk2) const
{
  G4double sigma = 0.;

  G4double sqrtS = (trk1.Get4Momentum() + trk2.Get4Momentum()).mag();
  
  G4ParticleDefinition* def1 = trk1.GetDefinition();
  G4ParticleDefinition* def2 = trk2.GetDefinition();

  G4double enc1 = def1->GetPDGEncoding();
  G4double enc2 = def2->GetPDGEncoding();
  G4double coeff = -1.;
  if ( (enc1 < 0 && enc2 >0) || (enc2 < 0 && enc1 >0) ) coeff = 1.;

  // Order the pair: first is the lower mass particle, second is the higher mass one
  G4std::pair<G4String,G4String> trkPair(def1->GetParticleName(),def2->GetParticleName());

  if (def1->GetPDGMass() > def2->GetPDGMass())
    trkPair = G4std::pair<G4String,G4String>(def2->GetParticleName(),def1->GetParticleName());
 
  G4std::vector<G4double> data;   
      
  if (xMap.find(trkPair) != xMap.end())
    {

      PairDoubleMap::const_iterator iter;
      for (iter = xMap.begin(); iter != xMap.end(); ++iter)
	{
	  G4std::pair<G4String,G4String> thePair = (*iter).first;
	  if (thePair == trkPair)
	    {
	      data = (*iter).second;
	  
	      G4double eMinFit = data[0];
	      G4double eMaxFit = data[1];
	      G4double xFit = data[2];
	      G4double y1Fit = data[3];
	      G4double y2Fit = data[4];
	      
	      // Total Cross-section fit, 1998 Review of Particle Properties, European Phys. J. 3(1998), 1
	      
	      // Parameters from the PDG fit
	      const G4double epsilon = 0.095;
	      const G4double eta1 = -0.34;
	      const G4double eta2 = -0.55;
	      
	      if (sqrtS < eMinFit || sqrtS > eMaxFit)
		G4cout << "WARNING! G4XPDGTotal::PDGTotal extrapolating cross section at " 
		       << sqrtS / GeV 
		       << " GeV outside the PDG fit range "
		       << eMinFit / GeV << " - " << eMaxFit / GeV << " GeV " << G4endl;
	      
	      G4double s = (sqrtS * sqrtS) / (GeV*GeV);
	      
	      sigma = ( (xFit * pow(s,epsilon)) + 
			(y1Fit * pow(s,eta1)) + 
			(coeff * y2Fit * pow(s,eta2)) ) * millibarn;
	      
	      if (sigma < 0.)
		{
		  G4String name1 = def1->GetParticleName();
		  G4String name2 = def2->GetParticleName();
		  G4cout << "WARNING! G4XPDGTotal::PDGTotal "      
			 << name1 << "-" << name2 
			 << " total cross section: Ecm " 
			 << sqrtS / GeV << " GeV, negative cross section " 
			 << sigma / millibarn << " mb set to 0" << G4endl;
		  sigma = 0.;
		}
	    }
	}
    }
  return sigma;
}


G4String G4XPDGTotal::Name() const
{
  G4String name = "PDGTotal ";
  return name;
}


G4bool G4XPDGTotal::IsValid(G4double e) const
{
  G4bool answer = InLimits(e,_lowLimit,_highLimit);

  return answer;
}


G4double G4XPDGTotal::PDGTotal(G4double coeff,G4double sqrtS) const 
{
  return 0.;
}











