// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4eEnergyLossPlus.hh,v 1.4.4.1 1999/12/07 20:50:53 gunter Exp $
// GEANT4 tag $Name: geant4-01-01 $
//
// $Id: 
// ------------------------------------------------------------
//      GEANT 4 class header file 
//
//      For information related to this code contact:
//      CERN, IT Division, ASD group
//      History: first implementation, based on object model of
//      2nd December 1995, G.Cosmo
//      ---------- G4eEnergyLossPlus physics process -----------
//                by Laszlo Urban, 20 March 1997 
// 18/11/98  , L. Urban
//  It is a modified version of G4eEnergyLoss:
//  continuous energy loss with generation of subcutoff delta rays
// 02/02/99  new data members ,  L.Urban 
// ---------------------------------------------------------------
 
#ifndef G4eEnergyLossPlus_h
#define G4eEnergyLossPlus_h 1
 
#include "G4ios.hh"
#include "globals.hh"
#include "Randomize.hh"
#include "G4VContinuousDiscreteProcess.hh"
#include "G4Material.hh"
#include "G4Element.hh"
#include "G4VParticleChange.hh"
#include "globals.hh"
#include "G4Track.hh"
#include "G4Step.hh"
#include "G4Electron.hh"
#include "G4Positron.hh"
#include "G4PhysicsLogVector.hh"
#include "G4PhysicsLinearVector.hh"
#include "G4EnergyLossTables.hh"

class G4EnergyLossMessenger;
 
// Class description:
// This class is the implementation of the unified Energy Loss process
// with generation of subcutoff secondaries , see description of 
// *****************************************
//  the AlongStepDoIt method.
// It calculates the continuous energy loss for e+/e-.
// The following processes give contributions to the continuous
// energy loss (by default) :
//  ---	 ionisation (= cont.ion.loss + delta ray production)
//  --- bremsstrahlung (= cont.loss due to soft brems+discrete bremsstrahlung)
//   more can be added	 ..........
// This class creates static dE/dx and range tables for e+ and e-,
// which tables can be used by other processes , too.
// G4eEnergyLoss is the base class for the processes giving contribution
// to the (continuous) energy loss of e+/e- .
// Class description - end

 
class G4eEnergyLossPlus : public G4VContinuousDiscreteProcess
 
{
  public:
 
    G4eEnergyLossPlus(const G4String& );

   ~G4eEnergyLossPlus();

  public: // With description

    G4bool IsApplicable(const G4ParticleDefinition&);
    //	true for e+/e- , false otherwise

    void BuildDEDXTable(const G4ParticleDefinition& aParticleType);
    //	It builds dE/dx and range tables for aParticleType and
    //	for every material contained in the materialtable.

    G4double GetContinuousStepLimit(const G4Track& track,
                                    G4double previousStepSize,
                                    G4double currentMinimumStep,
                                    G4double& currentSafety);
    // Computes the steplimit due to the energy loss process.

    G4VParticleChange* AlongStepDoIt(const G4Track& track,
                                     const G4Step& Step) ;
    // --- Performs the computation of the mean energy loss
    //     after the step .
    // --- Compares the value of the safety to the value
    //     of the cut in range.
    // --- If safety < cut in range , generates secondaries
    //     with kinetic energy in the interval [Tsafety,Tcut],
    //     where  Tsafety corresponds to range safety,
    //            Tcut is the cut in energy.
    // --- Updates the value of the mean energy loss and
    //     the direction of the primary
    // --- Computes the energy loss fluctuation.   

    virtual G4double GetMeanFreePath(const G4Track& track,
                                     G4double previousStepSize,
                                     G4ForceCondition* condition) = 0;
    // Virtual function to be overridden in the derived classes
    // ( ionisation and bremsstrahlung) .

    virtual G4VParticleChange* PostStepDoIt(const G4Track& track,
                                            const G4Step& Step) = 0;
    // Virtual function to be overridden in the derived classes
    // ( ionisation and bremsstrahlung) .
                                            
                                            
  private:

