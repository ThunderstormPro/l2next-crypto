# Copyright (c) 2019 Alexei Gaidulean
# All rights reserved.
#
# Use of this source code is governed by a MIT-style license that
# can be found in the LICENSE file.

#
# App functions.
#

# Application executable common props.
function(set_app_executable_common_properties target)
	# Group targets in the same solution folder.
	set_target_properties(${target} PROPERTIES FOLDER "Test Applications")
	
	# Target linker language C++.
	set_target_properties(${target} PROPERTIES LINKER_LANGUAGE CXX)
	
	# Compiler flags.
	target_compile_options(${target} PRIVATE ${COMPILER_FLAGS_SHARED})
	target_compile_options(${target} PRIVATE $<$<CONFIG:Debug>:${COMPILER_FLAGS_DEBUG}>)
	target_compile_options(${target} PRIVATE $<$<CONFIG:Release>:${COMPILER_FLAGS_RELEASE}>)
	
	# Set binaries output path.
	if (PROJECT_BIN_PATH)
		set_target_properties(${target} PROPERTIES
			ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BIN_PATH}/${target}"
			LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BIN_PATH}/${target}"
			RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BIN_PATH}/${target}"
		)
	endif()
endfunction()

# Test application config reader.
function(set_test_app_properties)
	set_app_executable_common_properties(${PROJECT_NAME})
	
	# Includes.
	target_include_directories(${PROJECT_NAME} PUBLIC Public)
	
	# Set executable linker flags.
	if(EXE_LINKER_FLAGS)
		string(REPLACE ";" " " _LINK_FLAGS "${EXE_LINKER_FLAGS}")
		set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS ${_LINK_FLAGS})
	endif()
endfunction()
