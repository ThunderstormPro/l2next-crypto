# Copyright (c) 2019 Alexei Gaidulean
# All rights reserved.
#
# Use of this source code is governed by a MIT-style license that
# can be found in the LICENSE file.

# Set library name.
set(LIBRARY_NAME mpir)

# Set library URL.
set(LIBRARY_URL https://github.com/chfast/mpir/archive/cmake.tar.gz)

# Set library URL hash.
set(LIBRARY_URL_HASH 47333027cb201493a598513bbbb17072)

# Set custom CMake args.
set(LIBRARY_CMAKE_ARGS -DMPIR_GMP=On)

# Set library static name.
set(LIBRARY_STATIC_NAME mpir.lib)

# Enqueue to download, build & install.
enqueue_external_dependency()