    void BuildRangeTable(const G4ParticleDefinition& aParticleType);

    void BuildInverseRangeTable(const G4ParticleDefinition& aParticleType);

    void BuildTimeTables(const G4ParticleDefinition& aParticleType);

    void BuildRangeVector(G4int materialIndex,
                          G4PhysicsLogVector* rangeVector);

    void BuildLabTimeVector(G4int materialIndex,
                          G4PhysicsLogVector* rangeVector);

    void BuildProperTimeVector(G4int materialIndex,
                          G4PhysicsLogVector* rangeVector);

    void InvertRangeVector(G4int materialIndex,
                          G4PhysicsLogVector* rangeVector);

    G4double RangeIntLin(G4PhysicsVector* physicsVector,G4int nbin);

    G4double RangeIntLog(G4PhysicsVector* physicsVector,G4int nbin);
    G4double LabTimeIntLog(G4PhysicsVector* physicsVector,G4int nbin);
    G4double ProperTimeIntLog(G4PhysicsVector* physicsVector,G4int nbin);

    void BuildRangeCoeffATable(const G4ParticleDefinition& aParticleType);
    void BuildRangeCoeffBTable(const G4ParticleDefinition& aParticleType);
    void BuildRangeCoeffCTable(const G4ParticleDefinition& aParticleType);
    
    G4double GetConstraints(const G4DynamicParticle* aParticle,
                            G4Material* aMaterial); 
                                                                  
    G4double GetLossWithFluct(const G4DynamicParticle* aParticle,
                              G4Material* aMaterial,
                              G4double   threshold);

    // hide  assignment operator
    G4eEnergyLossPlus (G4eEnergyLossPlus &); 
    G4eEnergyLossPlus & operator=(const G4eEnergyLossPlus &right);

  protected:

    G4PhysicsTable* theLossTable;
     
    G4double ParticleMass;               // heavily used

    G4double MinKineticEnergy ;           //

    G4double Charge,lastCharge ;

    G4PhysicsTable* theDEDXTable;
    G4PhysicsTable* theRangeTable;

    G4PhysicsTable* theRangeCoeffATable;
    G4PhysicsTable* theRangeCoeffBTable;
    G4PhysicsTable* theRangeCoeffCTable;

  private:

    G4PhysicsTable* theInverseRangeTable;

    G4PhysicsTable* theLabTimeTable ;
    G4PhysicsTable* theProperTimeTable ;
  
    G4int            CounterOfProcess;
    G4PhysicsTable** RecorderOfProcess;
                                            
    G4double fdEdx;                       // computed in GetConstraints
    G4double fRangeNow;                   // computed in GetConstraints

    G4double linLossLimit ;               //

    G4int TotBin;                         // number of bins in table, 
                                          // calculated in BuildPhysicTable
    G4double LowestKineticEnergy;
    G4double HighestKineticEnergy;
    G4double RTable,LOGRTable;           // LOGRTable=log(HighestKineticEnergy-
                                         // LowestKineticEnergy)/TotBin
                                         // RTable = exp(LOGRTable)

    G4double c1N,c2N ;                   // coeffs to compute nb of deltas
    G4int Ndeltamax ;                    // upper limit for nb of subcutoff
                                         // delta rays in one step
    // variables for the integration routines
    G4double taulow,tauhigh,ltaulow,ltauhigh;
    
    // data members to speed up the fluctuation calculation
    G4Material* lastMaterial;
    G4int imat;
    G4double f1Fluct,f2Fluct,e1Fluct,e2Fluct,rateFluct,ipotFluct;
    G4double e1LogFluct,e2LogFluct,ipotLogFluct;
    const G4double MaxExcitationNumber ;
    const G4double probLimFluct ;
    const long nmaxDirectFluct,nmaxCont1,nmaxCont2 ;
    
 //  
 // static part of the class
 //
 
 protected:
 
