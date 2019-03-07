#-- start of make_header -----------------

#====================================
#  Library HIPileupTool
#
#   Generated Mon Feb  1 20:54:21 2016  by sradhakr
#
#====================================

include ${CMTROOT}/src/Makefile.core

ifdef tag
CMTEXTRATAGS = $(tag)
else
tag       = $(CMTCONFIG)
endif

cmt_HIPileupTool_has_no_target_tag = 1

#--------------------------------------------------------

ifdef cmt_HIPileupTool_has_target_tag

tags      = $(tag),$(CMTEXTRATAGS),target_HIPileupTool

HIPileupTool_tag = $(tag)

#cmt_local_tagfile_HIPileupTool = $(HIPileupTool_tag)_HIPileupTool.make
cmt_local_tagfile_HIPileupTool = $(bin)$(HIPileupTool_tag)_HIPileupTool.make

else

tags      = $(tag),$(CMTEXTRATAGS)

HIPileupTool_tag = $(tag)

#cmt_local_tagfile_HIPileupTool = $(HIPileupTool_tag).make
cmt_local_tagfile_HIPileupTool = $(bin)$(HIPileupTool_tag).make

endif

include $(cmt_local_tagfile_HIPileupTool)
#-include $(cmt_local_tagfile_HIPileupTool)

ifdef cmt_HIPileupTool_has_target_tag

cmt_final_setup_HIPileupTool = $(bin)setup_HIPileupTool.make
cmt_dependencies_in_HIPileupTool = $(bin)dependencies_HIPileupTool.in
#cmt_final_setup_HIPileupTool = $(bin)HIPileupTool_HIPileupToolsetup.make
cmt_local_HIPileupTool_makefile = $(bin)HIPileupTool.make

else

cmt_final_setup_HIPileupTool = $(bin)setup.make
cmt_dependencies_in_HIPileupTool = $(bin)dependencies.in
#cmt_final_setup_HIPileupTool = $(bin)HIPileupToolsetup.make
cmt_local_HIPileupTool_makefile = $(bin)HIPileupTool.make

endif

#cmt_final_setup = $(bin)setup.make
#cmt_final_setup = $(bin)HIPileupToolsetup.make

#HIPileupTool :: ;

dirs ::
	@if test ! -r requirements ; then echo "No requirements file" ; fi; \
	  if test ! -d $(bin) ; then $(mkdir) -p $(bin) ; fi

javadirs ::
	@if test ! -d $(javabin) ; then $(mkdir) -p $(javabin) ; fi

srcdirs ::
	@if test ! -d $(src) ; then $(mkdir) -p $(src) ; fi

help ::
	$(echo) 'HIPileupTool'

binobj = 
ifdef STRUCTURED_OUTPUT
binobj = HIPileupTool/
#HIPileupTool::
#	@if test ! -d $(bin)$(binobj) ; then $(mkdir) -p $(bin)$(binobj) ; fi
#	$(echo) "STRUCTURED_OUTPUT="$(bin)$(binobj)
endif

${CMTROOT}/src/Makefile.core : ;
ifdef use_requirements
$(use_requirements) : ;
endif

#-- end of make_header ------------------
#-- start of libary_header ---------------

HIPileupToollibname   = $(bin)$(library_prefix)HIPileupTool$(library_suffix)
HIPileupToollib       = $(HIPileupToollibname).a
HIPileupToolstamp     = $(bin)HIPileupTool.stamp
HIPileupToolshstamp   = $(bin)HIPileupTool.shstamp

HIPileupTool :: dirs  HIPileupToolLIB
	$(echo) "HIPileupTool ok"

#-- end of libary_header ----------------
#-- start of library_no_static ------

#HIPileupToolLIB :: $(HIPileupToollib) $(HIPileupToolshstamp)
HIPileupToolLIB :: $(HIPileupToolshstamp)
	$(echo) "HIPileupTool : library ok"

$(HIPileupToollib) :: $(bin)HIPileupAlgo.o $(bin)HIPileupTool.o $(bin)HIPileupTool_load.o $(bin)HIPileupTool_entries.o
	$(lib_echo) "static library $@"
	$(lib_silent) cd $(bin); \
	  $(ar) $(HIPileupToollib) $?
	$(lib_silent) $(ranlib) $(HIPileupToollib)
	$(lib_silent) cat /dev/null >$(HIPileupToolstamp)

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

