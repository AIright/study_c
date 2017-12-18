file(REMOVE_RECURSE
  "sample6_unittest.pdb"
  "sample6_unittest"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/sample6_unittest.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
