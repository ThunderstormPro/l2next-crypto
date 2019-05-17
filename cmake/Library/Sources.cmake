# Copyright (c) 2019 Alexei Gaidulean
# All rights reserved.
#
# Use of this source code is governed by a MIT-style license that
# can be found in the LICENSE file.

# Index group.
add_source_group(Source
	"Public/LineageCrypto.h"
	"Private/LineageCrypto.cpp"
)

# Task runner.
add_source_group(Source.TaskRunner
	"Public/TaskRunner/TaskRunner.h"
	"Private/TaskRunner/TaskRunner.cpp"
)

add_source_group(Source.TaskRunner.Tasks
	"Public/TaskRunner/Tasks/AsyncTask.h"
	"Private/TaskRunner/Tasks/AsyncTask.cpp"
)

add_source_group(Source.TaskRunner.Commands
	"Public/TaskRunner/Commands/Encrypt.h"
	"Private/TaskRunner/Commands/Encrypt.cpp"
	"Public/TaskRunner/Commands/Decrypt.h"
	"Private/TaskRunner/Commands/Decrypt.cpp"
)

add_source_group(Source.TaskRunner.Interfaces
	"Public/TaskRunner/Interfaces/Task.h"
	"Public/TaskRunner/Interfaces/Command.h"
)