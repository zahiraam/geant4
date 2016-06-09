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
#ifndef G4BERTINIREGIONMODEL
#define G4BERTINIREGIONMODEL

#include "G4ios.hh"
#include "g4std/vector"
#include <math.h>
#include "globals.hh"
#include "G4Proton.hh"
#include "G4Neutron.hh"


typedef G4std::vector<G4double>::const_iterator iterator; 

class G4BertiniRegionModel /// :public G4VRegionModel
{
public:
  G4BertiniRegionModel(const G4int numberOfLayers, const G4int A, const G4int Z);
  ~G4BertiniRegionModel();

  /// instead of A and Z outer radius of the nucleus?
  /// void Init(const G4int numberOfLayers, const G4int A, const G4int Z);
  G4double GetDensity(G4double radius);
  G4double GetPotentialEnergy(G4double r, G4int particle);
  G4double GetMaximumNucleonMomentum(G4double radius, G4int nucleon);
  /// G4double NumberOfRegions();   

private:

  G4int massNumber;
  G4int protonNumber;
  G4std::vector<G4double> radius; /// contains the outer radiuses of the shells
  G4std::vector<G4double> density;
  G4std::vector<G4double> protonFermiEnergy;
  G4std::vector<G4double> neutronFermiEnergy;
  G4std::vector<G4double> protonFermiMomentum;
  G4std::vector<G4double> neutronFermiMomentum;
  
  G4std::vector<G4double> protonPotentialEnergy;
  G4std::vector<G4double> neutronPotentialEnergy;

  static const G4double radius0; 
  static const G4double BE;
  /// static const G4double pi = 3.141592;

  G4double GetFermiMomentum(G4double density, G4double mass);
  G4double GetFermiEnergy(G4double density, G4double mass);
};  
#endif







