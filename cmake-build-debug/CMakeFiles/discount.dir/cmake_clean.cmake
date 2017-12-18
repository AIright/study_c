file(REMOVE_RECURSE
  "discount.pdb"
  "discount"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/discount.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
