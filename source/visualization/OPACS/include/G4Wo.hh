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
// $Id: G4Wo.hh,v 1.6 2001/07/11 10:08:47 gunter Exp $
// GEANT4 tag $Name: geant4-05-00 $
//
// 
// Guy Barrand 04 November 1996
// Wo graphics system factory.

#ifndef G4WO_HH
#define G4WO_HH

#if defined(G4VIS_BUILD_OPACS_DRIVER) || defined(G4VIS_USE_OPACS)

//G4
#include "G4VGraphicsSystem.hh"

class G4VInteractorManager;

class G4Wo: public G4VGraphicsSystem {
public:
  G4Wo ();
  virtual ~G4Wo ();
  G4VSceneHandler*    CreateSceneHandler (const G4String& name = "");
  G4VViewer*     CreateViewer  (G4VSceneHandler&, const G4String& name = "");
  static G4VInteractorManager* GetInteractorManager ();
};

#endif

#endif
