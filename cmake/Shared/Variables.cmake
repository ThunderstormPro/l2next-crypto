# Copyright (c) 2019 Alexei Gaidulean
# All rights reserved.
#
# Use of this source code is governed by a MIT-style license that
# can be found in the LICENSE file.

#
# General.
#

# Directory where all source code for each module will be placed.
set(PROJECT_SRC_PATH "${_ROOT_PATH}/Source")

# Directory where all resources for each module will be placed.
set(PROJECT_RSRC_PATH "${_ROOT_PATH}/Resources")

# Binaries ouput directory.
set(PROJECT_BIN_PATH "${_ROOT_PATH}/Binaries")

# CMake projects build ouput directory.
set(PROJECT_BUILD_PATH "${_ROOT_PATH}/Build")

# Third party dependencies directory.
set(THIRD_PARTY_LIBS_PATH "${_ROOT_PATH}/ThirdParty")

#
# Shared configuration.
#

# Determine the platform.
if("${CMAKE_SYSTEM_NAME}" STREQUAL "Darwin")
  set(OS_MACOSX 1)
  set(OS_POSIX 1)
elseif("${CMAKE_SYSTEM_NAME}" STREQUAL "Linux")
  set(OS_LINUX 1)
  set(OS_POSIX 1)
elseif("${CMAKE_SYSTEM_NAME}" STREQUAL "Windows")
  set(OS_WINDOWS 1)
endif()


#
# Windows configuration.
#

# Platform-specific compiler flags.
list(APPEND COMPILER_FLAGS_SHARED
	/MP			# Multiprocess compilation
	/Gy			# Enable function-level linking
	/GR			# Enable run-time type information
	/W4			# Warning level 4
	/WX			# Treat warnings as errors
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

list(APPEND COMPILER_FLAGS_DEBUG
	/RTC1         # Disable optimizations
	/Od           # Enable basic run-time checks
	)

list(APPEND COMPILER_FLAGS_RELEASE
	/O2           # Optimize for maximum speed
	/Ob2          # Inline any suitable function
	/GF           # Enable string pooling
	)
	