# Copyright (c) 2019 Alexei Gaidulean
# All rights reserved.
#
# Use of this source code is governed by a MIT-style license that
# can be found in the LICENSE file.

# Set library name.
set(LIBRARY_NAME yaml)

# Set library URL.
set(LIBRARY_URL https://github.com/jbeder/yaml-cpp/archive/yaml-cpp-0.6.3.zip)

# Set library URL hash.
set(LIBRARY_URL_HASH 8da85c6d513cfd233ffe957c1da497dd)

# Set custom CMake args.
set(LIBRARY_CMAKE_ARGS -DYAML_CPP_BUILD_TESTS=OFF -DYAML_BUILD_SHARED_LIBS=OFF -DBUILD_SHARED_LIBS=OFF)

# Debug lib.
set(LIBRARY_STATIC_NAME_DEBUG libyaml-cppmdd.lib)

# Release lib.
set(LIBRARY_STATIC_NAME_RELEASE libyaml-cppmd.lib)

# Enqueue to download, build & install.
enqueue_external_dependency()
