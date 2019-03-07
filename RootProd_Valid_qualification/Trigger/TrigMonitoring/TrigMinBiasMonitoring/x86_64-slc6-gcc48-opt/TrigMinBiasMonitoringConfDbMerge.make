#-- start of make_header -----------------

#====================================
#  Document TrigMinBiasMonitoringConfDbMerge
#
#   Generated Sat Apr 11 21:57:00 2015  by mizhou
#
#====================================

include ${CMTROOT}/src/Makefile.core

ifdef tag
CMTEXTRATAGS = $(tag)
else
tag       = $(CMTCONFIG)
endif

cmt_TrigMinBiasMonitoringConfDbMerge_has_no_target_tag = 1

#--------------------------------------------------------

ifdef cmt_TrigMinBiasMonitoringConfDbMerge_has_target_tag

tags      = $(tag),$(CMTEXTRATAGS),target_TrigMinBiasMonitoringConfDbMerge

TrigMinBiasMonitoring_tag = $(tag)

#cmt_local_tagfile_TrigMinBiasMonitoringConfDbMerge = $(TrigMinBiasMonitoring_tag)_TrigMinBiasMonitoringConfDbMerge.make
cmt_local_tagfile_TrigMinBiasMonitoringConfDbMerge = $(bin)$(TrigMinBiasMonitoring_tag)_TrigMinBiasMonitoringConfDbMerge.make

else

tags      = $(tag),$(CMTEXTRATAGS)

TrigMinBiasMonitoring_tag = $(tag)

#cmt_local_tagfile_TrigMinBiasMonitoringConfDbMerge = $(TrigMinBiasMonitoring_tag).make
cmt_local_tagfile_TrigMinBiasMonitoringConfDbMerge = $(bin)$(TrigMinBiasMonitoring_tag).make

endif

include $(cmt_local_tagfile_TrigMinBiasMonitoringConfDbMerge)
#-include $(cmt_local_tagfile_TrigMinBiasMonitoringConfDbMerge)

ifdef cmt_TrigMinBiasMonitoringConfDbMerge_has_target_tag

cmt_final_setup_TrigMinBiasMonitoringConfDbMerge = $(bin)setup_TrigMinBiasMonitoringConfDbMerge.make
cmt_dependencies_in_TrigMinBiasMonitoringConfDbMerge = $(bin)dependencies_TrigMinBiasMonitoringConfDbMerge.in
#cmt_final_setup_TrigMinBiasMonitoringConfDbMerge = $(bin)TrigMinBiasMonitoring_TrigMinBiasMonitoringConfDbMergesetup.make
cmt_local_TrigMinBiasMonitoringConfDbMerge_makefile = $(bin)TrigMinBiasMonitoringConfDbMerge.make

else

cmt_final_setup_TrigMinBiasMonitoringConfDbMerge = $(bin)setup.make
cmt_dependencies_in_TrigMinBiasMonitoringConfDbMerge = $(bin)dependencies.in
#cmt_final_setup_TrigMinBiasMonitoringConfDbMerge = $(bin)TrigMinBiasMonitoringsetup.make
cmt_local_TrigMinBiasMonitoringConfDbMerge_makefile = $(bin)TrigMinBiasMonitoringConfDbMerge.make

endif

#cmt_final_setup = $(bin)setup.make
#cmt_final_setup = $(bin)TrigMinBiasMonitoringsetup.make

#TrigMinBiasMonitoringConfDbMerge :: ;

dirs ::
	@if test ! -r requirements ; then echo "No requirements file" ; fi; \
	  if test ! -d $(bin) ; then $(mkdir) -p $(bin) ; fi

javadirs ::
	@if test ! -d $(javabin) ; then $(mkdir) -p $(javabin) ; fi

srcdirs ::
	@if test ! -d $(src) ; then $(mkdir) -p $(src) ; fi

help ::
	$(echo) 'TrigMinBiasMonitoringConfDbMerge'

binobj = 
ifdef STRUCTURED_OUTPUT
binobj = TrigMinBiasMonitoringConfDbMerge/
#TrigMinBiasMonitoringConfDbMerge::
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

.PHONY: TrigMinBiasMonitoringConfDbMerge TrigMinBiasMonitoringConfDbMergeclean

# default is already '#'
#genconfDb_comment_char := "'#'"

instdir      := ${CMTINSTALLAREA}/$(tag)
confDbRef    := /afs/cern.ch/work/m/mizhou/QF1/Trigger/TrigMonitoring/TrigMinBiasMonitoring/genConf/TrigMinBiasMonitoring/TrigMinBiasMonitoring.confdb
stampConfDb  := $(confDbRef).stamp
mergedConfDb := $(instdir)/lib/$(project).confdb

TrigMinBiasMonitoringConfDbMerge :: $(stampConfDb) $(mergedConfDb)
	@:

.NOTPARALLEL : $(stampConfDb) $(mergedConfDb)

$(stampConfDb) $(mergedConfDb) :: $(confDbRef)
	@echo "Running merge_genconfDb  TrigMinBiasMonitoringConfDbMerge"
	$(merge_genconfDb_cmd) \
          --do-merge \
          --input-file $(confDbRef) \
          --merged-file $(mergedConfDb)

TrigMinBiasMonitoringConfDbMergeclean ::
	$(cleanup_silent) $(merge_genconfDb_cmd) \
          --un-merge \
          --input-file $(confDbRef) \
          --merged-file $(mergedConfDb)	;
	$(cleanup_silent) $(remove_command) $(stampConfDb)
libTrigMinBiasMonitoring_so_dependencies = ../x86_64-slc6-gcc48-opt/libTrigMinBiasMonitoring.so
#-- start of cleanup_header --------------

clean :: TrigMinBiasMonitoringConfDbMergeclean ;
#	@cd .

ifndef PEDANTIC
.DEFAULT::
	$(echo) "(TrigMinBiasMonitoringConfDbMerge.make) $@: No rule for such target" >&2
else
.DEFAULT::
	$(error PEDANTIC: $@: No rule for such target)
endif

TrigMinBiasMonitoringConfDbMergeclean ::
#-- end of cleanup_header ---------------
