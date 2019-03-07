#-- start of make_header -----------------

#====================================
#  Library TrigMinBiasMonitoringLib
#
#   Generated Sat Apr 11 21:55:02 2015  by mizhou
#
#====================================

include ${CMTROOT}/src/Makefile.core

ifdef tag
CMTEXTRATAGS = $(tag)
else
tag       = $(CMTCONFIG)
endif

cmt_TrigMinBiasMonitoringLib_has_no_target_tag = 1

#--------------------------------------------------------

ifdef cmt_TrigMinBiasMonitoringLib_has_target_tag

tags      = $(tag),$(CMTEXTRATAGS),target_TrigMinBiasMonitoringLib

TrigMinBiasMonitoring_tag = $(tag)

#cmt_local_tagfile_TrigMinBiasMonitoringLib = $(TrigMinBiasMonitoring_tag)_TrigMinBiasMonitoringLib.make
cmt_local_tagfile_TrigMinBiasMonitoringLib = $(bin)$(TrigMinBiasMonitoring_tag)_TrigMinBiasMonitoringLib.make

else

tags      = $(tag),$(CMTEXTRATAGS)

TrigMinBiasMonitoring_tag = $(tag)

#cmt_local_tagfile_TrigMinBiasMonitoringLib = $(TrigMinBiasMonitoring_tag).make
cmt_local_tagfile_TrigMinBiasMonitoringLib = $(bin)$(TrigMinBiasMonitoring_tag).make

endif

include $(cmt_local_tagfile_TrigMinBiasMonitoringLib)
#-include $(cmt_local_tagfile_TrigMinBiasMonitoringLib)

ifdef cmt_TrigMinBiasMonitoringLib_has_target_tag

cmt_final_setup_TrigMinBiasMonitoringLib = $(bin)setup_TrigMinBiasMonitoringLib.make
cmt_dependencies_in_TrigMinBiasMonitoringLib = $(bin)dependencies_TrigMinBiasMonitoringLib.in
#cmt_final_setup_TrigMinBiasMonitoringLib = $(bin)TrigMinBiasMonitoring_TrigMinBiasMonitoringLibsetup.make
cmt_local_TrigMinBiasMonitoringLib_makefile = $(bin)TrigMinBiasMonitoringLib.make

else

cmt_final_setup_TrigMinBiasMonitoringLib = $(bin)setup.make
cmt_dependencies_in_TrigMinBiasMonitoringLib = $(bin)dependencies.in
#cmt_final_setup_TrigMinBiasMonitoringLib = $(bin)TrigMinBiasMonitoringsetup.make
cmt_local_TrigMinBiasMonitoringLib_makefile = $(bin)TrigMinBiasMonitoringLib.make

endif

#cmt_final_setup = $(bin)setup.make
#cmt_final_setup = $(bin)TrigMinBiasMonitoringsetup.make

#TrigMinBiasMonitoringLib :: ;

dirs ::
	@if test ! -r requirements ; then echo "No requirements file" ; fi; \
	  if test ! -d $(bin) ; then $(mkdir) -p $(bin) ; fi

javadirs ::
	@if test ! -d $(javabin) ; then $(mkdir) -p $(javabin) ; fi

srcdirs ::
	@if test ! -d $(src) ; then $(mkdir) -p $(src) ; fi

help ::
	$(echo) 'TrigMinBiasMonitoringLib'

binobj = 
ifdef STRUCTURED_OUTPUT
binobj = TrigMinBiasMonitoringLib/
#TrigMinBiasMonitoringLib::
#	@if test ! -d $(bin)$(binobj) ; then $(mkdir) -p $(bin)$(binobj) ; fi
#	$(echo) "STRUCTURED_OUTPUT="$(bin)$(binobj)
endif

${CMTROOT}/src/Makefile.core : ;
ifdef use_requirements
$(use_requirements) : ;
endif

#-- end of make_header ------------------
#-- start of libary_header ---------------

TrigMinBiasMonitoringLiblibname   = $(bin)$(library_prefix)TrigMinBiasMonitoringLib$(library_suffix)
TrigMinBiasMonitoringLiblib       = $(TrigMinBiasMonitoringLiblibname).a
TrigMinBiasMonitoringLibstamp     = $(bin)TrigMinBiasMonitoringLib.stamp
TrigMinBiasMonitoringLibshstamp   = $(bin)TrigMinBiasMonitoringLib.shstamp

