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
```cpp
/**
 * Function : Constructor by copy.
 * Return : 'Sommet'.
 * Description : Create an object 'Sommet' with default parameters.
 * */ 
Sommet::Sommet() : data(0), left(nullptr), right(nullptr) {}

/**
 * Function : Constructor by copy.
 * Return : 'ArbreB'.
 * Description : Create an object 'ArbreB' with default parameters.
 * */  
ArbreB::ArbreB() : root(nullptr)  {}

/**
 * Function : Copy.
 * Return : 'Sommet'*.
 * Description : Return a deep copy of this.
 * */  
Sommet* Sommet::copy()

/**
 * Function : Constructor by copy.
 * Return : 'Sommet'.
 * Description : Create an object 'Sommet' with an other.
 * */  
Sommet::Sommet(const Sommet& other) {}

/** Function : Constructor by copy.
 * Return : 'ArbreB'.
 * Description : Create a object 'ArbreB' with an other.
 * */  
ArbreB::ArbreB(const ArbreB& other) {}

/** Function : Constructor with parameter.
 * Return : 'Sommet'.
 * Description : Create a object 'Sommet' by initializing the data.
 * */  
Sommet::Sommet(int newData) : data(newData), left(nullptr), right(nullptr) {}

/** Function : Constructor with parameter.
 * Return : 'ArbreB'.
 * Description : Create a object 'ArbreB' by initializing the root.
 * */  
ArbreB::ArbreB(int rootData) {}

/** Function : Overloading operator=.
 * Return : 'Sommet'.
 * Description : Copy a object 'Sommet' with an other.
 * */  
Sommet& Sommet::operator=(Sommet other) {}

/** Function : Overloading operator=.
 * Return : 'ArbreB'.
 * Description : Swap the value of the 'Sommet' with newData.
 * */  
Sommet& Sommet::operator=(int newData) {}


/** Function : Overloading operator=.
 * Return : 'ArbreB'.
 * Description : Copy a object 'ArbreB' with an other.
 * */  
ArbreB& ArbreB::operator=(const ArbreB& other) {}

/** Function : Overloading operator==.
 * Return : boolean.
 * Description : Say if the 'Sommet' is equal to an other.
 * */  
bool Sommet::operator==(const Sommet& other) {}

/** Function : Overloading operator==.
 * Return : boolean.
 * Description : Say if the 'Sommet' is equal to an other, recursive version.
 * */  
bool Sommet::equal(Sommet *node) {}


/** Function : Overloading operator==.
 * Return : boolean.
 * Description : Say if the 'ArbreB' is equal to an other.
 * */  
bool ArbreB::operator==(const ArbreB& other) {}

/** Function : Overloading operator<<.
 * Return : 'ArbreB'.
 * Description : Add a node with the value 'newData' in the tree.
 * */  
ArbreB& ArbreB::operator<<(int newData) {}

/** Function : add.
 * Return : 'ArbreB'.
 * Description : Add a node with the value 'newData' in the tree, recursive version.
 * */  
void ArbreB::add(Sommet *root, int newData) {}

/** Function : Overloading operator>>.
 * Return : 'ArbreB'.
 * Description : Dell a node with the value 'dellData' in the tree, if
 * the node with 'dellData' existe.
 * */
ArbreB& ArbreB::operator>>(int dellData) {}

/** Function : dell.
 * Return : 'ArbreB'.
 * Description : Dell a node with the value 'dellData' in the tree, if
 * the node with 'dellData' existe, recursive version.
 * */
void ArbreB::dell(Sommet *root, int dellData) {}

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



