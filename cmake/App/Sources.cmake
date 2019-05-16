# Copyright (c) 2019 Alexei Gaidulean
# All rights reserved.
#
# Use of this source code is governed by a MIT-style license that
# can be found in the LICENSE file.




# Index group.
add_source_group(Sources
	"LineageCryptoApp.h"
	"LineageCryptoApp.cpp"
)

# Config reader.
add_source_group(Sources.ConfigReader
	"ConfigReader/ConfigReader.h"
	"ConfigReader/ConfigReader.cpp"
)

# Config reader struct.
add_source_group(Sources.ConfigReader.Struct
	"ConfigReader/Struct/ConfigBase.h"
	"ConfigReader/Struct/ConfigPaths.h"
)

add_source_group(PrecompiledHeaders
	"pch.h"
	"pch.cpp"
)
