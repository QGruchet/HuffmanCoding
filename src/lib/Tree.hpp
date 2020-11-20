/**
 * Tree.cpp : You can found here all functions implemented for the Tree class.
 * Author : Mickael.
 * */

#ifndef Tree_HPP
#define Tree_HPP

#include "Parser.hpp"
#include "queue"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

class Sommet
{
  friend class ArbreB; // For used 'Sommet' int 'ArbreB' without 
                      // getters or setters

  private:
    /* Data */
    int data; // The value of the node
    Sommet *left, *right; // Left child and right child

public:
    /* Constructors */
    Sommet(); // Default
    Sommet(const Sommet&); // Copy
    Sommet(int);

    /* Overloaded */
    Sommet& operator=(Sommet);
    Sommet& operator=(int);
    bool operator==(const Sommet&);

    friend std::ostream &operator<<(std::ostream &, const Sommet&);
    
    /* Methodes */
    void Min(int*);
    int dataMin();

    void Max(int*);
    int dataMax();

    bool isLeaf();
    void printBeautifulTree(int);
    void writeBeautifulTreeInFile(int);
    Sommet* copy();
    bool equal(Sommet*);
    int countDepth();
    int countSize();

    /* Getters */
    int getData() const;
    Sommet* getLeft() const;
    Sommet* getRight() const;

    /* Setters */
    void setLeft(int leftData);
    void setRight(int rightData);

    /* Destructor */
    ~Sommet();
};

class ArbreB
{
  private:
    /* Data */
    Sommet *root;

  public:
    /* Constructors */
    ArbreB(); //Default
    ArbreB(const ArbreB&);
    ArbreB(int);

    /* Overloaded */
    ArbreB& operator=(const ArbreB&);
    bool operator==(const ArbreB&);
    
    ArbreB& operator<<(int); // Insert
    ArbreB& operator>>(int); // Dell
    Sommet* operator[](int);

    friend std::ostream &operator<<(std::ostream &flux, const ArbreB&);

    ArbreB& operator+=(const ArbreB&);
    ArbreB& operator-=(ArbreB&);

    /* Methodes */
    void add(Sommet*, int);
    void dell(Sommet*, int);
    Sommet* find(Sommet*, int);

    /* Getters */
    Sommet* getRoot() const;
    Sommet* getRandLeaf(Sommet*) const;

    /* Destructor */
    ~ArbreB();
};

#endif
