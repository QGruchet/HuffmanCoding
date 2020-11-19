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
	/** Function : Window().
	 * Description : Default constructor for window. It put layout, button, and text area inside the window.
	 * */
		Window(){
			// Setup window title, size, and fond
			setWindowTitle("Binary Tree");
			setBaseSize(480,720);
			setFont(QFont("Arial", 10));
	
			// Setup layout
			layout = new QVBoxLayout(this);
			setLayout(layout);

			//Add some esthetic function to the text
			printText = new QTextEdit(this);
			printText->setTextColor(Qt::white);
			printText->setFontWeight(QFont::Normal);
			printText->setFontPointSize(10);
			printText->setReadOnly(true);	// USer can't write in the layout
			printText->setStyleSheet("background-color: dark-grey;");

			printInfo = new QTextEdit(this);
			printInfo->setFontPointSize(10);
			printInfo->setTextColor(Qt::white);
			printInfo->setStyleSheet("background-color: dark-grey;");

			// Create place for write the tree
			infoTree = new QVBoxLayout(this);
			infoTree->setAlignment(Qt::AlignRight);
			setLayout(infoTree);
			layout->addLayout(infoTree);

			


			/*********** CREATION OF BUTTON ***********/
			// Link button to function
			test = new QPushButton("Print Tests", this);
			connect(test, SIGNAL(clicked()), this, SLOT(printTest()));

			quit = new QPushButton("Quit");
			connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));

			print = new QPushButton("Print Tree");
			connect(print, SIGNAL(clicked()), this, SLOT(printTree()));

			del = new QPushButton("Clean");
			connect(del, SIGNAL(clicked()), this, SLOT(delArbre()));

			secret = new QPushButton("Don't click");
			connect(secret, SIGNAL(clicked()), this, SLOT(secretbutton()));


			// Resize and replaced button
			int tailleTestX = test->fontMetrics().width("Print Tests") + 10;
			int tailleTestY = test->fontMetrics().height();
			const QSize sizeTest = QSize(tailleTestX + 100, tailleTestY + 15);
			test->setFixedSize(sizeTest);

			int tailleQuitX = quit->fontMetrics().width("Print Tests") + 10;
			int tailleQuitY = quit->fontMetrics().height();
			const QSize sizeQuit = QSize(tailleQuitX + 100, tailleQuitY + 15);
			quit->setFixedSize(sizeQuit);

			int taillePrintX = print->fontMetrics().width("Print Tests") + 10;
			int taillePrintY = print->fontMetrics().height();
			const QSize sizePrint = QSize(taillePrintX + 100, taillePrintY + 15);
			print->setFixedSize(sizePrint);

			int tailleDelX = del->fontMetrics().width("Print Tests") + 10;
			int tailleDelY = del->fontMetrics().height();
			const QSize sizeDel = QSize(tailleDelX + 100, tailleDelY + 15);
			del->setFixedSize(sizeDel);

			int tailleSecretX = secret->fontMetrics().width("Print Tests") + 10;
			int tailleSecretY = secret->fontMetrics().height();
			const QSize sizeSecret = QSize(tailleSecretX + 100, tailleSecretY + 15);
			secret->setFixedSize(sizeSecret);

			/************* FIN CREATION *************/

			//Adding widget to the main widget
			infoTree->addWidget(printInfo);
			layout->addWidget(printText);
			layout->addWidget(test, 0, Qt::AlignCenter);
			layout->addWidget(print, 0, Qt::AlignCenter);
			layout->addWidget(del, 0, Qt::AlignCenter);
			layout->addWidget(secret, 0, Qt::AlignCenter);
			layout->addWidget(quit, 0, Qt::AlignCenter);
		}
		/** Function : ~Window().
	 * Description : Destructor for Window.
	 * */
		~Window(){
			delete test;
			delete quit;
			delete print;
			delete del;
			delete secret;
			delete infoTree;
			delete printText;
			delete printInfo;
			delete layout;
		}

	public slots:
	/** Function : printTree().
	 * Description : Print the tree and his informations in the window.
	 * */
		void printTree(){
			// Open file for read the tree
			QString fileName = "src/txtQT/binary.txt";
			QFile fichier(fileName);
			fichier.open(QIODevice::ReadOnly | QIODevice::Text);
			QTextStream flux(&fichier);

			// Read the root, number of node, min and max
			QString depth = flux.readLine();
			QString valRoot = flux.readLine();
			QString numNode = flux.readLine();
			QString min = flux.readLine();
			QString max = flux.readLine();
			
			QString aff("Some informations about the tree : \n\t > Root of the tree : " + valRoot + 
						"\n\t > Depth of the tree : " + depth +
						"\n\t > Number of node : " + numNode + 
						"\n\t > Minimum of tree : " + min + 
						"\n\t > Maximum of tree : " + max);
			
			// Set the layout with a text
			printInfo->setText(aff);
			QString tout = flux.readAll();

			// Print all informations of the tree in the texts zone
			printText->setText(tout);
			resizeFull();
			printText->show();
			fichier.close();
		}
		/** Function : delArbre().
		 * Description : Clean all the window.
		 * */
		void delArbre(){
			// Clear tree and info area
			printText->setText(nullptr);
			printInfo->setText(nullptr);
			resizeFull();
			printText->show();
		}
		/** Function : secretButton().
		 * Description : Configure the secret button.
		 * */
		void secretbutton(){
			// Just a little features 
			qDebug() << "WHAT DID I JUST SAY ????";
			QMessageBox::information(this, "Disappointment...", "WHAT DID I JUST SAY ????");
		}
		/** Function : printTest().
		 * Description : Print all test in the window.
		 * */
		void printTest(){
			// Open file for read test
			QString fileName = "src/txtQT/resultTest.txt";
			QFile fichier(fileName);
			fichier.open(QIODevice::ReadOnly | QIODevice::Text);
			QTextStream flux(&fichier);
			QString tout = flux.readAll();

			// Print all the test in the tests zone
			printText->setText(tout);
			resizeFull();
			printText->show();
			fichier.close();
		}

		/** Function : resizeFull().
		 * Description : Resize the window with the size of current display.
		 * */
		void resizeFull()
		{
			// Resize the main window depending on the size display
			int width = QApplication::desktop()->width();
			int height = QApplication::desktop()->height();
			if(width > 1920) {
				width = 1920;
			}
			if(height > 1080) {
				height = 1080;
			}
			resize(height/1.5, width/3.5);
		}
};

#endif