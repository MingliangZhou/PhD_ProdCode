# echo "cleanup HIPileupTool HIPileupTool-00-00-01 in /afs/cern.ch/work/s/sradhakr/Run2Prep/pilup_tool"

if ( $?CMTROOT == 0 ) then
  setenv CMTROOT /cvmfs/atlas.cern.ch/repo/sw/software/x86_64-slc6-gcc48-opt/20.1.9/CMT/v1r25p20140131
endif
source ${CMTROOT}/mgr/setup.csh
set cmtHIPileupTooltempfile=`${CMTROOT}/${CMTBIN}/cmt.exe -quiet build temporary_name`
if $status != 0 then
  set cmtHIPileupTooltempfile=/tmp/cmt.$$
endif
${CMTROOT}/${CMTBIN}/cmt.exe cleanup -csh -pack=HIPileupTool -version=HIPileupTool-00-00-01 -path=/afs/cern.ch/work/s/sradhakr/Run2Prep/pilup_tool  $* >${cmtHIPileupTooltempfile}
if ( $status != 0 ) then
  echo "${CMTROOT}/${CMTBIN}/cmt.exe cleanup -csh -pack=HIPileupTool -version=HIPileupTool-00-00-01 -path=/afs/cern.ch/work/s/sradhakr/Run2Prep/pilup_tool  $* >${cmtHIPileupTooltempfile}"
  set cmtcleanupstatus=2
  /bin/rm -f ${cmtHIPileupTooltempfile}
  unset cmtHIPileupTooltempfile
  exit $cmtcleanupstatus
endif
set cmtcleanupstatus=0
source ${cmtHIPileupTooltempfile}
if ( $status != 0 ) then
  set cmtcleanupstatus=2
endif
/bin/rm -f ${cmtHIPileupTooltempfile}
unset cmtHIPileupTooltempfile
exit $cmtcleanupstatus

