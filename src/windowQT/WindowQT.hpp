#ifndef WindowQT_HPP
#define WindowQT_HPP

#include <iostream>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtCore/QFile>
#include <QtWidgets/QTextEdit> 
#include <QtWidgets/QLabel>
#include <QtGui/QColor>
#include <QtCore/QDebug>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QDesktopWidget>

class Window : public QWidget {

	Q_OBJECT
	//1080 720
	private:
		QVBoxLayout* layout;
		QVBoxLayout* infoTree;
		QTextEdit* printInfo;
		QPushButton* quit;
		QPushButton* print;
		QPushButton* del;
		QPushButton* secret;
		QTextEdit* printText;
		QPushButton* test;

	public:
		Window(){
			// Setup window title, size, and fond
			setWindowTitle("Binary Tree");
			setBaseSize(480,720);
			setFont(QFont("Arial", 10));
	
			// Setup layout
			layout = new QVBoxLayout(this);
			setLayout(layout);

			printText = new QTextEdit(this);
			printText->setTextColor(Qt::white);
			printText->setFontWeight(QFont::Normal);
			printText->setFontPointSize(10);
			printText->setReadOnly(true);	// USer can't write in the layout
			printText->setStyleSheet("background-color: dark-grey;");

			// Create place for write the tree
			infoTree = new QVBoxLayout(this);
			infoTree->setAlignment(Qt::AlignRight);
			setLayout(infoTree);
			layout->addLayout(infoTree);

			printInfo = new QTextEdit(this);
			printInfo->setFontPointSize(10);
			printInfo->setTextColor(Qt::white);
			printInfo->setStyleSheet("background-color: dark-grey;");


			/*********** CREATION DES BOUTON ***********/
			// Link button to function
			test = new QPushButton("Print Tests", this);
			connect(test, SIGNAL(clicked()), this, SLOT(printTest()));
			int tailleTestX = test->fontMetrics().width("Print Tests") + 10;
			int tailleTestY = test->fontMetrics().height();
			test->resize(tailleTestX, tailleTestY);

			quit = new QPushButton("Quit");
			connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
			int tailleQuitX = test->fontMetrics().width("Print Tests") + 10;
			int tailleQuitY = test->fontMetrics().height();

			print = new QPushButton("Print Tree");
			connect(print, SIGNAL(clicked()), this, SLOT(printTree()));
			int taillePrintX = test->fontMetrics().width("Print Tests") + 10;
			int taillePrintY = test->fontMetrics().height();

			del = new QPushButton("Clean");
			connect(del, SIGNAL(clicked()), this, SLOT(delArbre()));
			int tailleDelX = test->fontMetrics().width("Print Tests") + 10;
			int tailleDelY = test->fontMetrics().height();

			secret = new QPushButton("Don't click");
			connect(secret, SIGNAL(clicked()), this, SLOT(secretbutton()));
			int tailleSecretX = test->fontMetrics().width("Print Tests") + 10;
			int tailleSecretY = test->fontMetrics().height();

			/************* FIN CREATION *************/

			infoTree->addWidget(printInfo);
			layout->addWidget(printText);
			layout->addWidget(test);
			layout->addWidget(print);
			layout->addWidget(del);
			layout->addWidget(secret);
			layout->addWidget(quit);
		}

		~Window(){
			delete printText;
			delete quit;
			delete print;
			delete del;
			delete secret;
			delete layout;
		}

	public slots:
		void printTree(){
			// Open file for read the tree
			QString fileName = "src/txtQT/binary.txt";
			QFile fichier(fileName);
			fichier.open(QIODevice::ReadOnly | QIODevice::Text);
			QTextStream flux(&fichier);

			// Read the root, numer of node, min and max
			QString valRoot = flux.readLine();
			QString depth = flux.readLine();
			QString numNode = flux.readLine();
			QString min = flux.readLine();
			QString max = flux.readLine();
			
			QString aff("Some informations about the tree : \n\t > Root of the tree : " + valRoot + 
						"\n\t > Depth of the tree" + depth +
						"\n\t > Number of node : " + numNode + 
						"\n\t > Minimum of tree : " + min + 
						"\n\t > Maximum of tree : " + max);
			
			// Set the layout with a text
			printInfo->setText(aff);
			QString tout = flux.readAll();

			//test colorized text
			/*for (int i = 0; i < tout.length(); ++i)
			{
				if(tout.at(i) == '[' && tout.at(i + 1) == 'O'){
					for (int i; i  < i + 2; ++i)
					{
						printText->setHtml(QString("style=color:red"));
					}
				}
				else if(tout.at(i) == '[' && tout.at(i) == 'F'){

				}
			}
			*/
			printText->setText(tout);
			resizeFull();
			printText->show();
			fichier.close();
		}

		void delArbre(){
			printText->setText(nullptr);
			printInfo->setText(nullptr);
			resizeFull();
			printText->show();
		}

		void secretbutton(){
			qDebug() << "WHAT DID I JUST SAY ????";
			QMessageBox::information(this, "Disappointment...", "WHAT DID I JUST SAY ????");
		}

		void printTest(){
			QString fileName = "src/txtQT/resultTest.txt";
			QFile fichier(fileName);
			fichier.open(QIODevice::ReadOnly | QIODevice::Text);
			QTextStream flux(&fichier);

			QString tout = flux.readAll();
			printText->setText(tout);
			printInfo->setText(nullptr);
			resizeFull();
			printText->show();
			fichier.close();
		}

		void resizeFull()
		{
			int width = QApplication::desktop()->width();
			if(width > 1920) {
				width = 1920;
			}
			int height = QApplication::desktop()->height();
			resize(height/2, width/4);
		}
};

#endif