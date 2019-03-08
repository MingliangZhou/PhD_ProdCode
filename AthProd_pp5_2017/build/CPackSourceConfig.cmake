# This file will be configured to contain variables for CPack. These variables
# should be set in the CMake list file of the project before CPack module is
# included. The list of available CPACK_xxx variables and their associated
# documentation may be obtained using
#  cpack --help-variable-list
#
# Some variables are common to all generators (e.g. CPACK_PACKAGE_NAME)
# and some are specific to a generator
# (e.g. CPACK_NSIS_EXTRA_INSTALL_COMMANDS). The generator specific variables
# usually begin with CPACK_<GENNAME>_xxxx.


SET(CPACK_BINARY_7Z "")
SET(CPACK_BINARY_BUNDLE "")
SET(CPACK_BINARY_CYGWIN "")
SET(CPACK_BINARY_DEB "")
SET(CPACK_BINARY_DRAGNDROP "")
SET(CPACK_BINARY_IFW "")
SET(CPACK_BINARY_NSIS "")
SET(CPACK_BINARY_OSXX11 "")
SET(CPACK_BINARY_PACKAGEMAKER "")
SET(CPACK_BINARY_PRODUCTBUILD "")
SET(CPACK_BINARY_RPM "")
SET(CPACK_BINARY_STGZ "")
SET(CPACK_BINARY_TBZ2 "")
SET(CPACK_BINARY_TGZ "")
SET(CPACK_BINARY_TXZ "")
SET(CPACK_BINARY_TZ "")
SET(CPACK_BINARY_WIX "")
SET(CPACK_BINARY_ZIP "")
SET(CPACK_BUILD_SOURCE_DIRS "/afs/cern.ch/work/m/mizhou/AthProd_pp5_2017/source;/afs/cern.ch/work/m/mizhou/AthProd_pp5_2017/build")
SET(CPACK_CMAKE_GENERATOR "Unix Makefiles")
SET(CPACK_COMPONENTS_ALL "Debug;Unspecified")
SET(CPACK_COMPONENT_UNSPECIFIED_HIDDEN "TRUE")
SET(CPACK_COMPONENT_UNSPECIFIED_REQUIRED "TRUE")
SET(CPACK_GENERATOR "RPM")
SET(CPACK_IGNORE_FILES "/CVS/;/\\.svn/;/\\.bzr/;/\\.hg/;/\\.git/;\\.swp\$;\\.#;/#")
SET(CPACK_INSTALLED_DIRECTORIES "/afs/cern.ch/work/m/mizhou/AthProd_pp5_2017/source;/")
SET(CPACK_INSTALL_CMAKE_PROJECTS "")
SET(CPACK_INSTALL_COMMANDS "/afs/cern.ch/work/m/mizhou/AthProd_pp5_2017/build/cpack_install.sh")
SET(CPACK_INSTALL_PREFIX "usr/WorkDir/21.2.13/InstallArea/x86_64-slc6-gcc62-opt")
SET(CPACK_INSTALL_SCRIPT "/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AthAnalysis/21.2.13/InstallArea/x86_64-slc6-gcc62-opt/cmake/modules/scripts/cpack_install.cmake")
SET(CPACK_MODULE_PATH "/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AthAnalysis/21.2.13/InstallArea/x86_64-slc6-gcc62-opt/cmake/modules;/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AthAnalysisExternals/21.2.13/InstallArea/x86_64-slc6-gcc62-opt/cmake/modules")
SET(CPACK_NSIS_DISPLAY_NAME "WorkDir/21.2.13/InstallArea/x86_64-slc6-gcc62-opt")
SET(CPACK_NSIS_INSTALLER_ICON_CODE "")
SET(CPACK_NSIS_INSTALLER_MUI_ICON_CODE "")
SET(CPACK_NSIS_INSTALL_ROOT "$PROGRAMFILES")
SET(CPACK_NSIS_PACKAGE_NAME "WorkDir/21.2.13/InstallArea/x86_64-slc6-gcc62-opt")
SET(CPACK_OUTPUT_CONFIG_FILE "/afs/cern.ch/work/m/mizhou/AthProd_pp5_2017/build/CPackConfig.cmake")
SET(CPACK_PACKAGE_CONTACT "atlas-sw-core@cern.ch")
SET(CPACK_PACKAGE_DEFAULT_LOCATION "/usr")
SET(CPACK_PACKAGE_DESCRIPTION "WorkDir - 21.2.13")
SET(CPACK_PACKAGE_DESCRIPTION_FILE "/afs/cern.ch/work/m/mizhou/AthProd_pp5_2017/build/README.txt")
SET(CPACK_PACKAGE_DESCRIPTION_SUMMARY "WorkDir - 21.2.13")
SET(CPACK_PACKAGE_FILE_NAME "WorkDir-21.2.13-Source")
SET(CPACK_PACKAGE_INSTALL_DIRECTORY "WorkDir/21.2.13/InstallArea/x86_64-slc6-gcc62-opt")
SET(CPACK_PACKAGE_INSTALL_REGISTRY_KEY "WorkDir/21.2.13/InstallArea/x86_64-slc6-gcc62-opt")
SET(CPACK_PACKAGE_NAME "WorkDir")
SET(CPACK_PACKAGE_RELOCATABLE "true")
SET(CPACK_PACKAGE_VENDOR "ATLAS Collaboration")
SET(CPACK_PACKAGE_VERSION "21.2.13")
SET(CPACK_PACKAGE_VERSION_MAJOR "21")
SET(CPACK_PACKAGE_VERSION_MINOR "2")
SET(CPACK_PACKAGE_VERSION_PATCH "13")
SET(CPACK_PROJECT_CONFIG_FILE "/afs/cern.ch/work/m/mizhou/AthProd_pp5_2017/build/CPackOptions.cmake")
SET(CPACK_RESOURCE_FILE_LICENSE "/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AthAnalysis/21.2.13/InstallArea/x86_64-slc6-gcc62-opt/LICENSE.txt")
SET(CPACK_RESOURCE_FILE_README "/afs/cern.ch/work/m/mizhou/AthProd_pp5_2017/build/README.txt")
SET(CPACK_RESOURCE_FILE_WELCOME "/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/Cmake/3.8.1/Linux-x86_64/share/cmake-3.8/Templates/CPack.GenericWelcome.txt")
SET(CPACK_RPM_PACKAGE_ARCHITECTURE "noarch")
SET(CPACK_RPM_PACKAGE_AUTOREQ " no")
SET(CPACK_RPM_PACKAGE_AUTOREQPROV " no")
SET(CPACK_RPM_PACKAGE_GROUP "ATLAS Software")
SET(CPACK_RPM_PACKAGE_LICENSE "Simplified BSD")
SET(CPACK_RPM_PACKAGE_NAME "WorkDir_21.2.13_x86_64-slc6-gcc62-opt")
SET(CPACK_RPM_PACKAGE_PROVIDES "/bin/sh")
SET(CPACK_RPM_PACKAGE_REQUIRES "AthAnalysis_21.2.13_x86_64-slc6-gcc62-opt, LCG_88_ROOT_6.08.06_x86_64_slc6_gcc62_opt, LCG_88_tbb_44_20160413_x86_64_slc6_gcc62_opt, LCG_88_Python_2.7.13_x86_64_slc6_gcc62_opt, GAUDI_21.2.13_x86_64-slc6-gcc62-opt")
SET(CPACK_RPM_PACKAGE_SOURCES "ON")
SET(CPACK_RPM_PACKAGE_VERSION "21.2.13")
SET(CPACK_SET_DESTDIR "OFF")
SET(CPACK_SOURCE_7Z "")
SET(CPACK_SOURCE_CYGWIN "")
SET(CPACK_SOURCE_GENERATOR "RPM")
SET(CPACK_SOURCE_IGNORE_FILES "/CVS/;/\\.svn/;/\\.bzr/;/\\.hg/;/\\.git/;\\.swp\$;\\.#;/#")
SET(CPACK_SOURCE_INSTALLED_DIRECTORIES "/afs/cern.ch/work/m/mizhou/AthProd_pp5_2017/source;/")
SET(CPACK_SOURCE_OUTPUT_CONFIG_FILE "/afs/cern.ch/work/m/mizhou/AthProd_pp5_2017/build/CPackSourceConfig.cmake")
SET(CPACK_SOURCE_PACKAGE_FILE_NAME "WorkDir-21.2.13-Source")
SET(CPACK_SOURCE_RPM "")
SET(CPACK_SOURCE_TBZ2 "")
SET(CPACK_SOURCE_TGZ "")
SET(CPACK_SOURCE_TOPLEVEL_TAG "Linux-Source")
SET(CPACK_SOURCE_TXZ "")
SET(CPACK_SOURCE_TZ "")
SET(CPACK_SOURCE_ZIP "")
SET(CPACK_STRIP_FILES "")
SET(CPACK_SYSTEM_NAME "Linux")
SET(CPACK_TOPLEVEL_TAG "Linux-Source")
SET(CPACK_WIX_SIZEOF_VOID_P "8")

if(NOT CPACK_PROPERTIES_FILE)
  set(CPACK_PROPERTIES_FILE "/afs/cern.ch/work/m/mizhou/AthProd_pp5_2017/build/CPackProperties.cmake")
endif()

if(EXISTS ${CPACK_PROPERTIES_FILE})
  include(${CPACK_PROPERTIES_FILE})
endif()
