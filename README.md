# lh-parson

This project attempts aims to apply the libhandler model of effects and handlers to parson, a robust JSON library written in C.

Parson: https://github.com/kgabis/parson

libhandler:  https://github.com/koka-lang/libhandler

# Working With this Library

## Requirements
If you wish to contribute or otherwise experiment with this library directly, you can use the existing project structure provided you have the following pre-requisites installed:

* Python installed
* Conan package manager installed from PIP
* CMake
* Any C compiler that works with CMake

If you do not wish to use this particular combination of tools, you must setup your own solution to using the projects together. One common approach is to use git-submodules and CMake with custom scripting.   

If these requirements prevent you from running this example, apologies.  Hopefully the library and example are trivial enough for you to use your preferred toolset.

## Build Instructions
1. Clone this repository
2. Run cmake (run the following commands from the cloned directory):
	`mkdir build && cd build && cmake .. -DCMAKE_BUILD_TYPE=Release && cmake --build .`
3. Run `bin/lh_parson_test`
