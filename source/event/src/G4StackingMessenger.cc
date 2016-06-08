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
// $Id: G4StackingMessenger.cc,v 1.4 2002/12/04 18:43:15 asaim Exp $
// GEANT4 tag $Name: geant4-05-00 $
//
// --------------------------------------------------------------------

#include "G4StackingMessenger.hh"
#include "G4StackManager.hh"
#include "G4UIdirectory.hh"
#include "G4UIcmdWithoutParameter.hh"
#include "G4UIcmdWithAnInteger.hh"
#include "G4ios.hh"

G4StackingMessenger::G4StackingMessenger(G4StackManager * fCont)
:fContainer(fCont)
{
  stackDir = new G4UIdirectory("/event/stack/");
  stackDir->SetGuidance("Stack control commands.");

  statusCmd = new G4UIcmdWithoutParameter("/event/stack/status",this);
  statusCmd->SetGuidance("List current status of the stack.");

  clearCmd = new G4UIcmdWithAnInteger("/event/stack/clear",this);
  clearCmd->SetGuidance("Clear stacked tracks.");
  clearCmd->SetGuidance(" 2 : clear all tracks in all stacks");
  clearCmd->SetGuidance(" 1 : clear tracks in the urgent and waiting stacks");
  clearCmd->SetGuidance(" 0 : clear tracks in the waiting stack (default)");
  clearCmd->SetGuidance("-1 : clear tracks in the urgent stack");
  clearCmd->SetGuidance("-2 : clear tracks in the postponed stack");
  clearCmd->SetParameterName("level",true);
  clearCmd->SetDefaultValue(0);
  clearCmd->SetRange("level>=-2&&level<=2");
  clearCmd->AvailableForStates(G4State_GeomClosed,G4State_EventProc);
}

G4StackingMessenger::~G4StackingMessenger()
{
  delete statusCmd;
  delete clearCmd;
  delete stackDir;
}

void G4StackingMessenger::SetNewValue(G4UIcommand * command,G4String newValues)
{
  if( command==statusCmd )
  {
    G4cout << "========================== Current status of the stack =====" << G4endl;
    G4cout << " Number of tracks in the stack" << G4endl;
    G4cout << "    Urgent stack    : " << fContainer->GetNUrgentTrack() << G4endl;
    G4cout << "    Waiting stack   : " << fContainer->GetNWaitingTrack() << G4endl;
    G4cout << "    Postponed stack : " << fContainer->GetNPostponedTrack() << G4endl;
  }
  if( command==clearCmd )
  {
    G4int vc = clearCmd->GetNewIntValue(newValues);
    switch (vc)
    { 
      case 2:
        fContainer->ClearPostponeStack();
      case 1:
        fContainer->ClearUrgentStack();
      case 0:
        fContainer->ClearWaitingStack();
        break;
      case -1:
        fContainer->ClearUrgentStack();
        break;
      case -2:
        fContainer->ClearPostponeStack();
        break;
    }
  }
}

