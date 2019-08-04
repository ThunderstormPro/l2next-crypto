# Copyright (c) 2019 Alexei Gaidulean
# All rights reserved.
#
# Use of this source code is governed by a MIT-style license that
# can be found in the LICENSE file.

# Library specific dependencies required for test app.
ExternalProject_Get_property(zlib INSTALL_DIR)
add_resources(Root
	"${INSTALL_DIR}/bin/zlibd.dll"
)

# Application specific dependencies.
add_resources(Config
	"${PROJECT_RSRC_PATH}/${target}/config.yaml"
)
