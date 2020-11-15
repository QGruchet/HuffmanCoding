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
    Sommet(int);

    /* Overloaded */
    friend std::ostream &operator<<(std::ostream &, const Sommet&);
    
    /* Methodes */
    bool isLeaf();
    void printBeautifulTree(int);

    /* Getters */
    int getData() const;
    char getCar() const;
    Sommet* getLeft() const;
    Sommet* getRight() const;
    int getDepth();

    /* Destructor */
    ~Sommet();
};

class ArbreB
{
  private:
    /* Data */
    int size;
    Sommet *root;

  public:
    /* Builders */
    ArbreB(); //Default
    ArbreB(const ArbreB&); // Copy
    ArbreB(int);

    /* Overloaded */
    ArbreB& operator=(const ArbreB&);
    ArbreB& operator<<(int); // Insert
    ArbreB& operator>>(int); // Dell
    Sommet* operator[](int);

    friend std::ostream &operator<<(std::ostream &flux, const ArbreB&);

    /* Methodes */
    void add(Sommet*, int);
    void dell(Sommet*, int);
    Sommet* find(Sommet*, int);
    void clear(Sommet*);
    void copy(const Sommet*, Sommet*);

    /* Getters */
    Sommet* getRoot() const;
    int getSize() const;

    /* Destructor */
    ~ArbreB();
};

#endif