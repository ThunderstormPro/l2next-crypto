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
	"Public/Crypto/Algorithms/Base/Events/OnDecryptPassed.h"
)

add_source_group(Source.Crypto.Algorithms.Base.Structs
	"Public/Crypto/Algorithms/Base/Structs/DecryptResult.h"
)
	
# Shared.
add_source_group(Source.Crypto.Algorithms.Shared.ZLib.Duplex
	"Public/Crypto/Algorithms/Shared/ZLib/Duplex/InflateDuplex.h"
	"Private/Crypto/Algorithms/Shared/ZLib/Duplex/InflateDuplex.cpp"
	"Public/Crypto/Algorithms/Shared/ZLib/Duplex/DeflateDuplex.h"
	"Private/Crypto/Algorithms/Shared/ZLib/Duplex/DeflateDuplex.cpp"
)

add_source_group(Source.Crypto.Algorithms.Shared.ZLib.Events
	"Public/Crypto/Algorithms/Shared/ZLib/Events/InflatePassed.h"
	"Public/Crypto/Algorithms/Shared/ZLib/Events/InflateFailed.h"
)

add_source_group(Source.Crypto.Algorithms.Shared.ZLib.Structs
	"Public/Crypto/Algorithms/Shared/ZLib/Structs/zlibResult.h"
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

# Common.
add_source_group(Source.Shared.Enums
	"Public/Shared/Enums/CryptoCommands.h"
)

add_source_group(Source.Shared.Templates
	"Public/Shared/Templates/EventTemplate.h"
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

# Events.
add_source_group(Source.Utils.Streams.Events
	"Public/Utils/Streams/Events/OnData.h"
	"Private/Utils/Streams/Events/OnData.cpp"
	"Public/Utils/Streams/Events/OnEnd.h"
	"Private/Utils/Streams/Events/OnEnd.cpp"
)

# Stream traits.
add_source_group(Source.Utils.Streams.Traits
	"Public/Utils/Streams/Traits/Readable.h"
	"Private/Utils/Streams/Traits/Readable.cpp"
	"Public/Utils/Streams/Traits/Transformable.h"
	"Private/Utils/Streams/Traits/Transformable.cpp"
	"Public/Utils/Streams/Traits/Writable.h"
	"Private/Utils/Streams/Traits/Writable.cpp"
	"Public/Utils/Streams/Traits/Pipable.h"
	"Private/Utils/Streams/Traits/Pipable.cpp"
	"Public/Utils/Streams/Traits/Streamable.h"
	"Private/Utils/Streams/Traits/Streamable.cpp"
)

# Structs.
add_source_group(Source.Utils.Streams.Structs
	"Public/Utils/Streams/Structs/StreamExecResult.h"
	"Public/Utils/Streams/Structs/StreamOptions.h"
	"Public/Utils/Streams/Structs/BufStreamOptions.h"
	"Public/Utils/Streams/Structs/FileStreamOptions.h"
)