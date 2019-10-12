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

# Install export.
if (LINEGE_NEXT_CPP_INSTALL)
install(TARGETS ${PROJECT_NAME}
		EXPORT ${PROJECT_NAME}
		RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
		LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
		ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(DIRECTORY ${PROJECT_SOURCE_DIR}/Public/
		DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
		FILES_MATCHING PATTERN "*.h")
endif()
