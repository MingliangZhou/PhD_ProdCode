#-- start of make_header -----------------

#====================================
#  Library TrigMinBiasMonitoring
#
#   Generated Sat Apr 11 21:56:22 2015  by mizhou
#
#====================================

include ${CMTROOT}/src/Makefile.core

ifdef tag
CMTEXTRATAGS = $(tag)
else
tag       = $(CMTCONFIG)
endif

cmt_TrigMinBiasMonitoring_has_no_target_tag = 1

#--------------------------------------------------------

ifdef cmt_TrigMinBiasMonitoring_has_target_tag

tags      = $(tag),$(CMTEXTRATAGS),target_TrigMinBiasMonitoring

TrigMinBiasMonitoring_tag = $(tag)

#cmt_local_tagfile_TrigMinBiasMonitoring = $(TrigMinBiasMonitoring_tag)_TrigMinBiasMonitoring.make
cmt_local_tagfile_TrigMinBiasMonitoring = $(bin)$(TrigMinBiasMonitoring_tag)_TrigMinBiasMonitoring.make

else

tags      = $(tag),$(CMTEXTRATAGS)

TrigMinBiasMonitoring_tag = $(tag)

#cmt_local_tagfile_TrigMinBiasMonitoring = $(TrigMinBiasMonitoring_tag).make
cmt_local_tagfile_TrigMinBiasMonitoring = $(bin)$(TrigMinBiasMonitoring_tag).make

endif

include $(cmt_local_tagfile_TrigMinBiasMonitoring)
#-include $(cmt_local_tagfile_TrigMinBiasMonitoring)

ifdef cmt_TrigMinBiasMonitoring_has_target_tag

cmt_final_setup_TrigMinBiasMonitoring = $(bin)setup_TrigMinBiasMonitoring.make
cmt_dependencies_in_TrigMinBiasMonitoring = $(bin)dependencies_TrigMinBiasMonitoring.in
#cmt_final_setup_TrigMinBiasMonitoring = $(bin)TrigMinBiasMonitoring_TrigMinBiasMonitoringsetup.make
cmt_local_TrigMinBiasMonitoring_makefile = $(bin)TrigMinBiasMonitoring.make

else

cmt_final_setup_TrigMinBiasMonitoring = $(bin)setup.make
cmt_dependencies_in_TrigMinBiasMonitoring = $(bin)dependencies.in
#cmt_final_setup_TrigMinBiasMonitoring = $(bin)TrigMinBiasMonitoringsetup.make
cmt_local_TrigMinBiasMonitoring_makefile = $(bin)TrigMinBiasMonitoring.make

endif

#cmt_final_setup = $(bin)setup.make
#cmt_final_setup = $(bin)TrigMinBiasMonitoringsetup.make

#TrigMinBiasMonitoring :: ;

dirs ::
	@if test ! -r requirements ; then echo "No requirements file" ; fi; \
	  if test ! -d $(bin) ; then $(mkdir) -p $(bin) ; fi

javadirs ::
	@if test ! -d $(javabin) ; then $(mkdir) -p $(javabin) ; fi

srcdirs ::
	@if test ! -d $(src) ; then $(mkdir) -p $(src) ; fi

help ::
	$(echo) 'TrigMinBiasMonitoring'

binobj = 
ifdef STRUCTURED_OUTPUT
binobj = TrigMinBiasMonitoring/
#TrigMinBiasMonitoring::
#	@if test ! -d $(bin)$(binobj) ; then $(mkdir) -p $(bin)$(binobj) ; fi
#	$(echo) "STRUCTURED_OUTPUT="$(bin)$(binobj)
endif

${CMTROOT}/src/Makefile.core : ;
ifdef use_requirements
$(use_requirements) : ;
endif

#-- end of make_header ------------------
#-- start of libary_header ---------------

TrigMinBiasMonitoringlibname   = $(bin)$(library_prefix)TrigMinBiasMonitoring$(library_suffix)
TrigMinBiasMonitoringlib       = $(TrigMinBiasMonitoringlibname).a
TrigMinBiasMonitoringstamp     = $(bin)TrigMinBiasMonitoring.stamp
TrigMinBiasMonitoringshstamp   = $(bin)TrigMinBiasMonitoring.shstamp

TrigMinBiasMonitoring :: dirs  TrigMinBiasMonitoringLIB
	$(echo) "TrigMinBiasMonitoring ok"

#-- end of libary_header ----------------
#-- start of library_no_static ------

#TrigMinBiasMonitoringLIB :: $(TrigMinBiasMonitoringlib) $(TrigMinBiasMonitoringshstamp)
TrigMinBiasMonitoringLIB :: $(TrigMinBiasMonitoringshstamp)
	$(echo) "TrigMinBiasMonitoring : library ok"

$(TrigMinBiasMonitoringlib) :: $(bin)TrigMinBiasMonitoring_entries.o $(bin)TrigMinBiasMonitoring_load.o
	$(lib_echo) "static library $@"
	$(lib_silent) cd $(bin); \
	  $(ar) $(TrigMinBiasMonitoringlib) $?
	$(lib_silent) $(ranlib) $(TrigMinBiasMonitoringlib)
	$(lib_silent) cat /dev/null >$(TrigMinBiasMonitoringstamp)

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

