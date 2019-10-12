# Copyright (c) 2019 Alexei Gaidulean
# All rights reserved.
#
# Use of this source code is governed by a MIT-style license that
# can be found in the LICENSE file.

# Project metadata.
project(${PROJECT_NAME} VERSION 1.0.0)

# Add sources.
include(Library/Sources)

# Enqueue mpir for download.
include("ThirdParty/mpir" REQUIRED)

# Enqueue zlib for download.
include("ThirdParty/zlib" REQUIRED)

# Adds a static & dynamic library target.
add_library_targets(${PROJECT_NAME} "${L2NextCrypto_SOURCES}")

# Set library properties.
set_static_library_properties()

install(TARGETS ${PROJECT_NAME}
        CONFIGURATIONS Debug
        RUNTIME DESTINATION Debug/bin)
install(TARGETS ${PROJECT_NAME}
        CONFIGURATIONS Release
        RUNTIME DESTINATION Release/bin)
