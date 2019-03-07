#-- start of make_header -----------------

#====================================
#  Document TrigMinBiasMonitoringComponentsList
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

cmt_TrigMinBiasMonitoringComponentsList_has_no_target_tag = 1

#--------------------------------------------------------

ifdef cmt_TrigMinBiasMonitoringComponentsList_has_target_tag

tags      = $(tag),$(CMTEXTRATAGS),target_TrigMinBiasMonitoringComponentsList

TrigMinBiasMonitoring_tag = $(tag)

#cmt_local_tagfile_TrigMinBiasMonitoringComponentsList = $(TrigMinBiasMonitoring_tag)_TrigMinBiasMonitoringComponentsList.make
cmt_local_tagfile_TrigMinBiasMonitoringComponentsList = $(bin)$(TrigMinBiasMonitoring_tag)_TrigMinBiasMonitoringComponentsList.make

else

tags      = $(tag),$(CMTEXTRATAGS)

TrigMinBiasMonitoring_tag = $(tag)

#cmt_local_tagfile_TrigMinBiasMonitoringComponentsList = $(TrigMinBiasMonitoring_tag).make
cmt_local_tagfile_TrigMinBiasMonitoringComponentsList = $(bin)$(TrigMinBiasMonitoring_tag).make

endif

include $(cmt_local_tagfile_TrigMinBiasMonitoringComponentsList)
#-include $(cmt_local_tagfile_TrigMinBiasMonitoringComponentsList)

ifdef cmt_TrigMinBiasMonitoringComponentsList_has_target_tag

cmt_final_setup_TrigMinBiasMonitoringComponentsList = $(bin)setup_TrigMinBiasMonitoringComponentsList.make
cmt_dependencies_in_TrigMinBiasMonitoringComponentsList = $(bin)dependencies_TrigMinBiasMonitoringComponentsList.in
#cmt_final_setup_TrigMinBiasMonitoringComponentsList = $(bin)TrigMinBiasMonitoring_TrigMinBiasMonitoringComponentsListsetup.make
cmt_local_TrigMinBiasMonitoringComponentsList_makefile = $(bin)TrigMinBiasMonitoringComponentsList.make

else

cmt_final_setup_TrigMinBiasMonitoringComponentsList = $(bin)setup.make
cmt_dependencies_in_TrigMinBiasMonitoringComponentsList = $(bin)dependencies.in
#cmt_final_setup_TrigMinBiasMonitoringComponentsList = $(bin)TrigMinBiasMonitoringsetup.make
cmt_local_TrigMinBiasMonitoringComponentsList_makefile = $(bin)TrigMinBiasMonitoringComponentsList.make

endif

#cmt_final_setup = $(bin)setup.make
#cmt_final_setup = $(bin)TrigMinBiasMonitoringsetup.make

#TrigMinBiasMonitoringComponentsList :: ;

dirs ::
	@if test ! -r requirements ; then echo "No requirements file" ; fi; \
	  if test ! -d $(bin) ; then $(mkdir) -p $(bin) ; fi

javadirs ::
	@if test ! -d $(javabin) ; then $(mkdir) -p $(javabin) ; fi

srcdirs ::
	@if test ! -d $(src) ; then $(mkdir) -p $(src) ; fi

help ::
	$(echo) 'TrigMinBiasMonitoringComponentsList'

binobj = 
ifdef STRUCTURED_OUTPUT
binobj = TrigMinBiasMonitoringComponentsList/
#TrigMinBiasMonitoringComponentsList::
#	@if test ! -d $(bin)$(binobj) ; then $(mkdir) -p $(bin)$(binobj) ; fi
#	$(echo) "STRUCTURED_OUTPUT="$(bin)$(binobj)
endif

${CMTROOT}/src/Makefile.core : ;
ifdef use_requirements
$(use_requirements) : ;
endif

#-- end of make_header ------------------
##
componentslistfile = TrigMinBiasMonitoring.components
COMPONENTSLIST_DIR = ../$(tag)
fulllibname = libTrigMinBiasMonitoring.$(shlibsuffix)

TrigMinBiasMonitoringComponentsList :: ${COMPONENTSLIST_DIR}/$(componentslistfile)
	@:

${COMPONENTSLIST_DIR}/$(componentslistfile) :: $(bin)$(fulllibname)
	@echo 'Generating componentslist file for $(fulllibname)'
	cd ../$(tag);$(listcomponents_cmd) --output ${COMPONENTSLIST_DIR}/$(componentslistfile) $(fulllibname)

install :: TrigMinBiasMonitoringComponentsListinstall
TrigMinBiasMonitoringComponentsListinstall :: TrigMinBiasMonitoringComponentsList

uninstall :: TrigMinBiasMonitoringComponentsListuninstall
TrigMinBiasMonitoringComponentsListuninstall :: TrigMinBiasMonitoringComponentsListclean

TrigMinBiasMonitoringComponentsListclean ::
	@echo 'Deleting $(componentslistfile)'
	@rm -f ${COMPONENTSLIST_DIR}/$(componentslistfile)

#-- start of cleanup_header --------------

clean :: TrigMinBiasMonitoringComponentsListclean ;
#	@cd .

ifndef PEDANTIC
.DEFAULT::
	$(echo) "(TrigMinBiasMonitoringComponentsList.make) $@: No rule for such target" >&2
else
.DEFAULT::
	$(error PEDANTIC: $@: No rule for such target)
endif

TrigMinBiasMonitoringComponentsListclean ::
#-- end of cleanup_header ---------------