$(TrigMinBiasMonitoringlibname).$(shlibsuffix) :: $(bin)TrigMinBiasMonitoring_entries.o $(bin)TrigMinBiasMonitoring_load.o $(use_requirements) $(TrigMinBiasMonitoringstamps)
	$(lib_echo) "shared library $@"
	$(lib_silent) $(shlibbuilder) $(shlibflags) -o $@ $(bin)TrigMinBiasMonitoring_entries.o $(bin)TrigMinBiasMonitoring_load.o $(TrigMinBiasMonitoring_shlibflags)
	$(lib_silent) cat /dev/null >$(TrigMinBiasMonitoringstamp) && \
	  cat /dev/null >$(TrigMinBiasMonitoringshstamp)

$(TrigMinBiasMonitoringshstamp) :: $(TrigMinBiasMonitoringlibname).$(shlibsuffix)
	$(lib_silent) if test -f $(TrigMinBiasMonitoringlibname).$(shlibsuffix) ; then \
	  cat /dev/null >$(TrigMinBiasMonitoringstamp) && \
	  cat /dev/null >$(TrigMinBiasMonitoringshstamp) ; fi

TrigMinBiasMonitoringclean ::
	$(cleanup_echo) objects TrigMinBiasMonitoring
	$(cleanup_silent) /bin/rm -f $(bin)TrigMinBiasMonitoring_entries.o $(bin)TrigMinBiasMonitoring_load.o
	$(cleanup_silent) /bin/rm -f $(patsubst %.o,%.d,$(bin)TrigMinBiasMonitoring_entries.o $(bin)TrigMinBiasMonitoring_load.o) $(patsubst %.o,%.dep,$(bin)TrigMinBiasMonitoring_entries.o $(bin)TrigMinBiasMonitoring_load.o) $(patsubst %.o,%.d.stamp,$(bin)TrigMinBiasMonitoring_entries.o $(bin)TrigMinBiasMonitoring_load.o)
	$(cleanup_silent) cd $(bin); /bin/rm -rf TrigMinBiasMonitoring_deps TrigMinBiasMonitoring_dependencies.make

#-----------------------------------------------------------------
#
#  New section for automatic installation
#
#-----------------------------------------------------------------

install_dir = ${CMTINSTALLAREA}/$(tag)/lib
TrigMinBiasMonitoringinstallname = $(library_prefix)TrigMinBiasMonitoring$(library_suffix).$(shlibsuffix)

TrigMinBiasMonitoring :: TrigMinBiasMonitoringinstall ;

install :: TrigMinBiasMonitoringinstall ;

TrigMinBiasMonitoringinstall :: $(install_dir)/$(TrigMinBiasMonitoringinstallname)
ifdef CMTINSTALLAREA
	$(echo) "installation done"
endif

$(install_dir)/$(TrigMinBiasMonitoringinstallname) :: $(bin)$(TrigMinBiasMonitoringinstallname)
ifdef CMTINSTALLAREA
	$(install_silent) $(cmt_install_action) \
	    -source "`(cd $(bin); pwd)`" \
	    -name "$(TrigMinBiasMonitoringinstallname)" \
	    -out "$(install_dir)" \
	    -cmd "$(cmt_installarea_command)" \
	    -cmtpath "$($(package)_cmtpath)"
endif

##TrigMinBiasMonitoringclean :: TrigMinBiasMonitoringuninstall

uninstall :: TrigMinBiasMonitoringuninstall ;

TrigMinBiasMonitoringuninstall ::
ifdef CMTINSTALLAREA
	$(cleanup_silent) $(cmt_uninstall_action) \
	    -source "`(cd $(bin); pwd)`" \
	    -name "$(TrigMinBiasMonitoringinstallname)" \
	    -out "$(install_dir)" \
	    -cmtpath "$($(package)_cmtpath)"
endif

#-- end of library_no_static ------
#-- start of cpp_library -----------------

ifneq (-MMD -MP -MF $*.d -MQ $@,)

ifneq ($(MAKECMDGOALS),TrigMinBiasMonitoringclean)
ifneq ($(MAKECMDGOALS),uninstall)
-include $(bin)$(binobj)TrigMinBiasMonitoring_entries.d

$(bin)$(binobj)TrigMinBiasMonitoring_entries.d :

$(bin)$(binobj)TrigMinBiasMonitoring_entries.o : $(cmt_final_setup_TrigMinBiasMonitoring)

$(bin)$(binobj)TrigMinBiasMonitoring_entries.o : $(src)components/TrigMinBiasMonitoring_entries.cxx
	$(cpp_echo) $(src)components/TrigMinBiasMonitoring_entries.cxx
	$(cpp_silent) $(cppcomp) -MMD -MP -MF $*.d -MQ $@ -o $@ $(use_pp_cppflags) $(TrigMinBiasMonitoring_pp_cppflags) $(lib_TrigMinBiasMonitoring_pp_cppflags) $(TrigMinBiasMonitoring_entries_pp_cppflags) $(use_cppflags) $(TrigMinBiasMonitoring_cppflags) $(lib_TrigMinBiasMonitoring_cppflags) $(TrigMinBiasMonitoring_entries_cppflags) $(TrigMinBiasMonitoring_entries_cxx_cppflags) -I../src/components $(src)components/TrigMinBiasMonitoring_entries.cxx
