file(REMOVE_RECURSE
  "sample2_unittest.pdb"
  "sample2_unittest"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/sample2_unittest.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
