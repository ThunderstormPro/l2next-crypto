# Copyright (c) 2020 Alexei Gaidulean
# All rights reserved.
#
# Use of this source code is governed by a MIT-style license that
# can be found in the LICENSE file.

# List sources
file(GLOB_RECURSE SOURCE_LIST CONFIGURE_DEPENDS "Source/*.cpp" "Source/*.h")

# Add project and sources
add_executable(L2NextCryptoApp ${SOURCE_LIST})
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_LIST})

# Link libraries
target_include_directories(L2NextCryptoApp PRIVATE ${CMAKE_CURRENT_LIST_DIR}/Source)
target_link_libraries(L2NextCryptoApp PRIVATE L2NextCrypto)

# Add dependencies
find_package(yaml-cpp CONFIG REQUIRED)
target_link_libraries(L2NextCryptoApp PRIVATE yaml-cpp)

# Setup build paths
set_target_properties(L2NextCryptoApp
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${APP_BINARIES_DIR}
    LIBRARY_OUTPUT_DIRECTORY ${APP_BINARIES_DIR}
    RUNTIME_OUTPUT_DIRECTORY ${APP_BINARIES_DIR}
)

# Add post build events
# Copy config file into /config directory
add_custom_command(TARGET L2NextCryptoApp POST_BUILD COMMAND ${CMAKE_COMMAND} -E make_directory ${APP_BINARIES_DIR}/config)
add_custom_command(TARGET L2NextCryptoApp POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${APP_RESOURCES}/config.yaml ${APP_BINARIES_DIR}/config)

# Copy library dll
add_custom_command(TARGET L2NextCryptoApp POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${LIB_BINARIES_DIR}/L2NextCrypto.dll ${APP_BINARIES_DIR})

# Copy library debug files
list(APPEND LIB_DEBUG_BINARIES
    ${LIB_BINARIES_DIR}/L2NextCrypto.exp
    ${LIB_BINARIES_DIR}/L2NextCrypto.ilk
    ${LIB_BINARIES_DIR}/L2NextCrypto.pdb
)

set(ONLY_DEBUG $<NOT:$<CONFIG:DEBUG>>)
add_custom_command(TARGET L2NextCryptoApp POST_BUILD
    COMMAND "${CMAKE_COMMAND}" -E
    $<${ONLY_DEBUG}:echo>
    $<${ONLY_DEBUG}:"">
    copy_if_different ${LIB_DEBUG_BINARIES} ${APP_BINARIES_DIR}
)