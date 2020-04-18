# Copyright (c) 2019 Alexei Gaidulean
# All rights reserved.
#
# Use of this source code is governed by a MIT-style license that
# can be found in the LICENSE file.

# Index group.
add_source_group(Source
	"Public/L2NextCryptoApp.h"
	"Private/L2NextCryptoApp.cpp"
)

# Config reader.
add_source_group(Source.ConfigReader
	"Public/ConfigReader/ConfigReader.h"
	"Private/ConfigReader/ConfigReader.cpp"
)

# Config reader struct.
add_source_group(Source.ConfigReader.Struct
	"Public/ConfigReader/Struct/ConfigBase.h"
	"Private/ConfigReader/Struct/ConfigBase.cpp"
	"Public/ConfigReader/Struct/ConfigPaths.h"
	"Private/ConfigReader/Struct/ConfigPaths.cpp"
)

# Utils.
add_source_group(Source.Utils
	"Public/Utils/FileHelper.h"
	"Private/Utils/FileHelper.cpp"
)

add_source_group(Source.PrecompiledHeaders
	"Public/pch.h"
	"Private/pch.cpp"
)
