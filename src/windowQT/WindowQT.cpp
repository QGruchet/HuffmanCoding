/**
 * WindowQT.cpp : You can found here all functions implemented for the graphic interface.
 * Author : Quentin.
 * */
#include "WindowQT.hpp"

#include <QtWidgets/QApplication>

int main(int argc, char** argv){

	QApplication app(argc, argv);

	Window w;
	w.show();
	return app.exec();
}