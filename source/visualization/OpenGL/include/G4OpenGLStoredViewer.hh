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
// $Id: G4OpenGLStoredViewer.hh,v 1.8 2001/08/14 18:03:15 johna Exp $
// GEANT4 tag $Name: geant4-05-00 $
//
// 
// Andrew Walkden  7th February 1997
// Class G4OpenGLStoredViewer : Encapsulates the `storedness' of
//                              an OpenGL viewer, for inheritance by
//                              derived (X, Xm...) classes.

#ifdef G4VIS_BUILD_OPENGL_DRIVER

#ifndef G4OPENGLSTOREDVIEWER_HH
#define G4OPENGLSTOREDVIEWER_HH

#include "G4VViewer.hh"
#include "G4OpenGLViewer.hh"
#include "G4OpenGLSceneHandler.hh"
#include "G4OpenGLStoredSceneHandler.hh"
#include "G4OpenGLTransform3D.hh"
#include "globals.hh"

class G4OpenGLStoredSceneHandler;

class G4OpenGLStoredViewer: virtual public G4OpenGLViewer {
  
public:
  G4OpenGLStoredViewer (G4OpenGLStoredSceneHandler& scene);
  virtual ~G4OpenGLStoredViewer ();
  
protected:
  void KernelVisitDecision ();
  G4bool CompareForKernelVisit(G4ViewParameters&);
  void DrawDisplayLists ();
  G4OpenGLStoredSceneHandler& fG4OpenGLStoredSceneHandler;
  G4ViewParameters fLastVP;  // Memory for making kernel visit decisions.
};

#endif

#endif
