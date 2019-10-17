# Copyright (c) 2019 Alexei Gaidulean
# All rights reserved.
#
# Use of this source code is governed by a MIT-style license that
# can be found in the LICENSE file.

# Set library name.
set(LIBRARY_NAME zlib)

# Set library URL.
set(LIBRARY_URL https://www.zlib.net/zlib-1.2.11.tar.gz)

# Set library URL hash.
set(LIBRARY_URL_HASH 33f4b3034501a3cc2e8bc8d62e70fecc)

# Set debug library static name.
set(LIBRARY_STATIC_NAME_DEBUG zlibstaticd.lib)

# Set debug library static name.
set(LIBRARY_STATIC_NAME_RELEASE zlibstatic.lib)

# Enqueue to download, build & install.
enqueue_external_dependency()
