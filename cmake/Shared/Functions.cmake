# Copyright (c) 2019 Alexei Gaidulean
# All rights reserved.
#
# Use of this source code is governed by a MIT-style license that
# can be found in the LICENSE file.

#
# Shared functions.
#

# Add project to solution.
function(add_project_to_solution target)
	set(_PROJECT_SRC_PATH "${PROJECT_SRC_PATH}/${target}")
	set(_PROJECT_BUILD_PATH "${PROJECT_BUILD_PATH}/${target}")
	
	if(NOT IS_DIRECTORY ${_PROJECT_SRC_PATH})
		message(FATAL_ERROR "Failed to add project : [${target}] to solution. Source directory is missing.")
	endif()
	
	message("Adding project to solution: [${target}]")
	add_subdirectory(${_PROJECT_SRC_PATH} "${_PROJECT_BUILD_PATH}")
	
	unset(_PROJECT_SRC_PATH)
	unset(_PROJECT_BUILD_PATH)
endfunction()
