# Copyright (c) 2019 Alexei Gaidulean
# All rights reserved.
#
# Use of this source code is governed by a MIT-style license that
# can be found in the LICENSE file.

#
# Library functions.
#

# Check if add_library_targets() was called.
function(check_library name)
	if(NOT DEFINED name)
		message(FATAL_ERROR "Make sure to call add_library_targets() before setting any lib properties.")
	endif()
endfunction()

# Set common library properties.
function(set_common_library_props target)
	# Group targets in the same solution folder.
	set_target_properties(${target} PROPERTIES FOLDER Library)
	
	# Target linker language C++.
	set_target_properties(${target} PROPERTIES LINKER_LANGUAGE CXX)
	
	# Includes.
	target_include_directories(${target} PUBLIC
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Public>  
		$<INSTALL_INTERFACE:Public>
	)
	
	# Compiler flags.
	target_compile_options(${target} PRIVATE ${COMPILER_FLAGS_SHARED})
	target_compile_options(${target} PRIVATE $<$<CONFIG:Debug>:${COMPILER_FLAGS_DEBUG}>)
	target_compile_options(${target} PRIVATE $<$<CONFIG:Release>:${COMPILER_FLAGS_RELEASE}>)
	
	# Set binaries output path.
	if (PROJECT_BIN_PATH)
		set_target_properties(${target} PROPERTIES
			ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BIN_PATH}/${LIB_NAME}"
			LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BIN_PATH}/${LIB_NAME}"
			RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BIN_PATH}/${LIB_NAME}"
		)
	endif()
endfunction()

# Set static library properties.
function(set_static_library_properties)
	check_library(${LIB_NAME})
	set_common_library_props(${LIB_NAME})
	
	# Link third party dependencies. 
	link_external_dependency(zlib ${LIB_NAME})
endfunction()
