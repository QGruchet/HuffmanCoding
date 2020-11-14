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
    int numCar; // if car = '\0', numCar = Sum of char under Sommet,
                // else numCar = frequency of car
    char car;
    Sommet *left, *right;

    /* Init */
    void init(int, char);

public:
    /* Builders */
    Sommet(); // Default
    Sommet(int, char);
    Sommet(int);

    /* Overloaded */
    Sommet& operator<<(int);
    Sommet& operator>>(int);

    friend std::ostream &operator<<(std::ostream &flux, Sommet s);
    
    /* Methodes */
    bool isLeaf();

    void Min(int*);
    int dataMin();

    void Max(int*);
    int dataMax();

    bool found(int);

    void printPrefix();
    void print(Sommet*);
    void printBeautifulTree(int);
    void clean();

    /* Getters */
    int getNumCar() const;
    char getCar() const;
    Sommet* getLeft() const;
    Sommet* getRight() const;
    int getDepth();

    void ecritureHeader();
    void ecritureFichier(Sommet*);
    void ecritureEnder();

    /* Destructor */
    ~Sommet();
};

class ArbreB
{
  private:
    /* Data */
    Sommet *root;
    int depth, size;

  public:
    /* Builders */
    ArbreB(); //Default
    ArbreB(Sommet*);

    /* Overloaded */

    /* Methodes */

    /* Getters */
    Sommet* getRoot() const;
    int getSize() const;

    /* Destructor */
    ~ArbreB();
};

#endif