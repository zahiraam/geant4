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
// $Id: AnaEx01SteppingAction.cc,v 1.5 2001/11/16 14:31:13 barrand Exp $
// GEANT4 tag $Name: geant4-05-00 $
//
// 

#ifdef G4ANALYSIS_USE
#include "AnaEx01AnalysisManager.hh"
#endif

#include "AnaEx01SteppingAction.hh"

AnaEx01SteppingAction::AnaEx01SteppingAction(
 AnaEx01AnalysisManager* aAnalysisManager
):fAnalysisManager(aAnalysisManager){}

AnaEx01SteppingAction::~AnaEx01SteppingAction(){}
void AnaEx01SteppingAction::UserSteppingAction(const G4Step* aStep){
#ifdef G4ANALYSIS_USE
  if(fAnalysisManager) fAnalysisManager->Step(aStep);
#endif
}



