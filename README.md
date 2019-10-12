# lineage-crypto
Encrypt / Decrypt C++ library for Lineage 2 files.

# Requirements

The below requirements must be met to build this library.

* Windows 7 or newer OS
* CMake version 3.1
* Visual Studio 2010 or newer. Visual Studio 2015 Update 3 and Windows 10 64-bit are recommended.
 
# Generating solution

To generate Visual Studio solution the following command must be executed in
bash from the project root directory:

* For Windows x32
```bash
 cmake -B Build -G "Visual Studio 15"
```

- For Windows x64
```bash
 cmake -B Build -G "Visual Studio 15 Win64"
```

 (!) Please note that the version of the IDE must match with the version of
Visual Studio installed on your PC.
Below is the list of supported VS versions:

* Visual Studio 10 (2010)
* Visual Studio 11 (2012)
* Visual Studio 12 (2013)
* Visual Studio 14 (2015)
* Visual Studio 15 (2017)

# Building solution

To perform a Windows build using a 32/64-bit:
Open ./Build/L2NextCrypto.sln in Visual Studio and select **Build > Build Solution**.
