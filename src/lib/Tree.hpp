#ifndef Tree_HPP
#define Tree_HPP

#include "Parser.hpp"
#include "queue"
#include <iostream>
#include <fstream>
#include <string>

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
        void init(int newNumCar, char newCar);

    public:
        /* Builders */
        Sommet(); // Default
        Sommet(int newNumCar, char newCar);
        Sommet(int newNum);

        /* Overloaded */
        Sommet& operator<<(int newData);
        
        /* Methodes */
        int maximum(int a, int b);

        bool isLeaf();

        void printPrefix();
        void print(Sommet *node);
        void printBeautifulTree(int space);
        void clean();

        /* Getters */
        int getNumCar() const;
        char getCar() const;
        Sommet* getLeft() const;
        Sommet* getRight() const;
        int getDepth();

        void ecritureHeader();
        void ecritureFichier(Sommet* node);
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
        ArbreB(Sommet *root);

        /* Overloaded */

        /* Methodes */
        bool isTreeEmpty();

        /* Getters */
        Sommet* getRoot() const;
        int getSize() const;

        /* Destructor */
        ~ArbreB();
};

#endif