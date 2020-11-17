#include "WindowQT.hpp"

#include <QtWidgets/QApplication>

int main(int argc, char** argv){

	QApplication app(argc, argv);

	Window w;
	w.show();
	return app.exec();
}