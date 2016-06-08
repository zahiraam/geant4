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
// $Id: CadDetectorMessenger.hh,v 1.1 2002/06/20 10:00:54 gcosmo Exp $
// GEANT4 tag $Name: geant4-05-00 $
// ------------------------------------------------------------

#ifndef CadDetectorMessenger_h
#define CadDetectorMessenger_h 1

#include "globals.hh"
#include "G4UImessenger.hh"

class CadDetectorConstruction;
class G4UIdirectory;
class G4UIcmdWithAString;

class CadDetectorMessenger: public G4UImessenger
{
  public:
    CadDetectorMessenger(CadDetectorConstruction * myDC);
    void SetNewValue(G4UIcommand * command,G4String newValues);
  private:
    CadDetectorConstruction * myDetector;
    G4UIdirectory *      mydetDir;
    G4UIcmdWithAString * selDetCmd;
    G4UIcmdWithAString * switchCmd;
    G4UIcmdWithAString * selMatCmd;

};

#endif

