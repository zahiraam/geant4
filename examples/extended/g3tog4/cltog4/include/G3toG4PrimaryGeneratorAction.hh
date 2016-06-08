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
// $Id: G3toG4PrimaryGeneratorAction.hh,v 1.2 2001/07/11 09:58:10 gunter Exp $
// GEANT4 tag $Name: geant4-05-00 $
//

#ifndef G3toG4PrimaryGeneratorAction_h
#define G3toG4PrimaryGeneratorAction_h 1

#include "G4Event.hh"
#include "G4ParticleGun.hh"
#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ThreeVector.hh"

class G3toG4PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
  public:
    G3toG4PrimaryGeneratorAction();
    ~G3toG4PrimaryGeneratorAction();

  public:
    void GeneratePrimaries(G4Event* anEvent);

  private:
    G4ParticleGun* particleGun;
    G4ThreeVector GetRandomDirection();
};

#endif


