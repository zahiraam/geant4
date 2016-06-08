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
// $Id: G4ImportanceAlgorithm.hh,v 1.6 2002/10/14 12:36:00 dressel Exp $
// GEANT4 tag $Name: geant4-05-00 $
//
// ----------------------------------------------------------------------
// Class G4ImportanceAlgorithm
//
// Class description:
//
// An implementation of a G4VImportanceAlgorithm (see description in
// G4VImportanceAlgorithm.hh).

// Author: Michael Dressel (Michael.Dressel@cern.ch)
// ----------------------------------------------------------------------
#ifndef G4ImportanceAlgorithm_hh
#define G4ImportanceAlgorithm_hh G4ImportanceAlgorithm_hh

#include "G4VImportanceAlgorithm.hh"

class G4ImportanceAlgorithm : public G4VImportanceAlgorithm
{

public:  // with description

  G4ImportanceAlgorithm();
    // simple construction

  virtual ~G4ImportanceAlgorithm();
    // repeate warning if triggered

  virtual G4Nsplit_Weight Calculate(G4double ipre, 
				    G4double ipost, 
				    G4double init_w) const;
    // calculate the number of tracks and their weight according 
    // to the pre and post importance value and the weight of
    // the mother track.  
private:

  void Error(const G4String &m) const;
  void Warning(const G4String &m) const;

private:

  mutable G4bool fWorned;
};

#endif
