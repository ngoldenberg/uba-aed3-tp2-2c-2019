# TP2 - Agoritmos y Estructuras de Datos III
_Trabajo Practico 2_

## Platform support
*IMPORTANT*: This project can only be run on the following OSs:
 - Darwin
 - Linux 64bit

## Estructura del proyecto

 - `src/` contains all the source
 - `test/` contains all the tests
 - `lib/` contains pre-compiled external libraries for different platforms and architectures (2)
 - `include/` contains external include files
 - `bin/` contains all compilation targets
 - `build/` is just the trashcan for cmake
 - `samples/` input samples

## Install
1) Install `cmake`, `make`, `g++` and `gtest` 
2) Clone project: `git clone git@github.com:lilmonk3y/uba-aed3-tp2-2c-2019.git` 
_(or no ssh: `git clone https://github.com/lilmonk3y/uba-aed3-tp2-2c-2019.git`)_ 
3) Run `cmake -S . -B build`

#### Reset
For resetting, just
```bash
rm -rf build/
```

## C++ FUN!
- Compile: `make -C build`
- Test: `make -C build test`
- Clean: `make -C build clean`
_(se puede evitar `-C build` estar dentro de `build/`)_

## Tests
Test sampled where added under `samples`, a brief description of each:

## Conventions
Google C++ style: <https://google.github.io/styleguide/cppguide.html>
