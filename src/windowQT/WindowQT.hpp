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

#define middleWinX 480
#define middleWinY 720
#define littleWinX middleWinX/2
#define littleWinY middleWinY/2


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
			// On change le titre et la taille de la fenetre principale 
			setWindowTitle("Binary Tree");
			setBaseSize(littleWinX,littleWinY);
			setFont(QFont("Arial", 10));
	
			// On creer la zone principale des widgets
			layout = new QVBoxLayout(this);
			setLayout(layout);

			printText = new QTextEdit(this);
			printText->setTextColor(Qt::white);
			printText->setFontWeight(QFont::Normal);
			// printText->setFontFamily("Yrsa Bold");
			printText->setFontPointSize(10);
			printText->setReadOnly(true);	//permet d'interdire l'ecriture dans le layout
			printText->setStyleSheet("background-color: dark-grey;");

			// On creer la zone de texte qui affiche l'arbre
			infoTree = new QVBoxLayout(this);
			infoTree->setAlignment(Qt::AlignRight);
			setLayout(infoTree);
			layout->addLayout(infoTree);

			printInfo = new QTextEdit(this);
			printInfo->setFontPointSize(10);
			printInfo->setTextColor(Qt::white);
			printInfo->setStyleSheet("background-color: dark-grey;");


			/*********** CREATION DES BOUTON ***********/
			// On connect le bouton a une fonction
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
			//on ouvre le fichier
			QString fileName = "src/txtQT/binary.txt";
			QFile fichier(fileName);
			fichier.open(QIODevice::ReadOnly | QIODevice::Text);
			QTextStream flux(&fichier);

			//on lit la premiere line qui correspond a la racine
			QString ligne;
			ligne = flux.readLine();
			int compt = 0;
			int min = 1000;
			int max = 0;
			bool ok;
			QChar dd = '0';
			//on compte le nombre de ligne
			QString ligne2;
			while(!flux.atEnd()){
				ligne2 = flux.readLine();
				compt++;
				for (int i = 0; i < ligne2.length(); ++i)
				{
					QString pl = ligne2.at(i);
					if(pl.toInt(&ok, 10) < min){
						min = pl.toInt(&ok, 10);
					}
					else if(max < pl.toInt(&ok, 10)){
						max = pl.toInt(&ok, 10);
					}
				}

			}
			
			QString aff("Root of the tree : " + ligne + 
						"\nNumber of node : " + QString::number(compt+1) + 
						"\nMinimum of tree : " + QString::number(min) + 
						"\nMaximum of tree : " + QString::number(max));
			
			//on ajoute le texte dans le layout
			printInfo->setText(aff);
			fichier.close();

			//On affiche l'arbre
			QFile fichier2(fileName);
			fichier.open(QIODevice::ReadOnly | QIODevice::Text);
			QTextStream flux2(&fichier);
			QString tout = flux2.readAll();
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
			fichier2.close();


		}

		void delArbre(){
			printText->setText(nullptr);
			printInfo->setText(nullptr);
			resizeHalf();
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
			int height = QApplication::desktop()->height();
			resize(width/3, height/2);
		}

		void resizeHalf(){
			int width = QApplication::desktop()->width();
			int height = QApplication::desktop()->height();
			resize(width/6, height/3);
		}
};

#endif