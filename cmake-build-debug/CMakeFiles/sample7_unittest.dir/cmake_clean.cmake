file(REMOVE_RECURSE
  "sample7_unittest.pdb"
  "sample7_unittest"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/sample7_unittest.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
