#!/bin/csh -f
set file = $1
set tmpfile = $1.tmp.$$
if ( ! -f $file ) then
  echo "File $file does not exist.  Stop."
  exit 1
endif

cat $file | sed \
-e 's/DCIOcatalog/G4DCIOcatalog/g' \
-e 's/DCIOentryT/G4DCIOentryT/g' \
-e 's/FADSevent/G4Pevent/g' \
-e 's/FileUtilities/G4FileUtilities/g' \
-e 's/HCIOcatalog/G4HCIOcatalog/g' \
-e 's/HCIOentryT/G4HCIOentryT/g' \
-e 's/PersistencyCenter/G4PersistencyCenter/g' \
-e 's/PersistencyCenterMessenger/G4PersistencyCenterMessenger/g' \
-e 's/PersistencyManager/G4PersistencyManager/g' \
-e 's/PersistencyManagerT/G4PersistencyManagerT/g' \
-e 's/VDCIOentry/G4VDCIOentry/g' \
-e 's/VHCIOentry/G4VHCIOentry/g' \
-e 's/VHepMCIO/G4VHepMCIO/g' \
-e 's/VMCTruthIO/G4VMCTruthIO/g' \
-e 's/VPDigitIO/G4VPDigitIO/g' \
-e 's/VPDigitsCollectionIO/G4VPDigitsCollectionIO/g' \
-e 's/VPEventIO/G4VPEventIO/g' \
-e 's/VPHitIO/G4VPHitIO/g' \
-e 's/VPHitsCollectionIO/G4VPHitsCollectionIO/g' \
-e 's/VTransactionManager/G4VTransactionManager/g' \
  -e 's/MCTEvent/G4MCTEvent/g' \
  -e 's/MCTEventAction/G4MCTEventAction/g' \
  -e 's/MCTGenEvent/G4MCTGenEvent/g' \
  -e 's/MCTGenParticle/G4MCTGenParticle/g' \
  -e 's/MCTManager/G4MCTManager/g' \
  -e 's/MCTMessenger/G4MCTMessenger/g' \
  -e 's/MCTSimEvent/G4MCTSimEvent/g' \
  -e 's/MCTSimParticle/G4MCTSimParticle/g' \
  -e 's/MCTSimVertex/G4MCTSimVertex/g' \
  -e 's/MCTSteppingAction/G4MCTSteppingAction/g' \
  -e 's/MCTVStoreSelection/G4MCTVStoreSelection/g' \
  -e 's/MCTVUserFilter/G4MCTVUserFilter/g' \
-e 's/G4G4/G4/g' \
-e 's/G4VG4/G4V/g' \
-e 's/GetG4/Get/g' \
-e 's/CurrentG4/Current/g' \
-e 's/SetG4PersistencyManager/SetPersistencyManager/g' \
-e 's/RegisterG4PersistencyManager/RegisterPersistencyManager/g' \
-e 's/DeleteG4PersistencyManager/DeletePersistencyManager/g' \
-e 's/FADS\/Goofy tag/GEANT4 tag/g' \
  > $tmpfile

diff $file $tmpfile

mv -f $file ${file}.org
mv -f $tmpfile $file

