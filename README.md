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

## Run & Usage
### Arbitraje
Utilizar una variable de entorno para seleccionar el algoritmo deseado.
* `FLOYD=true`: Seleccionara Floyd
* `FLOYD=false`: Seleccionara BellmanFord
Ejemplo: `cat samples/ejercicio_2_-2_int_cycle.txt | FLOYD=true ./bin/arbitraje`

#### Tests
Correr tests de Arbitraje: `./bin/arbitraje_test`

### Example
Un archivo de texto o cualquier tipo de input debe ser enviado como input de nuestro programa.

Ejemplo:
```bash
cat samples/ejercicio_2_sample_1.txt | ./bin/arbitraje
```

## Tests
Test sampled where added under `samples`, a brief description of each:

## Conventions
Google C++ style: <https://google.github.io/styleguide/cppguide.html>
