file(REMOVE_RECURSE
  "../x86_64-slc6-gcc62-opt/include/AnaCumu"
  "../x86_64-slc6-gcc62-opt/python/AnaCumu/__init__.py"
  "../x86_64-slc6-gcc62-opt/jobOptions/AnaCumu/AnaCumuAlgJobOptions.py"
  "../x86_64-slc6-gcc62-opt/include/AnaCumu"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/AnaCumuHeaderInstall.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
