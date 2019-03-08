# Generated by lcg_generate_env...
if [ -z "${LCG_RELEASE_BASE}" ]; then
   export LCG_RELEASE_BASE=/cvmfs/atlas.cern.ch/repo/sw/software/21.2/sw/lcg/releases
fi
if [ -z "${LCG_PLATFORM}" ]; then
   export LCG_PLATFORM=x86_64-slc6-gcc62-opt
fi
export ROOTSYS=${LCG_RELEASE_BASE}/LCG_88/ROOT/6.08.06/x86_64-slc6-gcc62-opt
export PYTHONHOME=${LCG_RELEASE_BASE}/LCG_91/Python/2.7.13/x86_64-slc6-gcc62-opt
if [ -z "${GAUDI_ROOT}" ]; then
   export GAUDI_ROOT=/cvmfs/atlas.cern.ch/repo/sw/software/21.2/GAUDI/21.2.18/InstallArea/x86_64-slc6-gcc62-opt
fi
if [ -z "${JOBOPTSEARCHPATH}" ]; then
   export JOBOPTSEARCHPATH=/cvmfs/atlas.cern.ch/repo/sw/software/21.2/GAUDI/21.2.13/InstallArea/x86_64-slc6-gcc62-opt/jobOptions
else
   export JOBOPTSEARCHPATH=/cvmfs/atlas.cern.ch/repo/sw/software/21.2/GAUDI/21.2.13/InstallArea/x86_64-slc6-gcc62-opt/jobOptions:${JOBOPTSEARCHPATH}
fi
if [ -z "${DATAPATH}" ]; then
   export DATAPATH=/cvmfs/atlas.cern.ch/repo/sw/software/21.2/GAUDI/21.2.13/InstallArea/x86_64-slc6-gcc62-opt/share
else
   export DATAPATH=/cvmfs/atlas.cern.ch/repo/sw/software/21.2/GAUDI/21.2.13/InstallArea/x86_64-slc6-gcc62-opt/share:${DATAPATH}
fi
if [ -z "${PYTHONPATH}" ]; then
   export PYTHONPATH=${ROOTSYS}/lib:/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AthAnalysisExternals/21.2.13/InstallArea/x86_64-slc6-gcc62-opt/python:/cvmfs/atlas.cern.ch/repo/sw/software/21.2/GAUDI/21.2.13/InstallArea/x86_64-slc6-gcc62-opt/python:/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AthAnalysis/21.2.13/InstallArea/x86_64-slc6-gcc62-opt/python
else
   export PYTHONPATH=${ROOTSYS}/lib:/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AthAnalysisExternals/21.2.13/InstallArea/x86_64-slc6-gcc62-opt/python:/cvmfs/atlas.cern.ch/repo/sw/software/21.2/GAUDI/21.2.13/InstallArea/x86_64-slc6-gcc62-opt/python:/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AthAnalysis/21.2.13/InstallArea/x86_64-slc6-gcc62-opt/python:${PYTHONPATH}
fi
if [ -z "${PATH}" ]; then
   export PATH=${ROOTSYS}/bin:${LCG_RELEASE_BASE}/LCG_88/Python/2.7.13/x86_64-slc6-gcc62-opt/bin:/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AthAnalysisExternals/21.2.13/InstallArea/x86_64-slc6-gcc62-opt/bin:/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AthAnalysis/21.2.13/InstallArea/x86_64-slc6-gcc62-opt/bin
else
   export PATH=${ROOTSYS}/bin:${LCG_RELEASE_BASE}/LCG_88/Python/2.7.13/x86_64-slc6-gcc62-opt/bin:/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AthAnalysisExternals/21.2.13/InstallArea/x86_64-slc6-gcc62-opt/bin:/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AthAnalysis/21.2.13/InstallArea/x86_64-slc6-gcc62-opt/bin:${PATH}
