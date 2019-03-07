#-- start of make_header -----------------

#====================================
#  Document HIPileupToolConfDbMerge
#
#   Generated Mon Feb  1 20:54:37 2016  by sradhakr
#
#====================================

include ${CMTROOT}/src/Makefile.core

ifdef tag
CMTEXTRATAGS = $(tag)
else
tag       = $(CMTCONFIG)
endif

cmt_HIPileupToolConfDbMerge_has_no_target_tag = 1

#--------------------------------------------------------

ifdef cmt_HIPileupToolConfDbMerge_has_target_tag

tags      = $(tag),$(CMTEXTRATAGS),target_HIPileupToolConfDbMerge

HIPileupTool_tag = $(tag)

#cmt_local_tagfile_HIPileupToolConfDbMerge = $(HIPileupTool_tag)_HIPileupToolConfDbMerge.make
cmt_local_tagfile_HIPileupToolConfDbMerge = $(bin)$(HIPileupTool_tag)_HIPileupToolConfDbMerge.make

else

tags      = $(tag),$(CMTEXTRATAGS)

HIPileupTool_tag = $(tag)

#cmt_local_tagfile_HIPileupToolConfDbMerge = $(HIPileupTool_tag).make
cmt_local_tagfile_HIPileupToolConfDbMerge = $(bin)$(HIPileupTool_tag).make

endif

include $(cmt_local_tagfile_HIPileupToolConfDbMerge)
#-include $(cmt_local_tagfile_HIPileupToolConfDbMerge)

ifdef cmt_HIPileupToolConfDbMerge_has_target_tag

cmt_final_setup_HIPileupToolConfDbMerge = $(bin)setup_HIPileupToolConfDbMerge.make
cmt_dependencies_in_HIPileupToolConfDbMerge = $(bin)dependencies_HIPileupToolConfDbMerge.in
#cmt_final_setup_HIPileupToolConfDbMerge = $(bin)HIPileupTool_HIPileupToolConfDbMergesetup.make
cmt_local_HIPileupToolConfDbMerge_makefile = $(bin)HIPileupToolConfDbMerge.make

else

cmt_final_setup_HIPileupToolConfDbMerge = $(bin)setup.make
cmt_dependencies_in_HIPileupToolConfDbMerge = $(bin)dependencies.in
#cmt_final_setup_HIPileupToolConfDbMerge = $(bin)HIPileupToolsetup.make
cmt_local_HIPileupToolConfDbMerge_makefile = $(bin)HIPileupToolConfDbMerge.make

endif

#cmt_final_setup = $(bin)setup.make
#cmt_final_setup = $(bin)HIPileupToolsetup.make

#HIPileupToolConfDbMerge :: ;

dirs ::
	@if test ! -r requirements ; then echo "No requirements file" ; fi; \
	  if test ! -d $(bin) ; then $(mkdir) -p $(bin) ; fi

javadirs ::
	@if test ! -d $(javabin) ; then $(mkdir) -p $(javabin) ; fi

srcdirs ::
	@if test ! -d $(src) ; then $(mkdir) -p $(src) ; fi

help ::
	$(echo) 'HIPileupToolConfDbMerge'

binobj = 
ifdef STRUCTURED_OUTPUT
binobj = HIPileupToolConfDbMerge/
#HIPileupToolConfDbMerge::
#	@if test ! -d $(bin)$(binobj) ; then $(mkdir) -p $(bin)$(binobj) ; fi
#	$(echo) "STRUCTURED_OUTPUT="$(bin)$(binobj)
endif

${CMTROOT}/src/Makefile.core : ;
ifdef use_requirements
$(use_requirements) : ;
endif

#-- end of make_header ------------------
# File: cmt/fragments/merge_genconfDb_header
# Author: Sebastien Binet (binet@cern.ch)

# Makefile fragment to merge a <library>.confdb file into a single
# <project>.confdb file in the (lib) install area

.PHONY: HIPileupToolConfDbMerge HIPileupToolConfDbMergeclean

# default is already '#'
#genconfDb_comment_char := "'#'"

instdir      := ${CMTINSTALLAREA}/$(tag)
confDbRef    := /afs/cern.ch/work/s/sradhakr/Run2Prep/pilup_tool/HIPileupTool/genConf/HIPileupTool/HIPileupTool.confdb
stampConfDb  := $(confDbRef).stamp
mergedConfDb := $(instdir)/lib/$(project).confdb

HIPileupToolConfDbMerge :: $(stampConfDb) $(mergedConfDb)
	@:

.NOTPARALLEL : $(stampConfDb) $(mergedConfDb)

$(stampConfDb) $(mergedConfDb) :: $(confDbRef)
	@echo "Running merge_genconfDb  HIPileupToolConfDbMerge"
	$(merge_genconfDb_cmd) \
          --do-merge \
          --input-file $(confDbRef) \
          --merged-file $(mergedConfDb)

HIPileupToolConfDbMergeclean ::
	$(cleanup_silent) $(merge_genconfDb_cmd) \
          --un-merge \
          --input-file $(confDbRef) \
          --merged-file $(mergedConfDb)	;
	$(cleanup_silent) $(remove_command) $(stampConfDb)
libHIPileupTool_so_dependencies = ../x86_64-slc6-gcc48-opt/libHIPileupTool.so
#-- start of cleanup_header --------------

clean :: HIPileupToolConfDbMergeclean ;
#	@cd .

ifndef PEDANTIC
.DEFAULT::
	$(echo) "(HIPileupToolConfDbMerge.make) $@: No rule for such target" >&2
else
.DEFAULT::
	$(error PEDANTIC: $@: No rule for such target)
endif

HIPileupToolConfDbMergeclean ::
#-- end of cleanup_header ---------------
