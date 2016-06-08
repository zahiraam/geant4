// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4DistributionGenerator.hh,v 1.1.8.1.2.1 1999/12/07 20:52:32 gunter Exp $
// GEANT4 tag $Name: geant4-01-01 $
//
// -------------------------------------------------------------------
//      GEANT 4 class file --- Copyright CERN 1998
//      CERN Geneva Switzerland
//
//      For information related to this code contact:
//      CERN, IT Division, ASD group
//
//      File name:     G4DistributionGenerator.hh 
//
//      Author:        Maria Grazia Pia (pia@genova.infn.it)
// 
//      Creation date: 12 May 1998
//
//      Modifications: 
// -------------------------------------------------------------------

#ifndef G4DISTRIBUTIONGENERATOR_HH
#define G4DISTRIBUTIONGENERATOR_HH

#include "g4rw/tvordvec.h"

#include "globals.hh"
#include "Randomize.hh"

class G4DistributionGenerator
{  

public:

  // Constructor
  G4DistributionGenerator(G4RWTValOrderedVector<G4double>& x,
  			  G4RWTValOrderedVector<G4double>& values);
  G4DistributionGenerator();

  // Destructor
  ~G4DistributionGenerator();

  G4double Generate(G4double ranflat);

private:

  // Hide assignment operator as private 
  //  G4DistributionGenerator& operator=(const G4DistributionGenerator &right);

  // Copy constructor
  //  G4DistributionGenerator(const G4DistributionGenerator& );

  G4RWTValOrderedVector<G4double> _x;
  G4RWTValOrderedVector<G4double> _cumProb;

};
 
#endif