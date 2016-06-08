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
// $Id: G3Pos.cc,v 1.8 2001/07/11 09:58:59 gunter Exp $
// GEANT4 tag $Name: geant4-05-00 $
//
// modified by I.Hrivnacova, 13.10.99

#include "globals.hh"
#include "G3Pos.hh"

G3Pos::G3Pos(G4String motherName, G4int C, G4ThreeVector* Position, G4int irot, 
	     G4String Only) 
  : _MotherName(motherName),
    _Copy(C), 
    _Position(Position), 
    _Irot(irot), 
    _Only(Only)
{
  if (_Only == "MANY") {
    // warning when MANY position is created
    G4String text = "G3Pos warning: Not supported MANY option has been encountered.\n";
    text = text +   "               It may cause overlapping volumes.";
    G4cerr << text << G4endl;
  }
}

G3Pos::~G3Pos(){;}

G4bool 
G3Pos::operator == ( const G3Pos& lv) const {
  return (this==&lv) ? true : false;
}

G4String&
G3Pos::GetMotherName() {
  return _MotherName;
}

G4int
G3Pos::GetIrot() {
  return _Irot;
}

G4int
G3Pos::GetCopy() {
  return _Copy;
}

G4ThreeVector* 
G3Pos::GetPos() {
  return _Position;
}

G4String&
G3Pos::GetOnly() {
  return _Only;
}
