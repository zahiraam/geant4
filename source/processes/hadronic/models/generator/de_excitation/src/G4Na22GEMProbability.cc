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
// $Id: G4Na22GEMProbability.cc,v 1.1 2002/06/06 18:02:23 larazb Exp $
// GEANT4 tag $Name: geant4-05-00 $
//
// Hadronic Process: Nuclear De-excitations
// by V. Lara (Nov 1999)
//


#include "G4Na22GEMProbability.hh"

G4Na22GEMProbability::G4Na22GEMProbability() :
  G4GEMProbability(22,11,3.0) // A,Z,Spin
{

    ExcitEnergies.push_back(583.03*keV);
    ExcitSpins.push_back(1.0);
    ExcitLifetimes.push_back(244.0e-3*picosecond);

    ExcitEnergies.push_back(657.0*keV);
    ExcitSpins.push_back(0.0);
    ExcitLifetimes.push_back(14.0*picosecond);

    ExcitEnergies.push_back(890.89*keV);
    ExcitSpins.push_back(4.0);
    ExcitLifetimes.push_back(10.4*picosecond);

    ExcitEnergies.push_back(1528.06*keV);
    ExcitSpins.push_back(5.0);
    ExcitLifetimes.push_back(3.40*picosecond);

    ExcitEnergies.push_back(1936.9*keV);
    ExcitSpins.push_back(1.0);
    ExcitLifetimes.push_back(3.0e-3*picosecond);

    ExcitEnergies.push_back(1951.8*keV);
    ExcitSpins.push_back(2.0);
    ExcitLifetimes.push_back(6.0e-3*picosecond);

    ExcitEnergies.push_back(1983.8*keV);
    ExcitSpins.push_back(3.0);
    ExcitLifetimes.push_back(1.59*picosecond);

    ExcitEnergies.push_back(2211.5*keV);
    ExcitSpins.push_back(1.0);
    ExcitLifetimes.push_back(14.9*picosecond);

    ExcitEnergies.push_back(2571.5*keV);
    ExcitSpins.push_back(2.0);
    ExcitLifetimes.push_back(5.6*picosecond);

    ExcitEnergies.push_back(2968.7*keV);
    ExcitSpins.push_back(3.0);
    ExcitLifetimes.push_back(42.0e-3*picosecond);

    ExcitEnergies.push_back(3059.6*keV);
    ExcitSpins.push_back(2.0);
    ExcitLifetimes.push_back(28.0e-3*picosecond);

    ExcitEnergies.push_back(3519.2*keV);
    ExcitSpins.push_back(3.0);
    ExcitLifetimes.push_back(464.0e-3*picosecond);

    ExcitEnergies.push_back(3706.6*keV);
    ExcitSpins.push_back(6.0);
    ExcitLifetimes.push_back(76.0e-3*picosecond);

    ExcitEnergies.push_back(3943.5*keV);
    ExcitSpins.push_back(1.0);
    ExcitLifetimes.push_back(6.0e-3*picosecond);

    ExcitEnergies.push_back(4071.3*keV);
    ExcitSpins.push_back(4.0);
    ExcitLifetimes.push_back(3.0e-3*picosecond);

    ExcitEnergies.push_back(4296.1*keV);
    ExcitSpins.push_back(0.0);
    ExcitLifetimes.push_back(3.5*picosecond);

    ExcitEnergies.push_back(4319.0*keV);
    ExcitSpins.push_back(1.0);
    ExcitLifetimes.push_back(30.0e-3*picosecond);

    ExcitEnergies.push_back(4360.0*keV);
    ExcitSpins.push_back(2.0);
    ExcitLifetimes.push_back(11.0e-3*picosecond);

    ExcitEnergies.push_back(4468.3*keV);
    ExcitSpins.push_back(4.0);
    ExcitLifetimes.push_back(104.0e-3*picosecond);

    ExcitEnergies.push_back(4523.8*keV);
    ExcitSpins.push_back(7.0);
    ExcitLifetimes.push_back(69.0e-3*picosecond);

    ExcitEnergies.push_back(4582.8*keV);
    ExcitSpins.push_back(2.0);
    ExcitLifetimes.push_back(69.0e-3*picosecond);

    ExcitEnergies.push_back(4621.7*keV);
    ExcitSpins.push_back(1.0);
    ExcitLifetimes.push_back(69.0e-3*picosecond);

    ExcitEnergies.push_back(4710.0*keV);
    ExcitSpins.push_back(5.0);
    ExcitLifetimes.push_back(42.0e-3*picosecond);

    ExcitEnergies.push_back(4771.0*keV);
    ExcitSpins.push_back(3.0);
    ExcitLifetimes.push_back(69.0*picosecond);

    ExcitEnergies.push_back(5062.4*keV);
    ExcitSpins.push_back(2.0);
    ExcitLifetimes.push_back(14.0e-3*picosecond);

    ExcitEnergies.push_back(5100.6*keV);
    ExcitSpins.push_back(4.0);
    ExcitLifetimes.push_back(38.0e-3*picosecond);

    ExcitEnergies.push_back(5167.0*keV);
    ExcitSpins.push_back(1.0);
    ExcitLifetimes.push_back(69.0*picosecond);


    ExcitEnergies.push_back(7153.0*keV);
    ExcitSpins.push_back(3.0);
    ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(0.5*keV));
    
    ExcitEnergies.push_back(7221.0*keV);
    ExcitSpins.push_back(2.0);
    ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(0.4*keV));
    
    ExcitEnergies.push_back(7241.0*keV);
    ExcitSpins.push_back(2.0);
    ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(0.3*keV));
    
    ExcitEnergies.push_back(7279.0*keV);
    ExcitSpins.push_back(1.0);
    ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(0.5*keV));
    
    ExcitEnergies.push_back(7280.0*keV);
    ExcitSpins.push_back(4.0);
    ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(1.5*keV));
    
    ExcitEnergies.push_back(7361.0*keV);
    ExcitSpins.push_back(3.0);
    ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(1.0*keV));
    
    ExcitEnergies.push_back(7373.0*keV);
    ExcitSpins.push_back(2.0);
    ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(0.5*keV));
    
    ExcitEnergies.push_back(7379.2*keV);
    ExcitSpins.push_back(2.0);
    ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(0.5*keV));
    
    ExcitEnergies.push_back(7402.0*keV);
    ExcitSpins.push_back(1.0);
    ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(1.5*keV));
    
    ExcitEnergies.push_back(7409.6*keV);
    ExcitSpins.push_back(1.0);
    ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(3.5*keV));
    
    ExcitEnergies.push_back(7472.6*keV);
    ExcitSpins.push_back(2.0);
    ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(3.5*keV));
    
    ExcitEnergies.push_back(7516.2*keV);
    ExcitSpins.push_back(3.0);
    ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(0.5*keV));
    
    ExcitEnergies.push_back(7547.9*keV);
    ExcitSpins.push_back(2.0);
    ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(0.6*keV));
    
    ExcitEnergies.push_back(7574.4*keV);
    ExcitSpins.push_back(5.0);
    ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(0.5*keV));
    
    ExcitEnergies.push_back(7600.0*keV);
    ExcitSpins.push_back(2.0);
    ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(1.9*keV));
    
    ExcitEnergies.push_back(7606.0*keV);
    ExcitSpins.push_back(1.0);
    ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(0.6*keV));
    
    ExcitEnergies.push_back(7637.0*keV);
    ExcitSpins.push_back(2.0);
    ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(0.5*keV));
    
    ExcitEnergies.push_back(7684.0*keV);
    ExcitSpins.push_back(2.0);
    ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(0.5*keV));
    
    ExcitEnergies.push_back(7779.0*keV);
    ExcitSpins.push_back(1.0);
    ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(2.8*keV));
    
    ExcitEnergies.push_back(7801.5*keV);
    ExcitSpins.push_back(1.0);
    ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(2.4*keV));
    
    ExcitEnergies.push_back(7821.9*keV);
    ExcitSpins.push_back(1.0);
    ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(0.5*keV));
    
    ExcitEnergies.push_back(7890.0*keV);
    ExcitSpins.push_back(3.0);
    ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(0.5*keV));
    
    ExcitEnergies.push_back(7920.0*keV);
    ExcitSpins.push_back(2.0);
    ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(17.0*keV));
    
    ExcitEnergies.push_back(7978.0*keV);
    ExcitSpins.push_back(1.0);
    ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(10.0*keV));
    
    ExcitEnergies.push_back(8019.0*keV);
    ExcitSpins.push_back(4.0);
    ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(1.0*keV));
    
    ExcitEnergies.push_back(8041.0*keV);
    ExcitSpins.push_back(2.0);
    ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(0.5*keV));
    
    ExcitEnergies.push_back(8102.0*keV);
    ExcitSpins.push_back(1.0);
    ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(3.8*keV));
    
    ExcitEnergies.push_back(8108.0*keV);
    ExcitSpins.push_back(3.0);
    ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(1.5*keV));
    
    ExcitEnergies.push_back(8115.0*keV);
    ExcitSpins.push_back(3.0);
    ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(3.1*keV));
    
    ExcitEnergies.push_back(8166.0*keV);
    ExcitSpins.push_back(3.0);
    ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(22.5*keV));
    
    ExcitEnergies.push_back(8198.0*keV);
    ExcitSpins.push_back(2.0);
    ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(0.6*keV));
    
    ExcitEnergies.push_back(8212.0*keV);
    ExcitSpins.push_back(1.0);
    ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(5.1*keV));
    
    ExcitEnergies.push_back(8234.0*keV);
    ExcitSpins.push_back(1.0);
    ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(11.0*keV));
    
    ExcitEnergies.push_back(8288.0*keV);
    ExcitSpins.push_back(0.0);
    ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(4.5*keV));
    
    ExcitEnergies.push_back(8329.0*keV);
    ExcitSpins.push_back(0.0);
    ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(2.7*keV));
    
    ExcitEnergies.push_back(8436.0*keV);
    ExcitSpins.push_back(0.0);
    ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(5.4*keV));
    
    ExcitEnergies.push_back(8497.0*keV);
    ExcitSpins.push_back(1.0);
    ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(44.0*keV));
    
    ExcitEnergies.push_back(8538.0*keV);
    ExcitSpins.push_back(0.0);
    ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(13.2*keV));
    
    ExcitEnergies.push_back(8602.0*keV);
    ExcitSpins.push_back(0.0);
    ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(11.2*keV));
    
    ExcitEnergies.push_back(8637.0*keV);
    ExcitSpins.push_back(0.0);
    ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(11.0*keV));
    
}


G4Na22GEMProbability::G4Na22GEMProbability(const G4Na22GEMProbability &right)
{
  G4Exception("G4Na22GEMProbability::copy_constructor meant to not be accessable");
}




const G4Na22GEMProbability & G4Na22GEMProbability::
operator=(const G4Na22GEMProbability &right)
{
  G4Exception("G4Na22GEMProbability::operator= meant to not be accessable");
  return *this;
}


G4bool G4Na22GEMProbability::operator==(const G4Na22GEMProbability &right) const
{
  return false;
}

G4bool G4Na22GEMProbability::operator!=(const G4Na22GEMProbability &right) const
{
  return true;
}



