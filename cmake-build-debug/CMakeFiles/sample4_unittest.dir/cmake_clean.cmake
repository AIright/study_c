file(REMOVE_RECURSE
  "sample4_unittest.pdb"
  "sample4_unittest"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/sample4_unittest.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
