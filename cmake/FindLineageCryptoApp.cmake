# Copyright (c) 2019 Alexei Gaidulean
# All rights reserved.
#
# Use of this source code is governed by a MIT-style license that
# can be found in the LICENSE file.

# Load guard.
check_bootstrap_step()

set(PROJECT_NAME LineageCryptoApp)

# Include shared utility scripts.
include(App/Variables)
include(App/Verbiage)
include(App/Macros)
include(App/Functions)

# Add target project to solution.
add_project_to_solution(${PROJECT_NAME})
