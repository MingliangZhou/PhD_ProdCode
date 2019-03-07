# echo "cleanup HIPileupTool HIPileupTool-00-00-01 in /afs/cern.ch/work/s/sradhakr/Run2Prep/pilup_tool"

if test "${CMTROOT}" = ""; then
  CMTROOT=/cvmfs/atlas.cern.ch/repo/sw/software/x86_64-slc6-gcc48-opt/20.1.9/CMT/v1r25p20140131; export CMTROOT
fi
. ${CMTROOT}/mgr/setup.sh
cmtHIPileupTooltempfile=`${CMTROOT}/${CMTBIN}/cmt.exe -quiet build temporary_name`
if test ! $? = 0 ; then cmtHIPileupTooltempfile=/tmp/cmt.$$; fi
${CMTROOT}/${CMTBIN}/cmt.exe cleanup -sh -pack=HIPileupTool -version=HIPileupTool-00-00-01 -path=/afs/cern.ch/work/s/sradhakr/Run2Prep/pilup_tool  $* >${cmtHIPileupTooltempfile}
if test $? != 0 ; then
  echo >&2 "${CMTROOT}/${CMTBIN}/cmt.exe cleanup -sh -pack=HIPileupTool -version=HIPileupTool-00-00-01 -path=/afs/cern.ch/work/s/sradhakr/Run2Prep/pilup_tool  $* >${cmtHIPileupTooltempfile}"
  cmtcleanupstatus=2
  /bin/rm -f ${cmtHIPileupTooltempfile}
  unset cmtHIPileupTooltempfile
  return $cmtcleanupstatus
fi
cmtcleanupstatus=0
. ${cmtHIPileupTooltempfile}
if test $? != 0 ; then
  cmtcleanupstatus=2
fi
/bin/rm -f ${cmtHIPileupTooltempfile}
unset cmtHIPileupTooltempfile
return $cmtcleanupstatus

