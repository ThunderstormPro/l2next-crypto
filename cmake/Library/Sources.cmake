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
	"Public/TaskRunner/Tasks/BaseTask.h"
	"Private/TaskRunner/Tasks/BaseTask.cpp"
	"Public/TaskRunner/Tasks/AsyncTask.h"
	"Private/TaskRunner/Tasks/AsyncTask.cpp"
)

add_source_group(Source.TaskRunner.Commands
	"Public/TaskRunner/Commands/BaseCommand.h"
	"Private/TaskRunner/Commands/BaseCommand.cpp"
	"Public/TaskRunner/Commands/Encrypt.h"
	"Private/TaskRunner/Commands/Encrypt.cpp"
	"Public/TaskRunner/Commands/Decrypt.h"
	"Private/TaskRunner/Commands/Decrypt.cpp"
)

add_source_group(Source.TaskRunner.Interfaces
	"Public/TaskRunner/Interfaces/Task.h"
)

# Crypto.
add_source_group(Source.Crypto
	"Public/Crypto/Crypto.h"
	"Private/Crypto/Crypto.cpp"
)

# Crypto algorithms.
add_source_group(Source.Crypto.Algorithms.Base
	"Public/Crypto/Algorithms/Base/AlgorithmBase.h"
	"Private/Crypto/Algorithms/Base/AlgorithmBase.cpp"
)

add_source_group(Source.Crypto.Algorithms.41x
	"Public/Crypto/Algorithms/41x/Dec41x.h"
	"Private/Crypto/Algorithms/41x/Dec41x.cpp"
	"Public/Crypto/Algorithms/41x/Enc41x.h"
	"Private/Crypto/Algorithms/41x/Enc41x.cpp"
)

# Common.
add_source_group(Source.Shared.Structs
	"Public/Shared/Structs/LineageFileSchema.h"
)

add_source_group(Source.Shared.Enums
	"Public/Shared/Enums/CryptoCommands.h"
)
