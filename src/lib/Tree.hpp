#ifndef Tree_HPP
#define Tree_HPP

#include "Parser.hpp"
#include "queue"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

class Sommet
{
  friend class ArbreB;

  private:
    /* Data */
    int data;
    Sommet *left, *right;

public:
    /* Builders */
    Sommet(); // Default
    Sommet(int, char);
    Sommet(int);

    /* Overloaded */
    friend std::ostream &operator<<(std::ostream &flux, const Sommet&);
    
    /* Methodes */
    bool isLeaf();
    void printBeautifulTree(int);
    int getDepth();

    /* Getters */
    int getData() const;
    char getCar() const;
    Sommet* getLeft() const;
    Sommet* getRight() const;

    /* Destructor */
    ~Sommet();
};

class ArbreB
{
  private:
    /* Data */
    int depth, size;
    Sommet *root;

  public:
    /* Builders */
    ArbreB(); //Default
    ArbreB(Sommet*);

    /* Overloaded */
    ArbreB& operator<<(int); // Insert
    ArbreB& operator>>(int); // Dell
    Sommet* operator[](int);

    friend std::ostream &operator<<(std::ostream &flux, const ArbreB&);

    /* Methodes */
    Sommet* add(int);
    Sommet* dell(int);
    Sommet* find(int);

    /* Getters */
    Sommet* getRoot() const;
    int getSize() const;

    /* Destructor */
    ~ArbreB();
};

#endif