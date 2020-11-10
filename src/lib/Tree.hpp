#ifndef Tree_HPP
#define Tree_HPP

#include "Parser.hpp"

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
        void init(int numCar, char car);

    public:
        /* Builders */
        Sommet(); // Default
        Sommet(const Sommet&); // Copy
        Sommet(int numCar, char car);
        Sommet(int num);

        /* Overloaded */
        Sommet &operator=(const Sommet&);

        friend std::ostream &operator<<(std::ostream &flux, const Sommet&);
        

        /* Getters */
        int getNumCar() const;
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
        Sommet *root;
        int depth, size;

    public:
        /* Builders */
        ArbreB(); // Default
        ArbreB(const ArbreB&); // Copy
        ArbreB(Sommet* root);

        /* Overloaded */
        ArbreB &operator=(const ArbreB&);

        ArbreB &operator+=(const ArbreB&); // Add an other tree
        ArbreB &operator-=(const ArbreB&); // Split tree

        void operator<(Sommet newNode); // Add node
        void operator>(Sommet* newNode); // Dell node

        Sommet* operator[](int index);

        friend std::ostream &operator<<(std::ostream &flux, const ArbreB&);

        /* Methodes */
        int maximum(int a, int b);

        bool isTreeEmpty();

        void addNode(Sommet *root, Sommet *newNode);
        void toVector(std::vector<Sommet*> vectorTree);

        void printTree(Sommet *sommet, int);

        /* Getters */
        Sommet* getRoot() const;
        int getSize() const;
        int getDepth(Sommet* sommet);

        /* Destructor */
        ~ArbreB();
};

#endif