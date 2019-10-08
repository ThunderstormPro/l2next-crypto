# Copyright (c) 2019 Alexei Gaidulean
# All rights reserved.
#
# Use of this source code is governed by a MIT-style license that
# can be found in the LICENSE file.

#
# Library macros.
#

# Utility function to add both shared & static library targets.
macro(add_library_targets name sources)
	# Set global name variables for internal use.
	set(LIB_NAME "${name}")

	# Add static libary target.
	add_library(${LIB_NAME} STATIC ${sources})
endmacro()
