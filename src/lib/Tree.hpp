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
    Sommet(const Sommet *left, const Sommet *right);

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
    Sommet *root;

  public:
    /* Builders */
    ArbreB(); // Default
    ArbreB(const ArbreB&); // Copy
    ArbreB(const Sommet* root);

    /* Overloaded */
    ArbreB &operator=(const ArbreB&);

    ArbreB &operator+=(const ArbreB&); // Add an other tree ( Quentin )
    ArbreB &operator-=(const ArbreB&); // Split tree ( Quentin )

    void operator<(const Sommet&); // Add node
    int operator>(Sommet&); // Dell node ( Quentin )

    // Sommet operator[]()

    friend std::ostream &operator<<(std::ostream &flux, const ArbreB&);

    /* Destructor */
    ~ArbreB();
};

#endif
