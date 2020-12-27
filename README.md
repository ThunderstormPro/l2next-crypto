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
* CMake version 3.1
* Visual Studio 2010 or newer. Visual Studio 2020 and Windows 10 64-bit are recommended.
 
# Generating solution

To generate Visual Studio solution the following command must be executed in
bash from the project root directory:

Ex.

* For Windows x32
```bash
 cmake -B Build -G "Visual Studio 16 2020" -A x32
```

- For Windows x64
```bash
 cmake -B Build -G "Visual Studio 15 Win64"
```

Additional argument can be provided to enable/disable building of test application.

```bash
 cmake -B Build -G "Visual Studio 15 Win64" -DBUILD_TEST_APP=on
```

 (!) Please note that the version of the IDE must match with the version of
Visual Studio installed on your PC.
Below is the list of supported VS versions:

* Visual Studio 14 (2015)
* Visual Studio 15 (2017)
* Visual Studio 16 (2020)

# Building solution

To perform a Windows build using a 32/64-bit:
Open ./Build/L2NextCrypto.sln in Visual Studio and select **Build > Build Solution**.
