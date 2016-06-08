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
// $Id: GammaRayTelCalorimeterHit.hh,v 1.2 2001/07/11 09:56:56 gunter Exp $
// GEANT4 tag $Name: geant4-05-00 $
// ------------------------------------------------------------
//      GEANT 4 class header file
//      CERN Geneva Switzerland
//
//
//      ------------ GammaRayTelCalorimeterHit  ------
//           by R.Giannitrapani, F.Longo & G.Santin (13 nov 2000)
//
// ************************************************************
// This Class describe the hits on the Calorimeter

#ifndef GammaRayTelCalorimeterHit_h
#define GammaRayTelCalorimeterHit_h 1

#include "G4VHit.hh"
#include "G4THitsCollection.hh"
#include "G4Allocator.hh"
#include "G4ThreeVector.hh"


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

class GammaRayTelCalorimeterHit : public G4VHit
{
public:
  
  GammaRayTelCalorimeterHit();
  ~GammaRayTelCalorimeterHit();
  GammaRayTelCalorimeterHit(const GammaRayTelCalorimeterHit&);
  const GammaRayTelCalorimeterHit& operator=(const
						GammaRayTelCalorimeterHit&);
  int operator==(const GammaRayTelCalorimeterHit&) const;
  
  inline void* operator new(size_t);
  inline void  operator delete(void*);
  
  void Draw();
  void Print();

private:
  
  G4double EdepCAL;  // Energy deposited on the ACD tile
  G4ThreeVector pos; // Position of the hit
  G4int CALBarNumber; // Number of the CAL tile
  G4int CALPlaneNumber;    // Number of the CAL plane
  G4int IsCALPlane;    // Type of the plane (0 X, 1 Y)

public:
  
  inline void AddEnergy(G4double de) {EdepCAL += de;};
  inline void SetCALBarNumber(G4int i) {CALBarNumber = i;};
  inline void SetCALPlaneNumber(G4int i) {CALPlaneNumber = i;};
  inline void SetCALType(G4int i) {IsCALPlane = i;};
  inline void SetPos(G4ThreeVector xyz){ pos = xyz; }
  
  inline G4double GetEdepCAL()     { return EdepCAL; };
  inline G4int    GetCALBarNumber()   { return CALBarNumber; };
  inline G4int    GetCALPlaneNumber()   { return CALPlaneNumber; };
  inline G4int    GetCALType()   {return IsCALPlane;};      
  inline G4ThreeVector GetPos() { return pos; };
  
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

typedef G4THitsCollection<GammaRayTelCalorimeterHit> GammaRayTelCalorimeterHitsCollection;

extern G4Allocator<GammaRayTelCalorimeterHit> GammaRayTelCalorimeterHitAllocator;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

inline void* GammaRayTelCalorimeterHit::operator new(size_t)
{
  void* aHit;
  aHit = (void*) GammaRayTelCalorimeterHitAllocator.MallocSingle();
  return aHit;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

inline void GammaRayTelCalorimeterHit::operator delete(void* aHit)
{
  GammaRayTelCalorimeterHitAllocator.FreeSingle((GammaRayTelCalorimeterHit*) aHit);
}

#endif










