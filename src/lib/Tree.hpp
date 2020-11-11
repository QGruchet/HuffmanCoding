#ifndef Tree_HPP
#define Tree_HPP

#include "Parser.hpp"
#include "queue"

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
        Sommet(int numCar, char car);
        Sommet(int num);

        /* Overloaded */
        
        /* Methodes */
        void add(Sommet *root, int newDatat);

        bool isLeaf();

        void printPrefix(Sommet *node);
        void print(Sommet *node);
        void printTree(Sommet *node, int space);
        void clean(Sommet *node);

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
        ArbreB(); //Default
        ArbreB(Sommet *root);

        /* Overloaded */

        /* Methodes */
        int maximum(int a, int b);
        bool isTreeEmpty();

        /* Getters */
        Sommet* getRoot() const;
        int getDepth(Sommet *node);
        int getSize() const;

        /* Destructor */
        ~ArbreB();
};

#endif