TrigMinBiasMonitoringLib :: dirs  TrigMinBiasMonitoringLibLIB
	$(echo) "TrigMinBiasMonitoringLib ok"

#-- end of libary_header ----------------
#-- start of library_no_static ------

#TrigMinBiasMonitoringLibLIB :: $(TrigMinBiasMonitoringLiblib) $(TrigMinBiasMonitoringLibshstamp)
TrigMinBiasMonitoringLibLIB :: $(TrigMinBiasMonitoringLibshstamp)
	$(echo) "TrigMinBiasMonitoringLib : library ok"

$(TrigMinBiasMonitoringLiblib) :: $(bin)HLTMinBiasMonTool.o
	$(lib_echo) "static library $@"
	$(lib_silent) cd $(bin); \
	  $(ar) $(TrigMinBiasMonitoringLiblib) $?
	$(lib_silent) $(ranlib) $(TrigMinBiasMonitoringLiblib)
	$(lib_silent) cat /dev/null >$(TrigMinBiasMonitoringLibstamp)

#------------------------------------------------------------------
#  Future improvement? to empty the object files after
#  storing in the library
#
##	  for f in $?; do \
##	    rm $${f}; touch $${f}; \
##	  done
#------------------------------------------------------------------

#
# We add one level of dependency upon the true shared library 
# (rather than simply upon the stamp file)
# this is for cases where the shared library has not been built
# while the stamp was created (error??) 
#

$(TrigMinBiasMonitoringLiblibname).$(shlibsuffix) :: $(bin)HLTMinBiasMonTool.o $(use_requirements) $(TrigMinBiasMonitoringLibstamps)
	$(lib_echo) "shared library $@"
	$(lib_silent) $(shlibbuilder) $(shlibflags) -o $@ $(bin)HLTMinBiasMonTool.o $(TrigMinBiasMonitoringLib_shlibflags)
	$(lib_silent) cat /dev/null >$(TrigMinBiasMonitoringLibstamp) && \
	  cat /dev/null >$(TrigMinBiasMonitoringLibshstamp)

$(TrigMinBiasMonitoringLibshstamp) :: $(TrigMinBiasMonitoringLiblibname).$(shlibsuffix)
	$(lib_silent) if test -f $(TrigMinBiasMonitoringLiblibname).$(shlibsuffix) ; then \
	  cat /dev/null >$(TrigMinBiasMonitoringLibstamp) && \
	  cat /dev/null >$(TrigMinBiasMonitoringLibshstamp) ; fi

TrigMinBiasMonitoringLibclean ::
	$(cleanup_echo) objects TrigMinBiasMonitoringLib
	$(cleanup_silent) /bin/rm -f $(bin)HLTMinBiasMonTool.o
	$(cleanup_silent) /bin/rm -f $(patsubst %.o,%.d,$(bin)HLTMinBiasMonTool.o) $(patsubst %.o,%.dep,$(bin)HLTMinBiasMonTool.o) $(patsubst %.o,%.d.stamp,$(bin)HLTMinBiasMonTool.o)
	$(cleanup_silent) cd $(bin); /bin/rm -rf TrigMinBiasMonitoringLib_deps TrigMinBiasMonitoringLib_dependencies.make

#-----------------------------------------------------------------
#
#  New section for automatic installation
#
#-----------------------------------------------------------------

install_dir = ${CMTINSTALLAREA}/$(tag)/lib
TrigMinBiasMonitoringLibinstallname = $(library_prefix)TrigMinBiasMonitoringLib$(library_suffix).$(shlibsuffix)

TrigMinBiasMonitoringLib :: TrigMinBiasMonitoringLibinstall ;

install :: TrigMinBiasMonitoringLibinstall ;

TrigMinBiasMonitoringLibinstall :: $(install_dir)/$(TrigMinBiasMonitoringLibinstallname)
ifdef CMTINSTALLAREA
	$(echo) "installation done"
endif

$(install_dir)/$(TrigMinBiasMonitoringLibinstallname) :: $(bin)$(TrigMinBiasMonitoringLibinstallname)
ifdef CMTINSTALLAREA
	$(install_silent) $(cmt_install_action) \
	    -source "`(cd $(bin); pwd)`" \
	    -name "$(TrigMinBiasMonitoringLibinstallname)" \
	    -out "$(install_dir)" \
	    -cmd "$(cmt_installarea_command)" \
	    -cmtpath "$($(package)_cmtpath)"
