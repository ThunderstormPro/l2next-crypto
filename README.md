# L2NextCrypto
Encrypt / Decrypt C++ library for Lineage 2 files.

# Usage

*Simple usage*

```
std::ifstream input(cp.src, std::ios::binary);
std::ofstream output(cp.out, std::ios::binary);

  try {
    std::stringstream stream;
    stream << input.rdbuf();

    auto crypto = std::make_unique<L2NextCrypto>();
    output << crypto->Decrypt(stream);
  }
  catch (EDecryptError err) {
     // Log error
  }
```

*With events*

```
std::ifstream input(cp.src, std::ios::binary);
std::ofstream output(cp.out, std::ios::binary);

  try {
    std::stringstream stream;
    stream << input.rdbuf();

    auto crypto = std::make_unique<L2NextCrypto>();
    
    crypto->OnDecryptChunk([&](const SDecryptedChunk& chunk) {
      // Print progress
    });

    crypto->OnInflateChunk([&](const SInflatedChunk& chunk) {
      // Print progress
    });
    
    output << crypto->Decrypt(stream);
  }
  catch (EDecryptError err) {
     // Log error
  }
```

# Requirements

The below requirements must be met to build this library.

* Windows 7 or newer OS
* CMake version 3.2
* Visual Studio 2017 or newer. Visual Studio 2020 and Windows 10 64-bit are recommended.

### VCPKG Required libraries: 
| Package | Platform | Recommended library type |
| --------------- | --------------- | --------------- |
| zlib | x(32/64) | static-md |
| mpir | x(32/64) | static-md |
| yaml-cpp | x(32/64) | static-md |

Example of installation:  
`vcpkg install zlib:x64-windows-static-md`

# Generating solution

First you must set an environment variable with your root vcpkg path.

ex. `set VCPKG_ROOT="C:\\vcpkg"`

This will make use of the vcpkg toolchain, if you don't want to set it up, you could call cmake command with extra param
```
ex. -DCMAKE_TOOLCHAIN_FILE=path_to_vcpkg/scripts/buildsystems/vcpkg.cmake
```

To generate Visual Studio solution the following command must be executed in
bash from the project root directory:

Ex.

* For Windows x32
```bash
 cmake -B Build -G "Visual Studio 16" -A x32 -DVCPKG_TARGET_TRIPLET=x32-windows-static-md
```

- For Windows x64
```bash
 cmake -B Build -G "Visual Studio 16" -A x64 -DVCPKG_TARGET_TRIPLET=x64-windows-static-md
```

 (!) Please note that the version of the IDE must match with the version of
Visual Studio installed on your PC.
Below is the list of supported VS versions:

* Visual Studio 15 (2017)
* Visual Studio 16 (2020)

# Building solution

To perform a Windows build using a 32/64-bit:
Open ./Build/L2NextCrypto.sln in Visual Studio and select **Build > Build Solution**.
