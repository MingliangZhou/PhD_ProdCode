#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "WorkDir::AthProdLib" for configuration "RelWithDebInfo"
set_property(TARGET WorkDir::AthProdLib APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(WorkDir::AthProdLib PROPERTIES
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/libAthProdLib.so"
  IMPORTED_SONAME_RELWITHDEBINFO "libAthProdLib.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS WorkDir::AthProdLib )
list(APPEND _IMPORT_CHECK_FILES_FOR_WorkDir::AthProdLib "${_IMPORT_PREFIX}/lib/libAthProdLib.so" )

# Import target "WorkDir::AthProd" for configuration "RelWithDebInfo"
set_property(TARGET WorkDir::AthProd APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(WorkDir::AthProd PROPERTIES
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/libAthProd.so"
  IMPORTED_NO_SONAME_RELWITHDEBINFO "TRUE"
  )

list(APPEND _IMPORT_CHECK_TARGETS WorkDir::AthProd )
list(APPEND _IMPORT_CHECK_FILES_FOR_WorkDir::AthProd "${_IMPORT_PREFIX}/lib/libAthProd.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