$(HIPileupToollibname).$(shlibsuffix) :: $(bin)HIPileupAlgo.o $(bin)HIPileupTool.o $(bin)HIPileupTool_load.o $(bin)HIPileupTool_entries.o $(use_requirements) $(HIPileupToolstamps)
	$(lib_echo) "shared library $@"
	$(lib_silent) $(shlibbuilder) $(shlibflags) -o $@ $(bin)HIPileupAlgo.o $(bin)HIPileupTool.o $(bin)HIPileupTool_load.o $(bin)HIPileupTool_entries.o $(HIPileupTool_shlibflags)
	$(lib_silent) cat /dev/null >$(HIPileupToolstamp) && \
	  cat /dev/null >$(HIPileupToolshstamp)

$(HIPileupToolshstamp) :: $(HIPileupToollibname).$(shlibsuffix)
	$(lib_silent) if test -f $(HIPileupToollibname).$(shlibsuffix) ; then \
	  cat /dev/null >$(HIPileupToolstamp) && \
	  cat /dev/null >$(HIPileupToolshstamp) ; fi

HIPileupToolclean ::
	$(cleanup_echo) objects HIPileupTool
	$(cleanup_silent) /bin/rm -f $(bin)HIPileupAlgo.o $(bin)HIPileupTool.o $(bin)HIPileupTool_load.o $(bin)HIPileupTool_entries.o
	$(cleanup_silent) /bin/rm -f $(patsubst %.o,%.d,$(bin)HIPileupAlgo.o $(bin)HIPileupTool.o $(bin)HIPileupTool_load.o $(bin)HIPileupTool_entries.o) $(patsubst %.o,%.dep,$(bin)HIPileupAlgo.o $(bin)HIPileupTool.o $(bin)HIPileupTool_load.o $(bin)HIPileupTool_entries.o) $(patsubst %.o,%.d.stamp,$(bin)HIPileupAlgo.o $(bin)HIPileupTool.o $(bin)HIPileupTool_load.o $(bin)HIPileupTool_entries.o)
	$(cleanup_silent) cd $(bin); /bin/rm -rf HIPileupTool_deps HIPileupTool_dependencies.make

#-----------------------------------------------------------------
#
#  New section for automatic installation
#
#-----------------------------------------------------------------

install_dir = ${CMTINSTALLAREA}/$(tag)/lib
HIPileupToolinstallname = $(library_prefix)HIPileupTool$(library_suffix).$(shlibsuffix)

HIPileupTool :: HIPileupToolinstall ;

install :: HIPileupToolinstall ;

HIPileupToolinstall :: $(install_dir)/$(HIPileupToolinstallname)
ifdef CMTINSTALLAREA
	$(echo) "installation done"
endif

$(install_dir)/$(HIPileupToolinstallname) :: $(bin)$(HIPileupToolinstallname)
ifdef CMTINSTALLAREA
	$(install_silent) $(cmt_install_action) \
	    -source "`(cd $(bin); pwd)`" \
	    -name "$(HIPileupToolinstallname)" \
	    -out "$(install_dir)" \
	    -cmd "$(cmt_installarea_command)" \
	    -cmtpath "$($(package)_cmtpath)"
endif

##HIPileupToolclean :: HIPileupTooluninstall

uninstall :: HIPileupTooluninstall ;

HIPileupTooluninstall ::
ifdef CMTINSTALLAREA
	$(cleanup_silent) $(cmt_uninstall_action) \
	    -source "`(cd $(bin); pwd)`" \
	    -name "$(HIPileupToolinstallname)" \
	    -out "$(install_dir)" \
	    -cmtpath "$($(package)_cmtpath)"
endif

#-- end of library_no_static ------
#-- start of cpp_library -----------------

ifneq (-MMD -MP -MF $*.d -MQ $@,)

ifneq ($(MAKECMDGOALS),HIPileupToolclean)
ifneq ($(MAKECMDGOALS),uninstall)
-include $(bin)$(binobj)HIPileupAlgo.d

$(bin)$(binobj)HIPileupAlgo.d :

$(bin)$(binobj)HIPileupAlgo.o : $(cmt_final_setup_HIPileupTool)

