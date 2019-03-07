# echo "setup TrigMinBiasMonitoring TrigMinBiasMonitoring-00-01-15 in /afs/cern.ch/work/m/mizhou/QF1/Trigger/TrigMonitoring"

if ( $?CMTROOT == 0 ) then
  setenv CMTROOT /cvmfs/atlas.cern.ch/repo/sw/software/x86_64-slc6-gcc48-opt/20.1.0/CMT/v1r25p20140131
endif
source ${CMTROOT}/mgr/setup.csh
set cmtTrigMinBiasMonitoringtempfile=`${CMTROOT}/${CMTBIN}/cmt.exe -quiet build temporary_name`
if $status != 0 then
  set cmtTrigMinBiasMonitoringtempfile=/tmp/cmt.$$
endif
${CMTROOT}/${CMTBIN}/cmt.exe setup -csh -pack=TrigMinBiasMonitoring -version=TrigMinBiasMonitoring-00-01-15 -path=/afs/cern.ch/work/m/mizhou/QF1/Trigger/TrigMonitoring  -quiet -without_version_directory -no_cleanup $* >${cmtTrigMinBiasMonitoringtempfile}
if ( $status != 0 ) then
  echo "${CMTROOT}/${CMTBIN}/cmt.exe setup -csh -pack=TrigMinBiasMonitoring -version=TrigMinBiasMonitoring-00-01-15 -path=/afs/cern.ch/work/m/mizhou/QF1/Trigger/TrigMonitoring  -quiet -without_version_directory -no_cleanup $* >${cmtTrigMinBiasMonitoringtempfile}"
  set cmtsetupstatus=2
  /bin/rm -f ${cmtTrigMinBiasMonitoringtempfile}
  unset cmtTrigMinBiasMonitoringtempfile
  exit $cmtsetupstatus
endif
set cmtsetupstatus=0
source ${cmtTrigMinBiasMonitoringtempfile}
if ( $status != 0 ) then
  set cmtsetupstatus=2
endif
/bin/rm -f ${cmtTrigMinBiasMonitoringtempfile}
unset cmtTrigMinBiasMonitoringtempfile
exit $cmtsetupstatus
