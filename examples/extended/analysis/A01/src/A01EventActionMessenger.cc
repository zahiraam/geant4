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
// $Id: A01EventActionMessenger.cc,v 1.3 2002/12/13 11:34:34 gunter Exp $
// --------------------------------------------------------------
//
#include "A01EventActionMessenger.hh"
#include "A01EventAction.hh"
#include "G4UIcmdWithAnInteger.hh"
#include "G4ios.hh"

A01EventActionMessenger::A01EventActionMessenger(A01EventAction * mpga)
:target(mpga)
{
  verboseCmd = new G4UIcmdWithAnInteger("/mydet/verbose",this);
  verboseCmd->SetGuidance("Verbose level for each event.");
  verboseCmd->SetGuidance(" Event summary will be displayed for every 'level' events.");
  verboseCmd->SetParameterName("level",true);
  verboseCmd->SetRange("level>=0");
  verboseCmd->SetDefaultValue(1);
}

A01EventActionMessenger::~A01EventActionMessenger()
{
  delete verboseCmd;
}

void A01EventActionMessenger::SetNewValue(G4UIcommand * command,G4String newValue)
{
  if( command==verboseCmd )
  { target->SetVerbose(verboseCmd->GetNewIntValue(newValue)); }
}

G4String A01EventActionMessenger::GetCurrentValue(G4UIcommand * command)
{
  G4String cv;
  if( command==verboseCmd )
  { cv = verboseCmd->ConvertToString(target->GetVerbose()); }

  return cv;
}

