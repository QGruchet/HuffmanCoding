#include "main.hpp"

#include <iostream>
#include <QApplication>
#include <QWidget>
#include <QPushButton>


int main(int argc, char** argv){

	QApplication app(argc, argv);

	Window w;
	w.show();
	return app.exec();
}