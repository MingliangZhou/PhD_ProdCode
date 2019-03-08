file(REMOVE_RECURSE
  "../x86_64-slc6-gcc62-opt/include/AthProd"
  "../x86_64-slc6-gcc62-opt/python/AthProd/__init__.py"
  "../x86_64-slc6-gcc62-opt/jobOptions/AthProd/AthProdAlgJobOptions.py"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/AthProdPythonBytecodeInstall.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
