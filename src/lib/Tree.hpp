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

  public:
    /* Builders */
    Sommet(); // Default
    Sommet(const Sommet&); // Copy
    Sommet(int numCar, char car);

    /* Overloaded */
    Sommet &operator=(const Sommet&);

    friend std::ostream &operator<<(std::ostream &flux, const Sommet&);

    /* Destructor */
    ~Sommet();
};

class ArbreB
{
  private:
    /* Attributes */
    Sommet *left, *right;

  public:
    /* Builders */
    ArbreB(); // Default
    ArbreB(const ArbreB&); // Copy

    /* Overloaded */
    ArbreB &operator=(const ArbreB&);

    ArbreB &operator+=(const ArbreB&); // Add an other tree
    ArbreB &operator-=(const ArbreB&); // Slip tree

    void operator<(const Sommet&); // Add node
    int operator>(Sommet&); // Dell node

    // Sommet operator[]()

    friend std::ostream &operator<<(std::ostream &flux, const ArbreB&);

    /* Destructor */
    ~ArbreB();
};

#endif