fi
if [ -z "${LD_LIBRARY_PATH}" ]; then
   export LD_LIBRARY_PATH=${LCG_RELEASE_BASE}/LCG_88/Boost/1.62.0/x86_64-slc6-gcc62-opt/lib::${LCG_RELEASE_BASE}/LCG_88/Boost/1.62.0/x86_64-slc6-gcc62-opt/lib::::${LCG_RELEASE_BASE}/LCG_88/tbb/44_20160413/x86_64-slc6-gcc62-opt/lib:${LCG_RELEASE_BASE}/LCG_88/Python/2.7.13/x86_64-slc6-gcc62-opt/lib:${ROOTSYS}/lib:/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AthAnalysisExternals/21.2.13/InstallArea/x86_64-slc6-gcc62-opt/lib:/cvmfs/atlas.cern.ch/repo/sw/software/21.2/GAUDI/21.2.13/InstallArea/x86_64-slc6-gcc62-opt/lib:/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AthAnalysis/21.2.13/InstallArea/x86_64-slc6-gcc62-opt/lib
else
   export LD_LIBRARY_PATH=${LCG_RELEASE_BASE}/LCG_88/Boost/1.62.0/x86_64-slc6-gcc62-opt/lib::${LCG_RELEASE_BASE}/LCG_88/Boost/1.62.0/x86_64-slc6-gcc62-opt/lib::::${LCG_RELEASE_BASE}/LCG_88/tbb/44_20160413/x86_64-slc6-gcc62-opt/lib:${LCG_RELEASE_BASE}/LCG_88/Python/2.7.13/x86_64-slc6-gcc62-opt/lib:${ROOTSYS}/lib:/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AthAnalysisExternals/21.2.13/InstallArea/x86_64-slc6-gcc62-opt/lib:/cvmfs/atlas.cern.ch/repo/sw/software/21.2/GAUDI/21.2.13/InstallArea/x86_64-slc6-gcc62-opt/lib:/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AthAnalysis/21.2.13/InstallArea/x86_64-slc6-gcc62-opt/lib:${LD_LIBRARY_PATH}
fi
if [ -z "${ROOT_INCLUDE_PATH}" ]; then
   export ROOT_INCLUDE_PATH=${LCG_RELEASE_BASE}/LCG_88/Boost/1.62.0/x86_64-slc6-gcc62-opt/include/boost-1_62::${LCG_RELEASE_BASE}/LCG_88/Boost/1.62.0/x86_64-slc6-gcc62-opt/include/boost-1_62::::${LCG_RELEASE_BASE}/LCG_88/tbb/44_20160413/x86_64-slc6-gcc62-opt/include::${LCG_RELEASE_BASE}/LCG_88/Python/2.7.13/x86_64-slc6-gcc62-opt/include/python2.7::${ROOTSYS}/include::/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AthAnalysisExternals/21.2.13/InstallArea/x86_64-slc6-gcc62-opt/include:/cvmfs/atlas.cern.ch/repo/sw/software/21.2/GAUDI/21.2.13/InstallArea/x86_64-slc6-gcc62-opt/include:/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AthAnalysis/21.2.13/InstallArea/x86_64-slc6-gcc62-opt/include
else
   export ROOT_INCLUDE_PATH=${LCG_RELEASE_BASE}/LCG_88/Boost/1.62.0/x86_64-slc6-gcc62-opt/include/boost-1_62::${LCG_RELEASE_BASE}/LCG_88/Boost/1.62.0/x86_64-slc6-gcc62-opt/include/boost-1_62::::${LCG_RELEASE_BASE}/LCG_88/tbb/44_20160413/x86_64-slc6-gcc62-opt/include::${LCG_RELEASE_BASE}/LCG_88/Python/2.7.13/x86_64-slc6-gcc62-opt/include/python2.7::${ROOTSYS}/include::/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AthAnalysisExternals/21.2.13/InstallArea/x86_64-slc6-gcc62-opt/include:/cvmfs/atlas.cern.ch/repo/sw/software/21.2/GAUDI/21.2.13/InstallArea/x86_64-slc6-gcc62-opt/include:/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AthAnalysis/21.2.13/InstallArea/x86_64-slc6-gcc62-opt/include:${ROOT_INCLUDE_PATH}
fi
