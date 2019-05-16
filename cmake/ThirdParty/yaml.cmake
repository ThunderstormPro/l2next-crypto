# Copyright (c) 2019 Alexei Gaidulean
# All rights reserved.
#
# Use of this source code is governed by a MIT-style license that
# can be found in the LICENSE file.

# Set library name.
set(LIBRARY_NAME yaml)

# Set library URL.
set(LIBRARY_URL https://github.com/jbeder/yaml-cpp/archive/master.zip)

# Set library URL hash.
set(LIBRARY_URL_HASH 974bdcd5bf916735d97311db525ef3e7)

# Set custom CMake args.
set(LIBRARY_CMAKE_ARGS -DYAML_CPP_BUILD_TESTS=OFF)

# Set library static name.
set(LIBRARY_STATIC_NAME libyaml-cppmdd.lib)

# Enqueue to download, build & install.
enqueue_external_dependency()
