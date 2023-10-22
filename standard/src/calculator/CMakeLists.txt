add_executable(calculator)

set_target_properties(calculator PROPERTIES OUTPUT_NAME "calc")

target_link_libraries(
	calculator
	PRIVATE
		mathlib
)

target_sources(
	calculator
	PRIVATE
		calculator.cpp
)