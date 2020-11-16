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
  friend class ArbreB;

  private:
    /* Data */
    int data;
    Sommet *left, *right;

public:
    /* Constructors */
    Sommet(); // Default
    Sommet(const Sommet&); // Copy
    Sommet(int);

    /* Overloaded */
    Sommet& operator=(Sommet);

    friend std::ostream &operator<<(std::ostream &, const Sommet&);
    
    /* Methodes */
    bool isLeaf();
    void printBeautifulTree(int);
    Sommet* copy();

    /* Getters */
    int getData() const;
    char getCar() const;
    Sommet* getLeft() const;
    Sommet* getRight() const;
    int countDepth();
    int countSize();

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
    /* Constructors */
    ArbreB(); //Default
    ArbreB(int);

    /* Overloaded */
    ArbreB& operator<<(int); // Insert
    ArbreB& operator>>(int); // Dell
    Sommet* operator[](int);

    friend std::ostream &operator<<(std::ostream &flux, const ArbreB&);

    ArbreB& operator+=(const ArbreB&);
    ArbreB& operator-=(ArbreB*);

    /* Methodes */
    void add(Sommet*, int);
    void dell(Sommet*, int);
    Sommet* find(Sommet*, int);

    /* Getters */
    Sommet* getRoot() const;
    int getSize() const;
    Sommet* getRandLeaf(Sommet*) const;

    /* Destructor */
    ~ArbreB();
};

#endif