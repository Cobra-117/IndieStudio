# Bomberman
## Contributors : 
Adrien Michaud, Basile Seroul, Flavien Allix, Jérémy Braconnier, Paul Moccelin, Timothé Lacheroy
## Project Goal : 
The goal of this project is to reproduce the Neo Bomberman game of 1970's. We have to use the raylib to make our own Game Engine. We have to use 3D object for players, walls, etc... and handle two local players with NPC controlled by ia.

# Installation / Build
## Windows Installation
Make sure that you have installed all the C and c++ libraries and raylib libraries, make sure that theses libraries path are set to windows environement table.
It is recommanded that you install visual studio with c++ libraries, then add c++ libraries to windows path, then install cmake + raylib and add them to windows path. Finally install git bash, then you are good to go.
This program has been tested and it is working fine on Windows 10 & 11
Windows 11 Compile Success : https://youtu.be/A-juh8ABWPk
Windows 10 Compile + Gameplay : https://youtu.be/EsdZcJ3tnWc

## Linux Installation
Make sure you use the lastest version of your libraries and you have raylib installed

## Build (linux + windows)

Go to the repo, then do the command : (use gitbash on windows)
```bash
cmake -B build/
```
Then, do
```bash
cmake --build build/
```
Once that done, on linux you should have your executable on the build folder. On windows, please move the executor from build/debug to buid/, otherwise textures will be blank!

# Task list

* Adrien Michaud :
  - [x] Done the Core encapsulation
  - [x] Done the first menu
  - [x] Done change skin players
  - [x] Done Camera
* Basile Seroul :
  - [x] Done the Shape's encapsulation
  - [x] Done the setting's menu
  - [x] Windows compilation tests
  - [x] Done UI
* Flavien Allix :
  - [x] Done the Text's encapsulation
  - [x] Done the Tests;
  - [x] Done github workflow tests
  - [x] Done other windows OS testing
* Jérémy Braconnier :
  - [x] Done the Audio's encapsulation
  - [x] Done 3d model search
  - [x] Done player music selection
* Paul Moccelin :
  - [x] Done the Model's encapsulation
* Timothé Lacheroy :
  - [x] Done the Texture's encapsulation
  - [x] Done the map's class
  - [x] Done map display
  - [x] Done players actions (Movement, ...)

## Tests

For testing, once the project as been build, go to the build directory then enter the command :
```bash
make test
```
This will do the tests automatically