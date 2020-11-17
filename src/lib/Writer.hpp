#ifndef Writer_HPP
#define Writer_HPP

#include "Tree.hpp"
#include "../test/Test.hpp"

class Writer
{
	private:
		/* Data */
		std::string file;

	public:
		/* Constructor */
		Writer();
		Writer(std::string);

		/* Methodes */
		void writeInFile(std::string);
		void writeBeautifulTreeInFile(Sommet*, int);
		void writeResultAllTests();
};

#endif