file(REMOVE_RECURSE
  "../x86_64-slc6-gcc62-opt/include/XeXeCent"
  "../x86_64-slc6-gcc62-opt/python/XeXeCent/__init__.py"
  "../x86_64-slc6-gcc62-opt/jobOptions/XeXeCent/XeXeCentAlgJobOptions.py"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/Package_XeXeCent_tests.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
