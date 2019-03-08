#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "WorkDir::XeXeCentLib" for configuration "RelWithDebInfo"
set_property(TARGET WorkDir::XeXeCentLib APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(WorkDir::XeXeCentLib PROPERTIES
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/libXeXeCentLib.so"
  IMPORTED_SONAME_RELWITHDEBINFO "libXeXeCentLib.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS WorkDir::XeXeCentLib )
list(APPEND _IMPORT_CHECK_FILES_FOR_WorkDir::XeXeCentLib "${_IMPORT_PREFIX}/lib/libXeXeCentLib.so" )

# Import target "WorkDir::XeXeCent" for configuration "RelWithDebInfo"
set_property(TARGET WorkDir::XeXeCent APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(WorkDir::XeXeCent PROPERTIES
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/libXeXeCent.so"
  IMPORTED_NO_SONAME_RELWITHDEBINFO "TRUE"
  )

list(APPEND _IMPORT_CHECK_TARGETS WorkDir::XeXeCent )
list(APPEND _IMPORT_CHECK_FILES_FOR_WorkDir::XeXeCent "${_IMPORT_PREFIX}/lib/libXeXeCent.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
