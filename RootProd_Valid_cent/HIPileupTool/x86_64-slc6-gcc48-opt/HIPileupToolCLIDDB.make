#-- start of make_header -----------------

#====================================
#  Document HIPileupToolCLIDDB
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

cmt_HIPileupToolCLIDDB_has_no_target_tag = 1

#--------------------------------------------------------

ifdef cmt_HIPileupToolCLIDDB_has_target_tag

tags      = $(tag),$(CMTEXTRATAGS),target_HIPileupToolCLIDDB

HIPileupTool_tag = $(tag)

#cmt_local_tagfile_HIPileupToolCLIDDB = $(HIPileupTool_tag)_HIPileupToolCLIDDB.make
cmt_local_tagfile_HIPileupToolCLIDDB = $(bin)$(HIPileupTool_tag)_HIPileupToolCLIDDB.make

else

tags      = $(tag),$(CMTEXTRATAGS)

HIPileupTool_tag = $(tag)

#cmt_local_tagfile_HIPileupToolCLIDDB = $(HIPileupTool_tag).make
cmt_local_tagfile_HIPileupToolCLIDDB = $(bin)$(HIPileupTool_tag).make

endif

include $(cmt_local_tagfile_HIPileupToolCLIDDB)
#-include $(cmt_local_tagfile_HIPileupToolCLIDDB)

ifdef cmt_HIPileupToolCLIDDB_has_target_tag

cmt_final_setup_HIPileupToolCLIDDB = $(bin)setup_HIPileupToolCLIDDB.make
cmt_dependencies_in_HIPileupToolCLIDDB = $(bin)dependencies_HIPileupToolCLIDDB.in
#cmt_final_setup_HIPileupToolCLIDDB = $(bin)HIPileupTool_HIPileupToolCLIDDBsetup.make
cmt_local_HIPileupToolCLIDDB_makefile = $(bin)HIPileupToolCLIDDB.make

else

cmt_final_setup_HIPileupToolCLIDDB = $(bin)setup.make
cmt_dependencies_in_HIPileupToolCLIDDB = $(bin)dependencies.in
#cmt_final_setup_HIPileupToolCLIDDB = $(bin)HIPileupToolsetup.make
cmt_local_HIPileupToolCLIDDB_makefile = $(bin)HIPileupToolCLIDDB.make

endif

#cmt_final_setup = $(bin)setup.make
#cmt_final_setup = $(bin)HIPileupToolsetup.make

#HIPileupToolCLIDDB :: ;

dirs ::
	@if test ! -r requirements ; then echo "No requirements file" ; fi; \
	  if test ! -d $(bin) ; then $(mkdir) -p $(bin) ; fi

javadirs ::
	@if test ! -d $(javabin) ; then $(mkdir) -p $(javabin) ; fi

srcdirs ::
	@if test ! -d $(src) ; then $(mkdir) -p $(src) ; fi

help ::
	$(echo) 'HIPileupToolCLIDDB'

binobj = 
ifdef STRUCTURED_OUTPUT
binobj = HIPileupToolCLIDDB/
#HIPileupToolCLIDDB::
#	@if test ! -d $(bin)$(binobj) ; then $(mkdir) -p $(bin)$(binobj) ; fi
#	$(echo) "STRUCTURED_OUTPUT="$(bin)$(binobj)
endif

${CMTROOT}/src/Makefile.core : ;
ifdef use_requirements
$(use_requirements) : ;
endif

#-- end of make_header ------------------
# File: cmt/fragments/genCLIDDB_header
# Author: Paolo Calafiura
# derived from genconf_header

# Use genCLIDDB_cmd to create package clid.db files

.PHONY: HIPileupToolCLIDDB HIPileupToolCLIDDBclean

outname := clid.db
cliddb  := HIPileupTool_$(outname)
instdir := $(CMTINSTALLAREA)/share
result  := $(instdir)/$(cliddb)
product := $(instdir)/$(outname)
conflib := $(bin)$(library_prefix)HIPileupTool.$(shlibsuffix)

HIPileupToolCLIDDB :: $(result)

$(instdir) :
	$(mkdir) -p $(instdir)

$(result) : $(conflib) $(product)
	@$(genCLIDDB_cmd) -p HIPileupTool -i$(product) -o $(result)

$(product) : $(instdir)
	touch $(product)

HIPileupToolCLIDDBclean ::
	$(cleanup_silent) $(uninstall_command) $(product) $(result)
	$(cleanup_silent) $(cmt_uninstallarea_command) $(product) $(result)

#-- start of cleanup_header --------------

clean :: HIPileupToolCLIDDBclean ;
#	@cd .

ifndef PEDANTIC
.DEFAULT::
	$(echo) "(HIPileupToolCLIDDB.make) $@: No rule for such target" >&2
else
.DEFAULT::
	$(error PEDANTIC: $@: No rule for such target)
endif

HIPileupToolCLIDDBclean ::
#-- end of cleanup_header ---------------
