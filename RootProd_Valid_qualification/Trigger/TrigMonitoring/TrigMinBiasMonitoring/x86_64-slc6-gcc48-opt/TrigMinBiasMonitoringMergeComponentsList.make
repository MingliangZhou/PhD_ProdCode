#-- start of make_header -----------------

#====================================
#  Document TrigMinBiasMonitoringMergeComponentsList
#
#   Generated Sat Apr 11 21:57:02 2015  by mizhou
#
#====================================

include ${CMTROOT}/src/Makefile.core

ifdef tag
CMTEXTRATAGS = $(tag)
else
tag       = $(CMTCONFIG)
endif

cmt_TrigMinBiasMonitoringMergeComponentsList_has_no_target_tag = 1

#--------------------------------------------------------

ifdef cmt_TrigMinBiasMonitoringMergeComponentsList_has_target_tag

tags      = $(tag),$(CMTEXTRATAGS),target_TrigMinBiasMonitoringMergeComponentsList

TrigMinBiasMonitoring_tag = $(tag)

#cmt_local_tagfile_TrigMinBiasMonitoringMergeComponentsList = $(TrigMinBiasMonitoring_tag)_TrigMinBiasMonitoringMergeComponentsList.make
cmt_local_tagfile_TrigMinBiasMonitoringMergeComponentsList = $(bin)$(TrigMinBiasMonitoring_tag)_TrigMinBiasMonitoringMergeComponentsList.make

else

tags      = $(tag),$(CMTEXTRATAGS)

TrigMinBiasMonitoring_tag = $(tag)

#cmt_local_tagfile_TrigMinBiasMonitoringMergeComponentsList = $(TrigMinBiasMonitoring_tag).make
cmt_local_tagfile_TrigMinBiasMonitoringMergeComponentsList = $(bin)$(TrigMinBiasMonitoring_tag).make

endif

include $(cmt_local_tagfile_TrigMinBiasMonitoringMergeComponentsList)
#-include $(cmt_local_tagfile_TrigMinBiasMonitoringMergeComponentsList)

ifdef cmt_TrigMinBiasMonitoringMergeComponentsList_has_target_tag

cmt_final_setup_TrigMinBiasMonitoringMergeComponentsList = $(bin)setup_TrigMinBiasMonitoringMergeComponentsList.make
cmt_dependencies_in_TrigMinBiasMonitoringMergeComponentsList = $(bin)dependencies_TrigMinBiasMonitoringMergeComponentsList.in
#cmt_final_setup_TrigMinBiasMonitoringMergeComponentsList = $(bin)TrigMinBiasMonitoring_TrigMinBiasMonitoringMergeComponentsListsetup.make
cmt_local_TrigMinBiasMonitoringMergeComponentsList_makefile = $(bin)TrigMinBiasMonitoringMergeComponentsList.make

else

cmt_final_setup_TrigMinBiasMonitoringMergeComponentsList = $(bin)setup.make
cmt_dependencies_in_TrigMinBiasMonitoringMergeComponentsList = $(bin)dependencies.in
#cmt_final_setup_TrigMinBiasMonitoringMergeComponentsList = $(bin)TrigMinBiasMonitoringsetup.make
cmt_local_TrigMinBiasMonitoringMergeComponentsList_makefile = $(bin)TrigMinBiasMonitoringMergeComponentsList.make

endif

#cmt_final_setup = $(bin)setup.make
#cmt_final_setup = $(bin)TrigMinBiasMonitoringsetup.make

#TrigMinBiasMonitoringMergeComponentsList :: ;

dirs ::
	@if test ! -r requirements ; then echo "No requirements file" ; fi; \
	  if test ! -d $(bin) ; then $(mkdir) -p $(bin) ; fi

javadirs ::
	@if test ! -d $(javabin) ; then $(mkdir) -p $(javabin) ; fi

srcdirs ::
	@if test ! -d $(src) ; then $(mkdir) -p $(src) ; fi

help ::
	$(echo) 'TrigMinBiasMonitoringMergeComponentsList'

binobj = 
ifdef STRUCTURED_OUTPUT
binobj = TrigMinBiasMonitoringMergeComponentsList/
#TrigMinBiasMonitoringMergeComponentsList::
#	@if test ! -d $(bin)$(binobj) ; then $(mkdir) -p $(bin)$(binobj) ; fi
#	$(echo) "STRUCTURED_OUTPUT="$(bin)$(binobj)
endif

${CMTROOT}/src/Makefile.core : ;
ifdef use_requirements
$(use_requirements) : ;
endif

#-- end of make_header ------------------
# File: cmt/fragments/merge_componentslist_header
# Author: Sebastien Binet (binet@cern.ch)

# Makefile fragment to merge a <library>.components file into a single
# <project>.components file in the (lib) install area
# If no InstallArea is present the fragment is dummy


.PHONY: TrigMinBiasMonitoringMergeComponentsList TrigMinBiasMonitoringMergeComponentsListclean

# default is already '#'
#genmap_comment_char := "'#'"

componentsListRef    := ../$(tag)/TrigMinBiasMonitoring.components

ifdef CMTINSTALLAREA
componentsListDir    := ${CMTINSTALLAREA}/$(tag)/lib
mergedComponentsList := $(componentsListDir)/$(project).components
stampComponentsList  := $(componentsListRef).stamp
else
componentsListDir    := ../$(tag)
mergedComponentsList :=
stampComponentsList  :=
endif

TrigMinBiasMonitoringMergeComponentsList :: $(stampComponentsList) $(mergedComponentsList)
	@:

.NOTPARALLEL : $(stampComponentsList) $(mergedComponentsList)

$(stampComponentsList) $(mergedComponentsList) :: $(componentsListRef)
	@echo "Running merge_componentslist  TrigMinBiasMonitoringMergeComponentsList"
	$(merge_componentslist_cmd) --do-merge \
         --input-file $(componentsListRef) --merged-file $(mergedComponentsList)

TrigMinBiasMonitoringMergeComponentsListclean ::
	$(cleanup_silent) $(merge_componentslist_cmd) --un-merge \
         --input-file $(componentsListRef) --merged-file $(mergedComponentsList) ;
	$(cleanup_silent) $(remove_command) $(stampComponentsList)
libTrigMinBiasMonitoring_so_dependencies = ../x86_64-slc6-gcc48-opt/libTrigMinBiasMonitoring.so
#-- start of cleanup_header --------------

clean :: TrigMinBiasMonitoringMergeComponentsListclean ;
#	@cd .

ifndef PEDANTIC
.DEFAULT::
	$(echo) "(TrigMinBiasMonitoringMergeComponentsList.make) $@: No rule for such target" >&2
else
.DEFAULT::
	$(error PEDANTIC: $@: No rule for such target)
endif

TrigMinBiasMonitoringMergeComponentsListclean ::
#-- end of cleanup_header ---------------