$(bin)$(binobj)HIPileupAlgo.o : $(src)HIPileupAlgo.cxx
	$(cpp_echo) $(src)HIPileupAlgo.cxx
	$(cpp_silent) $(cppcomp) -MMD -MP -MF $*.d -MQ $@ -o $@ $(use_pp_cppflags) $(HIPileupTool_pp_cppflags) $(lib_HIPileupTool_pp_cppflags) $(HIPileupAlgo_pp_cppflags) $(use_cppflags) $(HIPileupTool_cppflags) $(lib_HIPileupTool_cppflags) $(HIPileupAlgo_cppflags) $(HIPileupAlgo_cxx_cppflags)  $(src)HIPileupAlgo.cxx
endif
endif

else
$(bin)HIPileupTool_dependencies.make : $(HIPileupAlgo_cxx_dependencies)

$(bin)HIPileupTool_dependencies.make : $(src)HIPileupAlgo.cxx

$(bin)$(binobj)HIPileupAlgo.o : $(HIPileupAlgo_cxx_dependencies)
	$(cpp_echo) $(src)HIPileupAlgo.cxx
	$(cpp_silent) $(cppcomp) -o $@ $(use_pp_cppflags) $(HIPileupTool_pp_cppflags) $(lib_HIPileupTool_pp_cppflags) $(HIPileupAlgo_pp_cppflags) $(use_cppflags) $(HIPileupTool_cppflags) $(lib_HIPileupTool_cppflags) $(HIPileupAlgo_cppflags) $(HIPileupAlgo_cxx_cppflags)  $(src)HIPileupAlgo.cxx

endif

#-- end of cpp_library ------------------
#-- start of cpp_library -----------------

ifneq (-MMD -MP -MF $*.d -MQ $@,)

ifneq ($(MAKECMDGOALS),HIPileupToolclean)
ifneq ($(MAKECMDGOALS),uninstall)
-include $(bin)$(binobj)HIPileupTool.d

$(bin)$(binobj)HIPileupTool.d :

$(bin)$(binobj)HIPileupTool.o : $(cmt_final_setup_HIPileupTool)

$(bin)$(binobj)HIPileupTool.o : ../Root/HIPileupTool.cxx
	$(cpp_echo) ../Root/HIPileupTool.cxx
	$(cpp_silent) $(cppcomp) -MMD -MP -MF $*.d -MQ $@ -o $@ $(use_pp_cppflags) $(HIPileupTool_pp_cppflags) $(lib_HIPileupTool_pp_cppflags) $(HIPileupTool_pp_cppflags) $(use_cppflags) $(HIPileupTool_cppflags) $(lib_HIPileupTool_cppflags) $(HIPileupTool_cppflags) $(HIPileupTool_cxx_cppflags) -I../Root ../Root/HIPileupTool.cxx
endif
endif

else
$(bin)HIPileupTool_dependencies.make : $(HIPileupTool_cxx_dependencies)

$(bin)HIPileupTool_dependencies.make : ../Root/HIPileupTool.cxx

$(bin)$(binobj)HIPileupTool.o : $(HIPileupTool_cxx_dependencies)
	$(cpp_echo) ../Root/HIPileupTool.cxx
	$(cpp_silent) $(cppcomp) -o $@ $(use_pp_cppflags) $(HIPileupTool_pp_cppflags) $(lib_HIPileupTool_pp_cppflags) $(HIPileupTool_pp_cppflags) $(use_cppflags) $(HIPileupTool_cppflags) $(lib_HIPileupTool_cppflags) $(HIPileupTool_cppflags) $(HIPileupTool_cxx_cppflags) -I../Root ../Root/HIPileupTool.cxx

endif

#-- end of cpp_library ------------------
#-- start of cpp_library -----------------

ifneq (-MMD -MP -MF $*.d -MQ $@,)

ifneq ($(MAKECMDGOALS),HIPileupToolclean)
ifneq ($(MAKECMDGOALS),uninstall)
-include $(bin)$(binobj)HIPileupTool_load.d

$(bin)$(binobj)HIPileupTool_load.d :

$(bin)$(binobj)HIPileupTool_load.o : $(cmt_final_setup_HIPileupTool)

