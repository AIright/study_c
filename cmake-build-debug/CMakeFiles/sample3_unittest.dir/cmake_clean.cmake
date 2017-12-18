file(REMOVE_RECURSE
  "sample3_unittest.pdb"
  "sample3_unittest"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/sample3_unittest.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
