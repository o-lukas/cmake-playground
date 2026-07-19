## v0.5.1 (2026-07-19)

### Fix

- don't build MathUtils as shared by default

## v0.5.0 (2026-07-18)

### Feat

- generate and install sbom
- **conan**: use conan lock file

### Fix

- install DLLs to runtime

## v0.4.0 (2026-07-18)

### BREAKING CHANGE

- project names have changed

### Feat

- **conan**: added conan test package feature
- **conan**: use xxx-config.cmake files inside package
- add MathUtil project

### Fix

- remove invalid declarations from includes destination

### Refactor

- rename projects

## v0.3.0 (2026-07-18)

### Feat

- create package config files

## v0.2.0 (2026-07-16)

### Feat

- generate Conan packages
- export CMake targets

## v0.1.1 (2026-07-12)

### Fix

- use permissions instead of GH_TOKEN

## v0.1.0 (2026-07-12)

### Feat

- use GTest for testing
- run various CPack generators depending on platform
- use conan to install CLI11 and use it in executable
- add basic CPack configuration
- added simple playground project
