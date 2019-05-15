# Copyright (c) 2019 Alexei Gaidulean
# All rights reserved.
#
# Use of this source code is governed by a MIT-style license that
# can be found in the LICENSE file.

# Project metadata.
project(${PROJECT_NAME} VERSION 1.0.0)

# Add sources.
include(App/Sources)

# Add executable target.
add_executable(${PROJECT_NAME} WIN32 ${LineageCryptoApp_SOURCES})

# Set test app properties.
set_test_app_properties()

# Add project dependencies.
add_dependencies(${PROJECT_NAME} LineageCrypto_Static)
target_link_libraries(${PROJECT_NAME} PUBLIC LineageCrypto_Static)
