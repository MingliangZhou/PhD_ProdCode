# echo "cleanup TrigMinBiasMonitoring TrigMinBiasMonitoring-00-01-15 in /afs/cern.ch/work/m/mizhou/QF1/Trigger/TrigMonitoring"

if test "${CMTROOT}" = ""; then
  CMTROOT=/cvmfs/atlas.cern.ch/repo/sw/software/x86_64-slc6-gcc48-opt/20.1.0/CMT/v1r25p20140131; export CMTROOT
fi
. ${CMTROOT}/mgr/setup.sh
cmtTrigMinBiasMonitoringtempfile=`${CMTROOT}/${CMTBIN}/cmt.exe -quiet build temporary_name`
if test ! $? = 0 ; then cmtTrigMinBiasMonitoringtempfile=/tmp/cmt.$$; fi
${CMTROOT}/${CMTBIN}/cmt.exe cleanup -sh -pack=TrigMinBiasMonitoring -version=TrigMinBiasMonitoring-00-01-15 -path=/afs/cern.ch/work/m/mizhou/QF1/Trigger/TrigMonitoring  -quiet -without_version_directory $* >${cmtTrigMinBiasMonitoringtempfile}
if test $? != 0 ; then
  echo >&2 "${CMTROOT}/${CMTBIN}/cmt.exe cleanup -sh -pack=TrigMinBiasMonitoring -version=TrigMinBiasMonitoring-00-01-15 -path=/afs/cern.ch/work/m/mizhou/QF1/Trigger/TrigMonitoring  -quiet -without_version_directory $* >${cmtTrigMinBiasMonitoringtempfile}"
  cmtcleanupstatus=2
  /bin/rm -f ${cmtTrigMinBiasMonitoringtempfile}
  unset cmtTrigMinBiasMonitoringtempfile
  return $cmtcleanupstatus
fi
cmtcleanupstatus=0
. ${cmtTrigMinBiasMonitoringtempfile}
if test $? != 0 ; then
  cmtcleanupstatus=2
fi
/bin/rm -f ${cmtTrigMinBiasMonitoringtempfile}
unset cmtTrigMinBiasMonitoringtempfile
return $cmtcleanupstatus

