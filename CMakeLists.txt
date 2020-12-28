# Copyright (c) 2020 Alexei Gaidulean
# All rights reserved.
#
# Use of this source code is governed by a MIT-style license that
# can be found in the LICENSE file.
#

# CMake version policy
cmake_minimum_required(VERSION 3.12)

# Dependency on vcpkg
if(DEFINED ENV{VCPKG_ROOT} AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
  set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake"
      CACHE STRING "")
endif()

# Solution name
project(L2NextCrypto VERSION 1.1.0 DESCRIPTION "Lineage2 Encrypt/Decrypt library")

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Only generate Debug and Release configuration types
set(CMAKE_CONFIGURATION_TYPES Debug Release)

# Setup paths
set(SOLUTION_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(SOURCE_DIR ${SOLUTION_DIR}/Source)
set(BINARIES_DIR ${SOLUTION_DIR}/Binaries)
set(RESOURCES_DIR ${SOLUTION_DIR}/Resources)
set(APP_RESOURCES "${RESOURCES_DIR}/L2NextCryptoApp")
set(APP_BINARIES_DIR "${BINARIES_DIR}/L2NextCryptoApp/${CMAKE_VS_PLATFORM_NAME}/$<CONFIG>")
set(LIB_BINARIES_DIR "${BINARIES_DIR}/L2NextCrypto/${CMAKE_VS_PLATFORM_NAME}/$<CONFIG>")

# Load projects configuration
add_subdirectory(${SOURCE_DIR}/L2NextCrypto)
add_subdirectory(${SOURCE_DIR}/L2NextCryptoApp)

# Solution structure
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER CMake)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT L2NextCryptoApp)

# Compile options
list(APPEND COMPILER_FLAGS_SHARED
	/MP			# Multiprocess compilation
	/Gy			# Enable function-level linking
	/GR			# Enable run-time type information
	/W4			# Warning level 4
	/wd4100		# Ignore "unreferenced formal parameter" warning
	/wd4127		# Ignore "conditional expression is constant" warning
	/wd4244		# Ignore "conversion possible loss of data" warning
	/wd4481		# Ignore "nonstandard extension used: override" warning
	/wd4512		# Ignore "assignment operator could not be generated" warning
	/wd4701		# Ignore "potentially uninitialized local variable" warning
	/wd4702		# Ignore "unreachable code" warning
	/wd4996		# Ignore "function or variable may be unsafe" warning
	/wd4146		# Ignore GMP internal warnings
	/wd4267		# Ignore GMP internal warnings
	/wd4703		# Ignore GMP internal warnings
	/wd4189		# Ignore GMP internal warnings
)

target_compile_options(L2NextCrypto PRIVATE ${COMPILER_FLAGS_SHARED})
target_compile_options(L2NextCryptoApp PRIVATE ${COMPILER_FLAGS_SHARED})