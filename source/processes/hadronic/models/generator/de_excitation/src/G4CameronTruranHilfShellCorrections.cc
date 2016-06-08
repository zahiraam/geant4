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
// $Id: G4CameronTruranHilfShellCorrections.cc,v 1.7 2002/12/12 19:17:19 gunter Exp $
// GEANT4 tag $Name: geant4-05-00 $
//
// Hadronic Process: Nuclear De-excitations
// by V. Lara

#include "G4CameronTruranHilfShellCorrections.hh"


// Data comes from:
// J.W. Truran, A.G.W. Cameron, and E. Hilf, 
// Proc. Int. Conf. on the Properties of Nuclei Far From the Beta-Stability,
// Leysin, Switzerland, August 31 - September 4, 1970, Vol.1, p. 275
// S(Z)
const G4double G4CameronTruranHilfShellCorrections::ShellZTable
[G4CameronTruranHilfShellCorrections::ZTableSize] = { // 93 from Z = 10 to Z = 102
 2.349, 1.936, 1.596, 1.061, 0.341,-0.040, 0.565, 1.065, 1.536,
 1.972, 1.855, 2.043, 1.931, 1.652, 1.347, 0.973, 0.579, 0.159,
-0.487,-0.192, 0.443, 0.932, 1.387, 1.810, 1.969, 2.067, 2.064,
 1.825, 1.539, 1.251, 0.957, 1.128, 1.007, 0.603, 0.013,-0.635,
-1.258,-1.905,-2.562,-3.266,-4.099,-3.615,-3.171,-2.814,-2.337,
-1.778,-1.220,-0.694,-0.181, 0.323, 0.624, 0.841, 0.904, 0.906,
 0.930, 0.919, 0.934, 0.941, 0.978, 0.982, 1.083, 1.201, 1.281,
 1.189, 0.963, 0.781, 0.738, 0.696, 0.119,-0.619,-1.265,-1.898,
-2.431,-1.326,-0.268, 0.737, 1.451, 2.138, 2.307, 2.221, 2.041,
 1.827, 1.239, 0.747, 0.214,-0.263,-0.778,-1.272,-1.800,-2.302,
-2.846,-3.499,-3.042  
};
// S(N)
const G4double G4CameronTruranHilfShellCorrections::ShellNTable
[G4CameronTruranHilfShellCorrections::NTableSize] = { // 146 from N = 10 to N = 155
 2.439, 1.829, 1.419, 0.746,-0.082,-0.832,-0.960,-1.006,-1.045,
-1.114,-0.900,-0.081, 0.334, 0.064,-0.639,-1.363,-2.138,-2.987,
-4.042,-4.001,-3.582,-3.120,-2.677,-2.259,-1.778,-1.315,-0.944,
-0.599,-0.285,-0.020, 0.121, 0.140, 0.149,-0.001,-0.230,-0.604,
-1.010,-1.570,-2.466,-3.489,-4.552,-4.214,-3.375,-2.526,-1.725,
-0.923,-0.164, 0.601, 1.316, 1.947, 2.482, 2.971, 3.398, 3.737,
 3.979, 4.183, 4.374, 4.517, 4.605, 4.539, 4.375, 4.043, 3.672,
 3.250, 2.776, 2.254, 1.715, 1.151, 0.463,-0.237,-1.031,-1.850,
-2.722,-1.663,-0.724, 0.035, 0.786, 1.587, 2.145, 2.669, 2.680,
 2.488, 2.243, 1.969, 1.778, 1.663, 1.487, 1.325, 1.148, 0.962,
 0.843, 0.727, 0.574, 0.436, 0.320, 0.264, 0.397, 0.507, 0.405,
 0.346, 0.369, 0.397, 0.403, 0.379, 0.184,-0.226,-0.737,-1.305,
-1.950,-2.565,-3.126,-3.721,-4.393,-5.082,-5.921,-6.712,-6.853,
-5.592,-4.413,-3.333,-2.413,-1.582,-0.966,-0.421,-0.123, 0.228,
 0.543, 0.874, 1.059, 1.181, 1.186, 1.029, 1.029, 1.153, 1.227,
 1.330, 1.449, 1.596, 1.712, 1.851, 1.949, 2.044, 2.155, 2.307,
 2.621, 3.096
};

G4CameronTruranHilfShellCorrections* G4CameronTruranHilfShellCorrections::theInstance = 0;


G4CameronTruranHilfShellCorrections::G4CameronTruranHilfShellCorrections()
{;}

G4CameronTruranHilfShellCorrections* G4CameronTruranHilfShellCorrections::GetInstance() {
  if (!theInstance) theInstance = new G4CameronTruranHilfShellCorrections();
  return theInstance;
}
