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
#ifndef G4DeltaDeltastarBuilder_h
#define G4DeltaDeltastarBuilder_h

#include "G4VXResonanceTable.hh"
#include "G4XDeltaDeltastarTable.hh"

class G4DeltaDeltastarBuilder : public G4VXResonanceTable
{
  public: 
  G4DeltaDeltastarBuilder(const G4String & aName, G4XDeltaDeltastarTable & aT)
      : theT(aT), theS(aName)
  {}
  virtual G4PhysicsVector* CrossSectionTable() const
  {
    return const_cast<G4PhysicsVector*>(theT.CrossSectionTable(theS));
  }
  
  private:
  
  G4XDeltaDeltastarTable & theT;
  G4String theS;
};
#endif