$(bin)$(binobj)HIPileupTool_load.o : $(src)components/HIPileupTool_load.cxx
	$(cpp_echo) $(src)components/HIPileupTool_load.cxx
	$(cpp_silent) $(cppcomp) -MMD -MP -MF $*.d -MQ $@ -o $@ $(use_pp_cppflags) $(HIPileupTool_pp_cppflags) $(lib_HIPileupTool_pp_cppflags) $(HIPileupTool_load_pp_cppflags) $(use_cppflags) $(HIPileupTool_cppflags) $(lib_HIPileupTool_cppflags) $(HIPileupTool_load_cppflags) $(HIPileupTool_load_cxx_cppflags) -I../src/components $(src)components/HIPileupTool_load.cxx
endif
endif

else
$(bin)HIPileupTool_dependencies.make : $(HIPileupTool_load_cxx_dependencies)

$(bin)HIPileupTool_dependencies.make : $(src)components/HIPileupTool_load.cxx

$(bin)$(binobj)HIPileupTool_load.o : $(HIPileupTool_load_cxx_dependencies)
	$(cpp_echo) $(src)components/HIPileupTool_load.cxx
	$(cpp_silent) $(cppcomp) -o $@ $(use_pp_cppflags) $(HIPileupTool_pp_cppflags) $(lib_HIPileupTool_pp_cppflags) $(HIPileupTool_load_pp_cppflags) $(use_cppflags) $(HIPileupTool_cppflags) $(lib_HIPileupTool_cppflags) $(HIPileupTool_load_cppflags) $(HIPileupTool_load_cxx_cppflags) -I../src/components $(src)components/HIPileupTool_load.cxx

endif

#-- end of cpp_library ------------------
#-- start of cpp_library -----------------

ifneq (-MMD -MP -MF $*.d -MQ $@,)

ifneq ($(MAKECMDGOALS),HIPileupToolclean)
ifneq ($(MAKECMDGOALS),uninstall)
-include $(bin)$(binobj)HIPileupTool_entries.d

$(bin)$(binobj)HIPileupTool_entries.d :

$(bin)$(binobj)HIPileupTool_entries.o : $(cmt_final_setup_HIPileupTool)

$(bin)$(binobj)HIPileupTool_entries.o : $(src)components/HIPileupTool_entries.cxx
	$(cpp_echo) $(src)components/HIPileupTool_entries.cxx
	$(cpp_silent) $(cppcomp) -MMD -MP -MF $*.d -MQ $@ -o $@ $(use_pp_cppflags) $(HIPileupTool_pp_cppflags) $(lib_HIPileupTool_pp_cppflags) $(HIPileupTool_entries_pp_cppflags) $(use_cppflags) $(HIPileupTool_cppflags) $(lib_HIPileupTool_cppflags) $(HIPileupTool_entries_cppflags) $(HIPileupTool_entries_cxx_cppflags) -I../src/components $(src)components/HIPileupTool_entries.cxx
endif
endif

else
$(bin)HIPileupTool_dependencies.make : $(HIPileupTool_entries_cxx_dependencies)

$(bin)HIPileupTool_dependencies.make : $(src)components/HIPileupTool_entries.cxx

$(bin)$(binobj)HIPileupTool_entries.o : $(HIPileupTool_entries_cxx_dependencies)
	$(cpp_echo) $(src)components/HIPileupTool_entries.cxx
	$(cpp_silent) $(cppcomp) -o $@ $(use_pp_cppflags) $(HIPileupTool_pp_cppflags) $(lib_HIPileupTool_pp_cppflags) $(HIPileupTool_entries_pp_cppflags) $(use_cppflags) $(HIPileupTool_cppflags) $(lib_HIPileupTool_cppflags) $(HIPileupTool_entries_cppflags) $(HIPileupTool_entries_cxx_cppflags) -I../src/components $(src)components/HIPileupTool_entries.cxx

endif

#-- end of cpp_library ------------------
#-- start of cleanup_header --------------

clean :: HIPileupToolclean ;
#	@cd .

ifndef PEDANTIC
.DEFAULT::
	$(echo) "(HIPileupTool.make) $@: No rule for such target" >&2
else
.DEFAULT::
	$(error PEDANTIC: $@: No rule for such target)
endif

HIPileupToolclean ::
#-- end of cleanup_header ---------------
#-- start of cleanup_library -------------
	$(cleanup_echo) library HIPileupTool
	-$(cleanup_silent) cd $(bin) && \rm -f $(library_prefix)HIPileupTool$(library_suffix).a $(library_prefix)HIPileupTool$(library_suffix).$(shlibsuffix) HIPileupTool.stamp HIPileupTool.shstamp
#-- end of cleanup_library ---------------
