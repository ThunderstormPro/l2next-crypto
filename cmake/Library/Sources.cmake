# Copyright (c) 2019 Alexei Gaidulean
# All rights reserved.
#
# Use of this source code is governed by a MIT-style license that
# can be found in the LICENSE file.

# Index group.
add_source_group(Source
	"Public/L2NextCrypto.h"
	"Private/L2NextCrypto.cpp"
)

# Pre-compiled libs.
add_source_group(Libs
	"Public/Libs/mini-gmp.h"
	"Private/Libs/mini-gmp.c"
)

# Crypto validators.
add_source_group(Source.Crypto.Validators.HeaderValidator
	"Public/Crypto/Validators/HeaderValidator/HeaderValidator.h"
	"Private/Crypto/Validators/HeaderValidator/HeaderValidator.cpp"
)

add_source_group(Source.Crypto.Validators.HeaderValidator.Duplex
	"Public/Crypto/Validators/HeaderValidator/Duplex/HeaderValidatorDuplex.h"
	"Private/Crypto/Validators/HeaderValidator/Duplex/HeaderValidatorDuplex.cpp"
)

add_source_group(Source.Crypto.Validators.HeaderValidator.Events
	"Public/Crypto/Validators/HeaderValidator/Events/OnValidationPassed.h"
	"Public/Crypto/Validators/HeaderValidator/Events/OnValidationFailed.h"
)

# Crypto structs.
add_source_group(Source.Crypto.Validators.HeaderValidator.Structs
	"Public/Crypto/Validators/HeaderValidator/Structs/ValidationResult.h"
)

# Crypto enums.
add_source_group(Source.Crypto.Enums
	"Public/Crypto/Enums/CryptType.h"
	"Public/Crypto/Enums/HeaderVersion.h"
	"Public/Crypto/Enums/DecryptErrorStatus.h"
	"Public/Crypto/Enums/EncryptErrorStatus.h"
)

# Crypto structs.
add_source_group(Source.Crypto.Structs
	"Public/Crypto/Structs/DecryptResult.h"
	"Public/Crypto/Structs/EncryptResult.h"
)

# Crypto algorithms.
add_source_group(Source.Crypto.Algorithms
	"Public/Crypto/Algorithms/AlgorithmRegistry.h"
	"Private/Crypto/Algorithms/AlgorithmRegistry.cpp"
)

# Base algorithm.
add_source_group(Source.Crypto.Algorithms.Base
	"Public/Crypto/Algorithms/Base/Algorithm.h"
	"Private/Crypto/Algorithms/Base/Algorithm.cpp"
)

# Base duplex.
add_source_group(Source.Crypto.Algorithms.Base.Duplex
	"Public/Crypto/Algorithms/Base/Duplex/AlgorithmDuplex.h"
	"Private/Crypto/Algorithms/Base/Duplex/AlgorithmDuplex.cpp"
)

# Base events.
add_source_group(Source.Crypto.Algorithms.Base.Events
	"Public/Crypto/Algorithms/Base/Events/OnDecryptFailed.h"
)
	
# Shared.
add_source_group(Source.Crypto.Algorithms.Shared.ZLib.Duplex
	"Public/Crypto/Algorithms/Shared/ZLib/Duplex/InflateDuplex.h"
	"Private/Crypto/Algorithms/Shared/ZLib/Duplex/InflateDuplex.cpp"
	"Public/Crypto/Algorithms/Shared/ZLib/Duplex/DeflateDuplex.h"
	"Private/Crypto/Algorithms/Shared/ZLib/Duplex/DeflateDuplex.cpp"
)

add_source_group(Source.Crypto.Algorithms.Shared.ZLib.Events
	"Public/Crypto/Algorithms/Shared/ZLib/Events/OnInflateFailed.h"
)

add_source_group(Source.Crypto.Algorithms.Shared.Rsa
	"Public/Crypto/Algorithms/Shared/Rsa/RsaBlock.h"
	"Private/Crypto/Algorithms/Shared/Rsa/RsaBlock.cpp"
	"Public/Crypto/Algorithms/Shared/Rsa/RsaEncryptedBlock.h"
	"Private/Crypto/Algorithms/Shared/Rsa/RsaEncryptedBlock.cpp"
)


# 41x
add_source_group(Source.Crypto.Algorithms.41x.Versions
	"Public/Crypto/Algorithms/41x/Versions/Ver411.h"
	"Public/Crypto/Algorithms/41x/Versions/Ver412.h"
	"Public/Crypto/Algorithms/41x/Versions/Ver413.h"
	"Public/Crypto/Algorithms/41x/Versions/Ver414.h"
)

add_source_group(Source.Crypto.Algorithms.41x.Duplex
	"Public/Crypto/Algorithms/41x/Duplex/Ver41xDecDuplex.h"
	"Private/Crypto/Algorithms/41x/Duplex/Ver41xDecDuplex.cpp"
	"Public/Crypto/Algorithms/41x/Duplex/Ver41xEncDuplex.h"
	"Private/Crypto/Algorithms/41x/Duplex/Ver41xEncDuplex.cpp"
)

add_source_group(Source.Crypto.Algorithms.41x.Shared
	"Public/Crypto/Algorithms/41x/Shared/Ver41xParams.h"
)

# Shared.
add_source_group(Source.Shared.Templates
	"Public/Shared/Templates/EventTemplate.h"
)

add_source_group(Source.Shared.Structs
	"Public/Shared/Structs/FileData.h"
)

# Utils.

# BufferedStream.
add_source_group(Source.Utils.Streams
	"Public/Utils/Streams/InputStream.h"
	"Private/Utils/Streams/InputStream.cpp"
	"Public/Utils/Streams/OutputStream.h"
	"Private/Utils/Streams/OutputStream.cpp"
	"Public/Utils/Streams/DuplexStream.h"
	"Private/Utils/Streams/DuplexStream.cpp"
)
