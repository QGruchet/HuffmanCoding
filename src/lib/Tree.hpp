#ifndef Tree_HPP
#define Tree_HPP

#include <iostream>

class Sommet
{
  private:
    /* Attributes */
    int numCar; // if car = '\0', numCar = Sum of char under Sommet,
                // else numCar = frequency of car
    char car;
    Sommet *left, *right;

  public:
    /* Builders */
    Sommet(); // Default
    Sommet(const Sommet&); // Copy
    Sommet(int numCar, char car);

    /* Overloaded */
    Sommet &operator=(const Sommet&);

    friend std::ostream &operator<<(std::ostream &flux, const Sommet&);
    
    int maximum(int a, int b);

    /* Getters */
    int getNumCar() const;
    char getCar() const;
    Sommet* getLeft() const;
    Sommet* getRight() const;
    int getDepth(Sommet*);



    /* Destructor */
    ~Sommet();
};

class ArbreB
{
  private:
    /* Attributes */
    Sommet *root;

  public:
    /* Builders */
    ArbreB(); // Default
    ArbreB(const ArbreB&); // Copy
    ArbreB(Sommet* root);

    /* Overloaded */
    ArbreB &operator=(const ArbreB&);

    ArbreB &operator+=(const ArbreB&); // Add an other tree ( Quentin )
    ArbreB &operator-=(const ArbreB&); // Split tree ( Quentin )

    void operator<(Sommet&); // Add node
    int operator>(Sommet&); // Dell node ( Quentin )

    int emptyTree();
    ArbreB addNode(Sommet *);

    Sommet &operator[](int index);

    /*printer*/
    void printTree(Sommet*, int depth);

    /* Getters */
    Sommet* getRoot() const;

    /* Destructor */
    ~ArbreB();
};

#endif
