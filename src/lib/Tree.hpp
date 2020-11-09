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

    public:
        /* Builders */
        Sommet(); // Default
        Sommet(const Sommet&); // Copy
        Sommet(int numCar, char car);

        /* Overloaded */
        Sommet &operator=(const Sommet&);

        friend std::ostream &operator<<(std::ostream &flux, const Sommet&);
        
        int maximum(int a, int b);

<<<<<<< HEAD
    /* Getters */
    int getNumCar() const;
    char getCar() const;
    Sommet* getLeft() const;
    Sommet* getRight() const;
    int getDepth(Sommet*);
=======
        /* Getters */
        int getNumCar() const;
        char getCar() const;
        Sommet* getLeft() const;
        Sommet* getRight() const;
        int getDepth(Sommet* sommet);
>>>>>>> 9989db358e97b8c4612d38b6fbad8187acb968a0



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

<<<<<<< HEAD
    void operator<(Sommet&); // Add node
    int operator>(Sommet&); // Dell node ( Quentin )

    int emptyTree();
    ArbreB addNode(Sommet *);

    Sommet &operator[](int index);

    /*printer*/
    void printTree(Sommet*, int depth);
=======
        void operator<(Sommet newRoot); // Add node
        void operator>(Sommet* newRoot); // Dell node ( Quentin )

        Sommet &operator[](int index);

        /*printer*/
        void printTree(ArbreB, int depth);
>>>>>>> 9989db358e97b8c4612d38b6fbad8187acb968a0

        /* Getters */
        Sommet* getRoot() const;

        /* Destructor */
        ~ArbreB();
};

#endif
