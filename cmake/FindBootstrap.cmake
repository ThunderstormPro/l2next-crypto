# Copyright (c) 2019 Alexei Gaidulean
# All rights reserved.
#
# Use of this source code is governed by a MIT-style license that
# can be found in the LICENSE file.

#
# This file is the project's CMake configuration entry point and should be loaded
# using `find_package(Bootstrap REQUIRED)`.
#

# Find the project root directory.
set(_ROOT_PATH "")
if (ROOT_PATH AND IS_DIRECTORY "${ROOT_PATH}")
	set(_ROOT_PATH "${ROOT_PATH}")
	set(_ROOT_PATH_REQUIRED 1)
endif()

# Find the project CMake bootstrap module directory requirement.
set(_CMAKE_MODULE_PATH "")
if (NOT DEFINED CMAKE_MODULE_PATH)
	message(FATAL_ERROR "CMAKE_MODULE_PATH is not defined or is not valid.")
else()
	# Add subfolders.
	list(APPEND CMAKE_MODULE_PATH "${ROOT_PATH}/cmake/App")
	list(APPEND CMAKE_MODULE_PATH "${ROOT_PATH}/cmake/Library")
	list(APPEND CMAKE_MODULE_PATH "${ROOT_PATH}/cmake/Shared")
	list(APPEND CMAKE_MODULE_PATH "${ROOT_PATH}/cmake/ThirdParty")
endif()

# Check if all subdirectories used for CMake bootstrap are present.
foreach(dir ${CMAKE_MODULE_PATH})
	if (IS_DIRECTORY ${dir})
		list(APPEND _CMAKE_MODULE_PATH dir)
		set(_CMAKE_MODULE_PATH_REQUIRED 1)
	else()
		unset(_CMAKE_MODULE_PATH_REQUIRED)
	endif()
endforeach()

# Check required directories, throw error if not found.
if (NOT DEFINED _ROOT_PATH_REQUIRED)
	message(FATAL_ERROR "${MSG_INVALID_ROOT_PATH} ${MSG_ERROR_ROOT_PATHS}")
endif()

if (NOT DEFINED _CMAKE_MODULE_PATH_REQUIRED)
	message(FATAL_ERROR "${MSG_INVALID_CMAKE_PATH} ${MSG_ERROR_ROOT_PATHS}")
endif()

# Include shared utility scripts.
include(Shared/Variables)
include(Shared/Verbiage)
include(Shared/Macros)
include(Shared/Functions)

# Include CMake modules required for project generation.
include(CheckIncludeFile)
include(CheckIncludeFiles)
include(ExternalProject)

# Prevent further solution generation if launched not on Windows OS
if(NOT OS_WINDOWS)
	message(FATAL_ERROR "Only Windows OS is supported for solution generation at the moment.")
endif()

# Use folders in the resulting project files.
set_property(GLOBAL PROPERTY OS_FOLDERS ON)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Add target projects to solution.
message("[Projects]")

# Load shared & static library package.
find_package(LineageCrypto REQUIRED)

# Load test application package.
find_package(LineageCryptoApp REQUIRED)
