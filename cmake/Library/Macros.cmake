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
	set(LIB_SHARED_NAME "${name}")
	set(LIB_STATIC_NAME "${name}${LIB_STATIC_POSTFIX}")

	# Add shared library target.
	add_library(${LIB_SHARED_NAME} SHARED ${sources})
	
	# Add static libary target.
	add_library(${LIB_STATIC_NAME} STATIC ${sources})
endmacro()
