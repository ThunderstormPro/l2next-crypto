# Copyright (c) 2019 Alexei Gaidulean
# All rights reserved.
#
# Use of this source code is governed by a MIT-style license that
# can be found in the LICENSE file.

# Must be loaded via FindLineageCrypto.cmake.
if(NOT DEFINED _ROOT_PATH_REQUIRED OR NOT DEFINED _CMAKE_MODULE_PATH_REQUIRED)
  message(FATAL_ERROR "Use find_package(LineageCrypto REQUIRED) to load this file.")
endif()

#
# Library variables.
#

# Static library postfix.
set(LIB_STATIC_POSTFIX "_Static")
