# 06 OBSERVER PATTERN
## PlantUML installation
```bash
sudo apt-get install plantuml
```
## UML diagram generation
```bash
cd uml/
plantuml -tsvg -gui
```
## Manual compilation
```bash
mkdir build-debug && cd build-debug
cmake -DCMAKE_BUILD_TYPE=Debug ../
make -j4
mkdir build-release && cd build-release
cmake -DCMAKE_BUILD_TYPE=Release ../
make -j4
```
## Compilation from CLion
```bash
File -> Open... -> [Select directory with CMakeLists.txt]
```
Build profile for optimized build:
```bash
File -> Settings... -> Build, Execution, Deveopment -> CMake -> [Click '+' to add new 'Profile' with 'Build Type' 'Release']
```
