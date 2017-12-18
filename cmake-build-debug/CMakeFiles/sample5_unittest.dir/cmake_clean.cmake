file(REMOVE_RECURSE
  "sample5_unittest.pdb"
  "sample5_unittest"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/sample5_unittest.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
