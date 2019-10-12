# Copyright (c) 2019 Alexei Gaidulean
# All rights reserved.
#
# Use of this source code is governed by a MIT-style license that
# can be found in the LICENSE file.
#

#
# Global setup.
#

# CMake version policy
cmake_minimum_required(VERSION 3.1...3.14)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
	cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

# Project name.
project(L2NextCrypto)

# Only generate Debug and Release configuration types.
set(CMAKE_CONFIGURATION_TYPES Debug Release)

# Setup cmake bootstrap paths.
set(ROOT_PATH "${CMAKE_CURRENT_SOURCE_DIR}")
set(CMAKE_MODULE_PATH "${ROOT_PATH}/cmake")

#
# Load configuration.
#

# Execute FindL2NextCrypto.cmake which must exist in CMAKE_MODULE_PATH.
find_package(Bootstrap REQUIRED)