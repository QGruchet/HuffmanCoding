#ifndef Tree_HPP
#define Tree_HPP

#include "Parser.hpp"

class Sommet
{
    private:
        /* Data */
        int numCar; // if car = '\0', numCar = Sum of char under Sommet,
                    // else numCar = frequency of car
        char car;
        Sommet *left, *right;

        /* Builders */
        Sommet(); // Default
        Sommet(const Sommet&); // Copy
        Sommet(int numCar, char car);

        /* Overloaded */
        Sommet &operator=(const Sommet&);

        friend std::ostream &operator<<(std::ostream &flux, const Sommet&);
        
        int maximum(int a, int b);

    public:
        /* Getters */
        int getNumCar() const;
        char getCar() const;
        Sommet* getLeft() const;
        Sommet* getRight() const;
        int getDepth(Sommet* sommet);

        /* Destructor */
        ~Sommet();
};

class ArbreB
{
    private:
        /* Data */
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

        void operator<(Sommet newNode); // Add node
        void operator>(Sommet* newNode); // Dell node ( Quentin )

        Sommet &operator[](int index);

        /* Methodes */
        void printTree(Sommet *sommet, int depth);
        int emptyTree();
        void addNode(Sommet *newNode, Sommet *root);

        /* Getters */
        Sommet* getRoot() const;

        /* Destructor */
        ~ArbreB();
};

#endif
