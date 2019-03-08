file(REMOVE_RECURSE
  "../x86_64-slc6-gcc62-opt/include/XeXeCent"
  "../x86_64-slc6-gcc62-opt/python/XeXeCent/__init__.py"
  "../x86_64-slc6-gcc62-opt/jobOptions/XeXeCent/XeXeCentAlgJobOptions.py"
  "../x86_64-slc6-gcc62-opt/include/XeXeCent"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/XeXeCentHeaderInstall.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
