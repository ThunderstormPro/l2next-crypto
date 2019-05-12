# Copyright (c) 2019 Alexei Gaidulean
# All rights reserved.
#
# Use of this source code is governed by a MIT-style license that
# can be found in the LICENSE file.

# Platform-specific linker flags.
list(APPEND EXE_LINKER_FLAGS
	/MANIFEST:NO        # No default manifest (see ADD_WINDOWS_MANIFEST macro usage)
	/LARGEADDRESSAWARE  # Allow 32-bit processes to access 3GB of RAM
	/SUBSYSTEM:CONSOLE  # Build this as a console application
	)