endif
endif

else
$(bin)TrigMinBiasMonitoring_dependencies.make : $(TrigMinBiasMonitoring_entries_cxx_dependencies)

$(bin)TrigMinBiasMonitoring_dependencies.make : $(src)components/TrigMinBiasMonitoring_entries.cxx

$(bin)$(binobj)TrigMinBiasMonitoring_entries.o : $(TrigMinBiasMonitoring_entries_cxx_dependencies)
	$(cpp_echo) $(src)components/TrigMinBiasMonitoring_entries.cxx
	$(cpp_silent) $(cppcomp) -o $@ $(use_pp_cppflags) $(TrigMinBiasMonitoring_pp_cppflags) $(lib_TrigMinBiasMonitoring_pp_cppflags) $(TrigMinBiasMonitoring_entries_pp_cppflags) $(use_cppflags) $(TrigMinBiasMonitoring_cppflags) $(lib_TrigMinBiasMonitoring_cppflags) $(TrigMinBiasMonitoring_entries_cppflags) $(TrigMinBiasMonitoring_entries_cxx_cppflags) -I../src/components $(src)components/TrigMinBiasMonitoring_entries.cxx

endif

#-- end of cpp_library ------------------
#-- start of cpp_library -----------------

ifneq (-MMD -MP -MF $*.d -MQ $@,)

ifneq ($(MAKECMDGOALS),TrigMinBiasMonitoringclean)
ifneq ($(MAKECMDGOALS),uninstall)
-include $(bin)$(binobj)TrigMinBiasMonitoring_load.d

$(bin)$(binobj)TrigMinBiasMonitoring_load.d :

$(bin)$(binobj)TrigMinBiasMonitoring_load.o : $(cmt_final_setup_TrigMinBiasMonitoring)

$(bin)$(binobj)TrigMinBiasMonitoring_load.o : $(src)components/TrigMinBiasMonitoring_load.cxx
	$(cpp_echo) $(src)components/TrigMinBiasMonitoring_load.cxx
	$(cpp_silent) $(cppcomp) -MMD -MP -MF $*.d -MQ $@ -o $@ $(use_pp_cppflags) $(TrigMinBiasMonitoring_pp_cppflags) $(lib_TrigMinBiasMonitoring_pp_cppflags) $(TrigMinBiasMonitoring_load_pp_cppflags) $(use_cppflags) $(TrigMinBiasMonitoring_cppflags) $(lib_TrigMinBiasMonitoring_cppflags) $(TrigMinBiasMonitoring_load_cppflags) $(TrigMinBiasMonitoring_load_cxx_cppflags) -I../src/components $(src)components/TrigMinBiasMonitoring_load.cxx
endif
endif

else
$(bin)TrigMinBiasMonitoring_dependencies.make : $(TrigMinBiasMonitoring_load_cxx_dependencies)

$(bin)TrigMinBiasMonitoring_dependencies.make : $(src)components/TrigMinBiasMonitoring_load.cxx

$(bin)$(binobj)TrigMinBiasMonitoring_load.o : $(TrigMinBiasMonitoring_load_cxx_dependencies)
	$(cpp_echo) $(src)components/TrigMinBiasMonitoring_load.cxx
	$(cpp_silent) $(cppcomp) -o $@ $(use_pp_cppflags) $(TrigMinBiasMonitoring_pp_cppflags) $(lib_TrigMinBiasMonitoring_pp_cppflags) $(TrigMinBiasMonitoring_load_pp_cppflags) $(use_cppflags) $(TrigMinBiasMonitoring_cppflags) $(lib_TrigMinBiasMonitoring_cppflags) $(TrigMinBiasMonitoring_load_cppflags) $(TrigMinBiasMonitoring_load_cxx_cppflags) -I../src/components $(src)components/TrigMinBiasMonitoring_load.cxx

endif

#-- end of cpp_library ------------------
#-- start of cleanup_header --------------

clean :: TrigMinBiasMonitoringclean ;
#	@cd .

ifndef PEDANTIC
.DEFAULT::
	$(echo) "(TrigMinBiasMonitoring.make) $@: No rule for such target" >&2
else
.DEFAULT::
	$(error PEDANTIC: $@: No rule for such target)
endif

TrigMinBiasMonitoringclean ::
#-- end of cleanup_header ---------------
#-- start of cleanup_library -------------
	$(cleanup_echo) library TrigMinBiasMonitoring
	-$(cleanup_silent) cd $(bin) && \rm -f $(library_prefix)TrigMinBiasMonitoring$(library_suffix).a $(library_prefix)TrigMinBiasMonitoring$(library_suffix).$(shlibsuffix) TrigMinBiasMonitoring.stamp TrigMinBiasMonitoring.shstamp
#-- end of cleanup_library ---------------