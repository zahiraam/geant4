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
// $Id: G4MesonConstructor.cc,v 1.4 2001/07/11 10:01:50 gunter Exp $
// GEANT4 tag $Name: geant4-05-00 $
//
// 
// --------------------------------------------------------------
//	GEANT 4 class implementation file 
//

#include "G4MesonConstructor.hh"

#include "G4ParticleDefinition.hh"
#include "G4ParticleTable.hh"
// Mesons
#include "G4PionPlus.hh"
#include "G4PionMinus.hh"
#include "G4PionZero.hh"
#include "G4Eta.hh"
#include "G4EtaPrime.hh"

#include "G4KaonPlus.hh"
#include "G4KaonMinus.hh"
#include "G4KaonZero.hh"
#include "G4AntiKaonZero.hh"
#include "G4KaonZeroLong.hh"
#include "G4KaonZeroShort.hh"

#include "G4DMesonPlus.hh"
#include "G4DMesonMinus.hh"
#include "G4DMesonZero.hh"
#include "G4AntiDMesonZero.hh"
#include "G4DsMesonPlus.hh"
#include "G4DsMesonMinus.hh"
#include "G4JPsi.hh"

#include "G4BMesonPlus.hh"
#include "G4BMesonMinus.hh"
#include "G4BMesonZero.hh"
#include "G4AntiBMesonZero.hh"
#include "G4BsMesonZero.hh"
#include "G4AntiBsMesonZero.hh"

G4MesonConstructor::G4MesonConstructor()
{
}

G4MesonConstructor::~G4MesonConstructor()
{
}


void G4MesonConstructor::ConstructParticle()
{
  ConstructLightMesons();
  ConstructCharmMesons();
  ConstructBottomMesons();
}

void G4MesonConstructor::ConstructLightMesons()
{
  G4PionPlus::PionPlusDefinition();
  G4PionMinus::PionMinusDefinition();
  G4PionZero::PionZeroDefinition();
  G4Eta::EtaDefinition();
  G4EtaPrime::EtaPrimeDefinition();
  G4KaonPlus::KaonPlusDefinition();
  G4KaonMinus::KaonMinusDefinition();
  G4KaonZero::KaonZeroDefinition();
  G4AntiKaonZero::AntiKaonZeroDefinition();
  G4KaonZeroLong::KaonZeroLongDefinition();
  G4KaonZeroShort::KaonZeroShortDefinition();
}
void G4MesonConstructor::ConstructCharmMesons()
{
  G4DMesonPlus::DMesonPlusDefinition();
  G4DMesonMinus::DMesonMinusDefinition();
  G4DMesonZero::DMesonZeroDefinition();
  G4AntiDMesonZero::AntiDMesonZeroDefinition();
  G4DsMesonPlus::DsMesonPlusDefinition();
  G4DsMesonMinus::DsMesonMinusDefinition();
  G4JPsi::JPsiDefinition();
}
void G4MesonConstructor::ConstructBottomMesons()
{
  G4BMesonPlus::BMesonPlusDefinition();
  G4BMesonMinus::BMesonMinusDefinition();
  G4BMesonZero::BMesonZeroDefinition();
  G4AntiBMesonZero::AntiBMesonZeroDefinition();
  G4BsMesonZero::BsMesonZeroDefinition();
  G4AntiBsMesonZero::AntiBsMesonZeroDefinition();
}
