file(REMOVE_RECURSE
  "sample10_unittest.pdb"
  "sample10_unittest"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/sample10_unittest.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