endif

##TrigMinBiasMonitoringLibclean :: TrigMinBiasMonitoringLibuninstall

uninstall :: TrigMinBiasMonitoringLibuninstall ;

TrigMinBiasMonitoringLibuninstall ::
ifdef CMTINSTALLAREA
	$(cleanup_silent) $(cmt_uninstall_action) \
	    -source "`(cd $(bin); pwd)`" \
	    -name "$(TrigMinBiasMonitoringLibinstallname)" \
	    -out "$(install_dir)" \
	    -cmtpath "$($(package)_cmtpath)"
endif

#-- end of library_no_static ------
#-- start of cpp_library -----------------

ifneq (-MMD -MP -MF $*.d -MQ $@,)

ifneq ($(MAKECMDGOALS),TrigMinBiasMonitoringLibclean)
ifneq ($(MAKECMDGOALS),uninstall)
-include $(bin)$(binobj)HLTMinBiasMonTool.d

$(bin)$(binobj)HLTMinBiasMonTool.d :

$(bin)$(binobj)HLTMinBiasMonTool.o : $(cmt_final_setup_TrigMinBiasMonitoringLib)

$(bin)$(binobj)HLTMinBiasMonTool.o : $(src)HLTMinBiasMonTool.cxx
	$(cpp_echo) $(src)HLTMinBiasMonTool.cxx
	$(cpp_silent) $(cppcomp) -MMD -MP -MF $*.d -MQ $@ -o $@ $(use_pp_cppflags) $(TrigMinBiasMonitoringLib_pp_cppflags) $(lib_TrigMinBiasMonitoringLib_pp_cppflags) $(HLTMinBiasMonTool_pp_cppflags) $(use_cppflags) $(TrigMinBiasMonitoringLib_cppflags) $(lib_TrigMinBiasMonitoringLib_cppflags) $(HLTMinBiasMonTool_cppflags) $(HLTMinBiasMonTool_cxx_cppflags)  $(src)HLTMinBiasMonTool.cxx
endif
endif

else
$(bin)TrigMinBiasMonitoringLib_dependencies.make : $(HLTMinBiasMonTool_cxx_dependencies)

$(bin)TrigMinBiasMonitoringLib_dependencies.make : $(src)HLTMinBiasMonTool.cxx

$(bin)$(binobj)HLTMinBiasMonTool.o : $(HLTMinBiasMonTool_cxx_dependencies)
	$(cpp_echo) $(src)HLTMinBiasMonTool.cxx
	$(cpp_silent) $(cppcomp) -o $@ $(use_pp_cppflags) $(TrigMinBiasMonitoringLib_pp_cppflags) $(lib_TrigMinBiasMonitoringLib_pp_cppflags) $(HLTMinBiasMonTool_pp_cppflags) $(use_cppflags) $(TrigMinBiasMonitoringLib_cppflags) $(lib_TrigMinBiasMonitoringLib_cppflags) $(HLTMinBiasMonTool_cppflags) $(HLTMinBiasMonTool_cxx_cppflags)  $(src)HLTMinBiasMonTool.cxx

endif

#-- end of cpp_library ------------------
#-- start of cleanup_header --------------

clean :: TrigMinBiasMonitoringLibclean ;
#	@cd .

ifndef PEDANTIC
.DEFAULT::
	$(echo) "(TrigMinBiasMonitoringLib.make) $@: No rule for such target" >&2
else
.DEFAULT::
	$(error PEDANTIC: $@: No rule for such target)
endif

TrigMinBiasMonitoringLibclean ::
#-- end of cleanup_header ---------------
#-- start of cleanup_library -------------
	$(cleanup_echo) library TrigMinBiasMonitoringLib
	-$(cleanup_silent) cd $(bin) && \rm -f $(library_prefix)TrigMinBiasMonitoringLib$(library_suffix).a $(library_prefix)TrigMinBiasMonitoringLib$(library_suffix).$(shlibsuffix) TrigMinBiasMonitoringLib.stamp TrigMinBiasMonitoringLib.shstamp
#-- end of cleanup_library ---------------
