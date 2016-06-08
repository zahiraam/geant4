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
// $Id: G4CollisionNNToDeltaNstar.hh,v 1.6 2002/12/12 19:17:38 gunter Exp $ //

#ifndef G4CollisionNNToDeltaNstar_h
#define G4CollisionNNToDeltaNstar_h

#include "globals.hh"
#include "G4GeneralNNCollision.hh"
#include "G4VCrossSectionSource.hh"
#include "G4KineticTrackVector.hh"
#include "g4std/vector"

class G4KineticTrack;

class G4CollisionNNToDeltaNstar : public G4GeneralNNCollision
{

public:

  G4CollisionNNToDeltaNstar();

  virtual ~G4CollisionNNToDeltaNstar() {};
  virtual G4String GetName() const { return "NN -> Delta N* Collision"; }
  

protected:
  G4std::vector<G4String> result;
  virtual const G4std::vector<G4String>& GetListOfColliders(G4int whichOne) const
  {
    G4Exception("Tried to call G4CollisionNNToDeltaNstar::GetListOfColliders. Please find out why!");
    return result;
  } 

};

#endif
