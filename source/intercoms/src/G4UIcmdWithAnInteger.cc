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
// $Id: G4UIcmdWithAnInteger.cc,v 1.4 2002/04/26 22:03:35 asaim Exp $
// GEANT4 tag $Name: geant4-05-00 $
//
//

#include "G4UIcmdWithAnInteger.hh"
#include "g4std/strstream"

G4UIcmdWithAnInteger::G4UIcmdWithAnInteger
(const char * theCommandPath,G4UImessenger * theMessenger)
:G4UIcommand(theCommandPath,theMessenger)
{
  G4UIparameter * intParam = new G4UIparameter('i');
  SetParameter(intParam);
}

G4int G4UIcmdWithAnInteger::GetNewIntValue(const char* paramString)
{
  G4int vl;
  G4std::istrstream is((char*)paramString);
  is >> vl;
  return vl;
}

G4String G4UIcmdWithAnInteger::ConvertToString(G4int intValue)
{
  char st[20];
  G4std::ostrstream os(st,20);
  os << intValue << '\0';
  G4String vl = st;
  return vl;
}

void G4UIcmdWithAnInteger::SetParameterName
(const char * theName,G4bool omittable,G4bool currentAsDefault)
{
  G4UIparameter * theParam = GetParameter(0);
  theParam->SetParameterName(theName);
  theParam->SetOmittable(omittable);
  theParam->SetCurrentAsDefault(currentAsDefault);
}

void G4UIcmdWithAnInteger::SetDefaultValue(G4int defVal)
{
  G4UIparameter * theParam = GetParameter(0);
  theParam->SetDefaultValue(defVal);
}

