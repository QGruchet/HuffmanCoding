# HuffmanCoding
Implementation of Huffman coding in cpp.

[![forthebadge](http://forthebadge.com/images/badges/built-with-love.svg)](http://forthebadge.com)  [![forthebadge](http://forthebadge.com/images/badges/powered-by-electricity.svg)](http://forthebadge.com)

> "In computer science and information theory, a Huffman code is a particular type of optimal prefix code that is commonly used for lossless data compression." [wikipedia](https://en.wikipedia.org/wiki/Huffman_coding)

***

# Table of contents
- [Directory hierarchy](#Directory-hierarchy)  
- [Needed](#Needed)  
- [Installation](#Installation)  
- [Launch](#Launch)  
- [Some idea for amelioration](#Some-idea-for-amelioration)
- [Authors](#Authors)  


# Directory hierarchy

The project is split in many sub directories like the hierarchy as below : 
```bash
.
├── build.sh
├── Makefile
├── README.md
└── src
    ├── lib
    │   ├── Parser.cpp
    │   ├── Parser.hpp
    │   ├── Tree.cpp
    │   ├── Tree.hpp
    │   ├── Writer.cpp
    │   └── Writer.hpp
    ├── main
    │   └── Main.cpp
    ├── _test
    │   ├── Test.cpp
    │   └── Test.hpp
    └── windowQT
        ├── CMakeLists.txt
        ├── WindowQT.cpp
        └── WindowQT.hpp

5 directories, 15 files
```
* src : Contains all sources codes.
* src/lib : Contains all librairies using by the projet.
* src/main : Contains the main file.
* src/test : Contains the tests files.
* src/windowQT : Contains application files.  

# Needed


Our program is made in C++ and use Qt for the graphic interface. Also, for our program to work, we need two or three little things :

- [cmake](https://cmake.org/install/) version superior to 3.0.0 is required
- [Qt libraries](https://doc.ubuntu-fr.org/qt) version superior to 5.0 is required
- A C++ compiler like [g++](https://doc.ubuntu-fr.org/gcc) (recommanded) or [Clang](https://clang.llvm.org/get_started.html)


# Installation

To build our program, just needed to write this in a terminal :

- ``` make ```


# Launch

To start our program, two options are given :

- ``` make run ``` to have a display in the terminal.
- ``` make window ``` to run a graphic interface where you can interact with our program.

# Details of functions
## Tree.cpp

## Writer.cpp

## Test.cpp

## WindowQT.cpp

# Some idea for amelioration

Here some idea for future version :
- Our interface can interact with the painting tree, like adding node, deleting node, spliting tree, fusion of two differents tree...
- Dell root in the millde of the tree isn't working. We have to fix it.
- Solve memory leaks in the graphic interface.

# Authors
* **LE DENMAT Mickael 21804355**
* **GRUCHET Quentin 21605636**

***