    //basic DEDX and Range tables
    static G4PhysicsTable* theDEDXElectronTable ;
    static G4PhysicsTable* theDEDXPositronTable ;
    static G4PhysicsTable* theRangeElectronTable ;
    static G4PhysicsTable* theRangePositronTable ;

    //inverse tables of the range tables
    static G4PhysicsTable* theInverseRangeElectronTable;
    static G4PhysicsTable* theInverseRangePositronTable;
   
    // lab and proper time tables
    static G4PhysicsTable* theLabTimeElectronTable ;
    static G4PhysicsTable* theLabTimePositronTable ;
    static G4PhysicsTable* theProperTimeElectronTable ;
    static G4PhysicsTable* theProperTimePositronTable ;

    //processes inherited from G4eEnergyLossPlus 
    //register themselves  in the static array Recorder
    //for electrons/positrons separately
    //nb of contributing processes = NbOfProcesses
    static G4int NbOfProcesses;
    static G4int CounterOfElectronProcess;
    static G4int CounterOfPositronProcess ;          
    static G4PhysicsTable** RecorderOfElectronProcess;
    static G4PhysicsTable** RecorderOfPositronProcess;
    
    static G4double MinDeltaCutInRange; // minimum cut for delta rays
    static G4double* MinDeltaEnergy ;  

  private:
     
    //for interpolation within the tables
    static G4PhysicsTable* theeRangeCoeffATable;
    static G4PhysicsTable* theeRangeCoeffBTable;
    static G4PhysicsTable* theeRangeCoeffCTable;
    static G4PhysicsTable* thepRangeCoeffATable;
    static G4PhysicsTable* thepRangeCoeffBTable;
    static G4PhysicsTable* thepRangeCoeffCTable;
    
    static G4double dRoverRange;     // dRoverRange is the maximum allowed
                                     // deltarange/range in one Step 
    static G4double finalRange;      // final step before stopping
    static G4double c1lim,c2lim,c3lim ; // coeffs for computing steplimit
    
    static G4bool   rndmStepFlag;    // control the randomization of the step
    static G4bool   EnlossFlucFlag;  // control the energy loss fluctuation

    static G4EnergyLossMessenger* eLossMessenger;
         
  public: // With description
     
    static void  SetNbOfProcesses(G4int nb) {NbOfProcesses=nb;};
    // Sets number of processes giving contribution to the energy loss

    static void  PlusNbOfProcesses()        {NbOfProcesses++ ;};
    // Increases number of processes giving contribution to the energy loss

    static void  MinusNbOfProcesses()       {NbOfProcesses-- ;};                                      
    // Decreases number of processes giving contribution to the energy loss

    static G4int GetNbOfProcesses()         {return NbOfProcesses;};
    // Gets number of processes giving contribution to the energy loss
    // ( default value = 2)

    static void SetRndmStep     (G4bool   value) {rndmStepFlag   = value;}
    // use / do not use randomisation in energy loss steplimit
    // ( default = no randomisation)

    static void SetEnlossFluc   (G4bool   value) {EnlossFlucFlag = value;}
    // compute energy loss with/without fluctuation
    // ( default : with fluctuation)

    static void SetStepFunction (G4double c1, G4double c2)
                               {dRoverRange = c1; finalRange = c2;
                                c1lim=dRoverRange ;
                                c2lim=2.*(1-dRoverRange)*finalRange;
                                c3lim=-(1.-dRoverRange)*finalRange*finalRange;
                               }
    // sets values for data members used to compute the step limit:
    //	 dRoverRange : max. relative range change in one step,
    //	 finalRange  : if range <= finalRange --> last step for the particle.
 

    static void SetMinDeltaCutInRange(G4double value)
                                    {MinDeltaCutInRange = value;}
    // sets minimal cut value for the subcutoff secondaries
    // (i.e. the kinetic energy of these secondaries can not be
    //  smaller than the energy corresponds to MinDeltaCutInRange).
};
 
#include "G4eEnergyLossPlus.icc"

#endif
 