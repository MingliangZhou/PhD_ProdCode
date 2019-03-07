#-- start of make_header -----------------

#====================================
#  Document HIPileupToolComponentsList
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

cmt_HIPileupToolComponentsList_has_no_target_tag = 1

#--------------------------------------------------------

ifdef cmt_HIPileupToolComponentsList_has_target_tag

tags      = $(tag),$(CMTEXTRATAGS),target_HIPileupToolComponentsList

HIPileupTool_tag = $(tag)

#cmt_local_tagfile_HIPileupToolComponentsList = $(HIPileupTool_tag)_HIPileupToolComponentsList.make
cmt_local_tagfile_HIPileupToolComponentsList = $(bin)$(HIPileupTool_tag)_HIPileupToolComponentsList.make

else

tags      = $(tag),$(CMTEXTRATAGS)

HIPileupTool_tag = $(tag)

#cmt_local_tagfile_HIPileupToolComponentsList = $(HIPileupTool_tag).make
cmt_local_tagfile_HIPileupToolComponentsList = $(bin)$(HIPileupTool_tag).make

endif

include $(cmt_local_tagfile_HIPileupToolComponentsList)
#-include $(cmt_local_tagfile_HIPileupToolComponentsList)

ifdef cmt_HIPileupToolComponentsList_has_target_tag

cmt_final_setup_HIPileupToolComponentsList = $(bin)setup_HIPileupToolComponentsList.make
cmt_dependencies_in_HIPileupToolComponentsList = $(bin)dependencies_HIPileupToolComponentsList.in
#cmt_final_setup_HIPileupToolComponentsList = $(bin)HIPileupTool_HIPileupToolComponentsListsetup.make
cmt_local_HIPileupToolComponentsList_makefile = $(bin)HIPileupToolComponentsList.make

else

cmt_final_setup_HIPileupToolComponentsList = $(bin)setup.make
cmt_dependencies_in_HIPileupToolComponentsList = $(bin)dependencies.in
#cmt_final_setup_HIPileupToolComponentsList = $(bin)HIPileupToolsetup.make
cmt_local_HIPileupToolComponentsList_makefile = $(bin)HIPileupToolComponentsList.make

endif

#cmt_final_setup = $(bin)setup.make
#cmt_final_setup = $(bin)HIPileupToolsetup.make

#HIPileupToolComponentsList :: ;

dirs ::
	@if test ! -r requirements ; then echo "No requirements file" ; fi; \
	  if test ! -d $(bin) ; then $(mkdir) -p $(bin) ; fi

javadirs ::
	@if test ! -d $(javabin) ; then $(mkdir) -p $(javabin) ; fi

srcdirs ::
	@if test ! -d $(src) ; then $(mkdir) -p $(src) ; fi

help ::
	$(echo) 'HIPileupToolComponentsList'

binobj = 
ifdef STRUCTURED_OUTPUT
binobj = HIPileupToolComponentsList/
#HIPileupToolComponentsList::
#	@if test ! -d $(bin)$(binobj) ; then $(mkdir) -p $(bin)$(binobj) ; fi
#	$(echo) "STRUCTURED_OUTPUT="$(bin)$(binobj)
endif

${CMTROOT}/src/Makefile.core : ;
ifdef use_requirements
$(use_requirements) : ;
endif

#-- end of make_header ------------------
##
componentslistfile = HIPileupTool.components
COMPONENTSLIST_DIR = ../$(tag)
fulllibname = libHIPileupTool.$(shlibsuffix)

HIPileupToolComponentsList :: ${COMPONENTSLIST_DIR}/$(componentslistfile)
	@:

${COMPONENTSLIST_DIR}/$(componentslistfile) :: $(bin)$(fulllibname)
	@echo 'Generating componentslist file for $(fulllibname)'
	cd ../$(tag);$(listcomponents_cmd) --output ${COMPONENTSLIST_DIR}/$(componentslistfile) $(fulllibname)

install :: HIPileupToolComponentsListinstall
HIPileupToolComponentsListinstall :: HIPileupToolComponentsList

uninstall :: HIPileupToolComponentsListuninstall
HIPileupToolComponentsListuninstall :: HIPileupToolComponentsListclean

HIPileupToolComponentsListclean ::
	@echo 'Deleting $(componentslistfile)'
	@rm -f ${COMPONENTSLIST_DIR}/$(componentslistfile)

#-- start of cleanup_header --------------

clean :: HIPileupToolComponentsListclean ;
#	@cd .

ifndef PEDANTIC
.DEFAULT::
	$(echo) "(HIPileupToolComponentsList.make) $@: No rule for such target" >&2
else
.DEFAULT::
	$(error PEDANTIC: $@: No rule for such target)
endif

HIPileupToolComponentsListclean ::
#-- end of cleanup_header ---------------
