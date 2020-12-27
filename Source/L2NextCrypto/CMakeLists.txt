# Copyright (c) 2020 Alexei Gaidulean
# All rights reserved.
#
# Use of this source code is governed by a MIT-style license that
# can be found in the LICENSE file.

# Set library specific properties
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS True)

# List sources
file(GLOB_RECURSE PUBLIC_SOURCE_LIST "Public/*.h")
file(GLOB_RECURSE PRIVATE_SOURCE_LIST "Private/*.cpp" "Private/*.h")

# Add project and sources
add_library(L2NextCrypto SHARED ${PUBLIC_SOURCE_LIST} ${PRIVATE_SOURCE_LIST})
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${PUBLIC_SOURCE_LIST} ${PRIVATE_SOURCE_LIST})

# Setup project version and includes
set_target_properties(L2NextCrypto PROPERTIES VERSION ${PROJECT_VERSION})
target_include_directories(L2NextCrypto PUBLIC ${CMAKE_CURRENT_LIST_DIR}/Public)
target_include_directories(L2NextCrypto PRIVATE ${CMAKE_CURRENT_LIST_DIR}/Private)

# Add dependencies
find_package(ZLIB REQUIRED)
target_link_libraries(L2NextCrypto PRIVATE ZLIB::ZLIB)

find_path(MPIR_INCLUDE_DIR mpir.h)
find_library(MPIR_LIBRARY mpir)
target_include_directories(L2NextCrypto PRIVATE ${MPIR_INCLUDE_DIR})
target_link_libraries(L2NextCrypto PRIVATE ${MPIR_LIBRARY})

# Setup build paths
set_target_properties(L2NextCrypto
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${LIB_BINARIES_DIR}
    LIBRARY_OUTPUT_DIRECTORY ${LIB_BINARIES_DIR}
    RUNTIME_OUTPUT_DIRECTORY ${LIB_BINARIES_DIR}
)

# Setup exports
set_target_properties(L2NextCrypto
    PROPERTIES
    PUBLIC_HEADER ${PUBLIC_SOURCE_LIST}
)

install (TARGETS L2NextCrypto
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    PUBLIC_HEADER DESTINATION include
)