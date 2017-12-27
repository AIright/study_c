file(REMOVE_RECURSE
  "CapitalsCountries.pdb"
  "CapitalsCountries"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/CapitalsCountries.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
