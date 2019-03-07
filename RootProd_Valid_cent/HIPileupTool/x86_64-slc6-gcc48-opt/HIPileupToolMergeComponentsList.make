#-- start of make_header -----------------

#====================================
#  Document HIPileupToolMergeComponentsList
#
#   Generated Mon Feb  1 20:54:38 2016  by sradhakr
#
#====================================

include ${CMTROOT}/src/Makefile.core

ifdef tag
CMTEXTRATAGS = $(tag)
else
tag       = $(CMTCONFIG)
endif

cmt_HIPileupToolMergeComponentsList_has_no_target_tag = 1

#--------------------------------------------------------

ifdef cmt_HIPileupToolMergeComponentsList_has_target_tag

tags      = $(tag),$(CMTEXTRATAGS),target_HIPileupToolMergeComponentsList

HIPileupTool_tag = $(tag)

#cmt_local_tagfile_HIPileupToolMergeComponentsList = $(HIPileupTool_tag)_HIPileupToolMergeComponentsList.make
cmt_local_tagfile_HIPileupToolMergeComponentsList = $(bin)$(HIPileupTool_tag)_HIPileupToolMergeComponentsList.make

else

tags      = $(tag),$(CMTEXTRATAGS)

HIPileupTool_tag = $(tag)

#cmt_local_tagfile_HIPileupToolMergeComponentsList = $(HIPileupTool_tag).make
cmt_local_tagfile_HIPileupToolMergeComponentsList = $(bin)$(HIPileupTool_tag).make

endif

include $(cmt_local_tagfile_HIPileupToolMergeComponentsList)
#-include $(cmt_local_tagfile_HIPileupToolMergeComponentsList)

ifdef cmt_HIPileupToolMergeComponentsList_has_target_tag

cmt_final_setup_HIPileupToolMergeComponentsList = $(bin)setup_HIPileupToolMergeComponentsList.make
cmt_dependencies_in_HIPileupToolMergeComponentsList = $(bin)dependencies_HIPileupToolMergeComponentsList.in
#cmt_final_setup_HIPileupToolMergeComponentsList = $(bin)HIPileupTool_HIPileupToolMergeComponentsListsetup.make
cmt_local_HIPileupToolMergeComponentsList_makefile = $(bin)HIPileupToolMergeComponentsList.make

else

cmt_final_setup_HIPileupToolMergeComponentsList = $(bin)setup.make
cmt_dependencies_in_HIPileupToolMergeComponentsList = $(bin)dependencies.in
#cmt_final_setup_HIPileupToolMergeComponentsList = $(bin)HIPileupToolsetup.make
cmt_local_HIPileupToolMergeComponentsList_makefile = $(bin)HIPileupToolMergeComponentsList.make

endif

#cmt_final_setup = $(bin)setup.make
#cmt_final_setup = $(bin)HIPileupToolsetup.make

#HIPileupToolMergeComponentsList :: ;

dirs ::
	@if test ! -r requirements ; then echo "No requirements file" ; fi; \
	  if test ! -d $(bin) ; then $(mkdir) -p $(bin) ; fi

javadirs ::
	@if test ! -d $(javabin) ; then $(mkdir) -p $(javabin) ; fi

srcdirs ::
	@if test ! -d $(src) ; then $(mkdir) -p $(src) ; fi

help ::
	$(echo) 'HIPileupToolMergeComponentsList'

binobj = 
ifdef STRUCTURED_OUTPUT
binobj = HIPileupToolMergeComponentsList/
#HIPileupToolMergeComponentsList::
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


.PHONY: HIPileupToolMergeComponentsList HIPileupToolMergeComponentsListclean

# default is already '#'
#genmap_comment_char := "'#'"

componentsListRef    := ../$(tag)/HIPileupTool.components

ifdef CMTINSTALLAREA
componentsListDir    := ${CMTINSTALLAREA}/$(tag)/lib
mergedComponentsList := $(componentsListDir)/$(project).components
stampComponentsList  := $(componentsListRef).stamp
else
componentsListDir    := ../$(tag)
mergedComponentsList :=
stampComponentsList  :=
endif

HIPileupToolMergeComponentsList :: $(stampComponentsList) $(mergedComponentsList)
	@:

.NOTPARALLEL : $(stampComponentsList) $(mergedComponentsList)

$(stampComponentsList) $(mergedComponentsList) :: $(componentsListRef)
	@echo "Running merge_componentslist  HIPileupToolMergeComponentsList"
	$(merge_componentslist_cmd) --do-merge \
         --input-file $(componentsListRef) --merged-file $(mergedComponentsList)

HIPileupToolMergeComponentsListclean ::
	$(cleanup_silent) $(merge_componentslist_cmd) --un-merge \
         --input-file $(componentsListRef) --merged-file $(mergedComponentsList) ;
	$(cleanup_silent) $(remove_command) $(stampComponentsList)
libHIPileupTool_so_dependencies = ../x86_64-slc6-gcc48-opt/libHIPileupTool.so
#-- start of cleanup_header --------------

clean :: HIPileupToolMergeComponentsListclean ;
#	@cd .

ifndef PEDANTIC
.DEFAULT::
	$(echo) "(HIPileupToolMergeComponentsList.make) $@: No rule for such target" >&2
else
.DEFAULT::
	$(error PEDANTIC: $@: No rule for such target)
endif

HIPileupToolMergeComponentsListclean ::
#-- end of cleanup_header ---------------
