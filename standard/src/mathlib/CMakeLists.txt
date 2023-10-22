add_library(mathlib STATIC)

set_target_properties(mathlib PROPERTIES LIBRARY_OUTPUT_NAME "math.lib")

target_sources(
	mathlib
	PRIVATE
		mathlib.cpp
)