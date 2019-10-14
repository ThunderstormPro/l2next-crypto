# Copyright (c) 2019 Alexei Gaidulean
# All rights reserved.
#
# Use of this source code is governed by a MIT-style license that
# can be found in the LICENSE file.

# Project metadata.
project(${PROJECT_NAME} VERSION 1.0.0)

# Add sources.
include(Library/Sources)

# Enqueue zlib for download.
include("ThirdParty/zlib" REQUIRED)

# Adds a static & dynamic library target.
add_library_targets(${PROJECT_NAME} "${L2NextCrypto_SOURCES}")

# Set library properties.
set_static_library_properties()

# Install export.
if (L2NEXT_CPP_INSTALL)
	export_install_configs()
endif()
