project(lh_parson)
cmake_minimum_required(VERSION 3.7)

include(conan_include.cmake)

add_library(lh_parson
	lh_parson.c
)

target_include_directories(lh_parson
	PUBLIC
		${PROJECT_SOURCE_DIR}
)

target_link_libraries(lh_parson
	CONAN_PKG::libhandler
	CONAN_PKG::Parson
)


add_executable(lh_parson_test
	lh_parson_test.c
)

target_link_libraries(lh_parson_test
	lh_parson
	CONAN_PKG::libhandler
	CONAN_PKG::Parson
)

# https://cmake.org/cmake/help/v3.4/command/add_test.html 
# add_test(<name> <command> [<arg>...])
enable_testing()
add_test(NAME lh_parson_test COMMAND lh_parson_test)
