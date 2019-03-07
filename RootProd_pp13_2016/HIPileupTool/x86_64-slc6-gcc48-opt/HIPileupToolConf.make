#-- start of make_header -----------------

#====================================
#  Document HIPileupToolConf
#
#   Generated Mon Feb  1 20:54:36 2016  by sradhakr
#
#====================================

include ${CMTROOT}/src/Makefile.core

ifdef tag
CMTEXTRATAGS = $(tag)
else
tag       = $(CMTCONFIG)
endif

cmt_HIPileupToolConf_has_no_target_tag = 1

#--------------------------------------------------------

ifdef cmt_HIPileupToolConf_has_target_tag

tags      = $(tag),$(CMTEXTRATAGS),target_HIPileupToolConf

HIPileupTool_tag = $(tag)

#cmt_local_tagfile_HIPileupToolConf = $(HIPileupTool_tag)_HIPileupToolConf.make
cmt_local_tagfile_HIPileupToolConf = $(bin)$(HIPileupTool_tag)_HIPileupToolConf.make

else

tags      = $(tag),$(CMTEXTRATAGS)

HIPileupTool_tag = $(tag)

#cmt_local_tagfile_HIPileupToolConf = $(HIPileupTool_tag).make
cmt_local_tagfile_HIPileupToolConf = $(bin)$(HIPileupTool_tag).make

endif

include $(cmt_local_tagfile_HIPileupToolConf)
#-include $(cmt_local_tagfile_HIPileupToolConf)

ifdef cmt_HIPileupToolConf_has_target_tag

cmt_final_setup_HIPileupToolConf = $(bin)setup_HIPileupToolConf.make
cmt_dependencies_in_HIPileupToolConf = $(bin)dependencies_HIPileupToolConf.in
#cmt_final_setup_HIPileupToolConf = $(bin)HIPileupTool_HIPileupToolConfsetup.make
cmt_local_HIPileupToolConf_makefile = $(bin)HIPileupToolConf.make

else

cmt_final_setup_HIPileupToolConf = $(bin)setup.make
cmt_dependencies_in_HIPileupToolConf = $(bin)dependencies.in
#cmt_final_setup_HIPileupToolConf = $(bin)HIPileupToolsetup.make
cmt_local_HIPileupToolConf_makefile = $(bin)HIPileupToolConf.make

endif

#cmt_final_setup = $(bin)setup.make
#cmt_final_setup = $(bin)HIPileupToolsetup.make

#HIPileupToolConf :: ;

dirs ::
	@if test ! -r requirements ; then echo "No requirements file" ; fi; \
	  if test ! -d $(bin) ; then $(mkdir) -p $(bin) ; fi

javadirs ::
	@if test ! -d $(javabin) ; then $(mkdir) -p $(javabin) ; fi

srcdirs ::
	@if test ! -d $(src) ; then $(mkdir) -p $(src) ; fi

help ::
	$(echo) 'HIPileupToolConf'

binobj = 
ifdef STRUCTURED_OUTPUT
binobj = HIPileupToolConf/
#HIPileupToolConf::
#	@if test ! -d $(bin)$(binobj) ; then $(mkdir) -p $(bin)$(binobj) ; fi
#	$(echo) "STRUCTURED_OUTPUT="$(bin)$(binobj)
endif

${CMTROOT}/src/Makefile.core : ;
ifdef use_requirements
$(use_requirements) : ;
endif

#-- end of make_header ------------------
# File: cmt/fragments/genconfig_header
# Author: Wim Lavrijsen (WLavrijsen@lbl.gov)

# Use genconf.exe to create configurables python modules, then have the
# normal python install procedure take over.

.PHONY: HIPileupToolConf HIPileupToolConfclean

confpy  := HIPileupToolConf.py
conflib := $(bin)$(library_prefix)HIPileupTool.$(shlibsuffix)
confdb  := HIPileupTool.confdb
instdir := $(CMTINSTALLAREA)$(shared_install_subdir)/python/$(package)
product := $(instdir)/$(confpy)
initpy  := $(instdir)/__init__.py

ifdef GENCONF_ECHO
genconf_silent =
else
genconf_silent = $(silent)
endif

HIPileupToolConf :: HIPileupToolConfinstall

install :: HIPileupToolConfinstall

HIPileupToolConfinstall : /afs/cern.ch/work/s/sradhakr/Run2Prep/pilup_tool/HIPileupTool/genConf/HIPileupTool/$(confpy)
	@echo "Installing /afs/cern.ch/work/s/sradhakr/Run2Prep/pilup_tool/HIPileupTool/genConf/HIPileupTool in /afs/cern.ch/work/s/sradhakr/Run2Prep/pilup_tool/InstallArea/python" ; \
	 $(install_command) --exclude="*.py?" --exclude="__init__.py" --exclude="*.confdb" /afs/cern.ch/work/s/sradhakr/Run2Prep/pilup_tool/HIPileupTool/genConf/HIPileupTool /afs/cern.ch/work/s/sradhakr/Run2Prep/pilup_tool/InstallArea/python ; \

/afs/cern.ch/work/s/sradhakr/Run2Prep/pilup_tool/HIPileupTool/genConf/HIPileupTool/$(confpy) : $(conflib) /afs/cern.ch/work/s/sradhakr/Run2Prep/pilup_tool/HIPileupTool/genConf/HIPileupTool
	$(genconf_silent) $(genconfig_cmd)   -o /afs/cern.ch/work/s/sradhakr/Run2Prep/pilup_tool/HIPileupTool/genConf/HIPileupTool -p $(package) \
	  --configurable-module=GaudiKernel.Proxy \
	  --configurable-default-name=Configurable.DefaultName \
	  --configurable-algorithm=ConfigurableAlgorithm \
	  --configurable-algtool=ConfigurableAlgTool \
	  --configurable-auditor=ConfigurableAuditor \
          --configurable-service=ConfigurableService \
	  -i ../$(tag)/$(library_prefix)HIPileupTool.$(shlibsuffix)

/afs/cern.ch/work/s/sradhakr/Run2Prep/pilup_tool/HIPileupTool/genConf/HIPileupTool:
	@ if [ ! -d /afs/cern.ch/work/s/sradhakr/Run2Prep/pilup_tool/HIPileupTool/genConf/HIPileupTool ] ; then mkdir -p /afs/cern.ch/work/s/sradhakr/Run2Prep/pilup_tool/HIPileupTool/genConf/HIPileupTool ; fi ;

HIPileupToolConfclean :: HIPileupToolConfuninstall
	$(cleanup_silent) $(remove_command) /afs/cern.ch/work/s/sradhakr/Run2Prep/pilup_tool/HIPileupTool/genConf/HIPileupTool/$(confpy) /afs/cern.ch/work/s/sradhakr/Run2Prep/pilup_tool/HIPileupTool/genConf/HIPileupTool/$(confdb)

uninstall :: HIPileupToolConfuninstall

HIPileupToolConfuninstall ::
	@$(uninstall_command) /afs/cern.ch/work/s/sradhakr/Run2Prep/pilup_tool/InstallArea/python
libHIPileupTool_so_dependencies = ../x86_64-slc6-gcc48-opt/libHIPileupTool.so
#-- start of cleanup_header --------------

clean :: HIPileupToolConfclean ;
#	@cd .

ifndef PEDANTIC
.DEFAULT::
	$(echo) "(HIPileupToolConf.make) $@: No rule for such target" >&2
else
.DEFAULT::
	$(error PEDANTIC: $@: No rule for such target)
endif

HIPileupToolConfclean ::
#-- end of cleanup_header ---------------
