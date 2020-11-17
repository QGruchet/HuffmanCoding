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


class Window : public QWidget {

	Q_OBJECT

	private:
		QVBoxLayout* layout;
		QVBoxLayout* infoArbre;
		QTextEdit* zoneInfo;
		QPushButton* quitter;
		QPushButton* afficher;
		QPushButton* supprimer;
		QPushButton* secret;
		QTextEdit* zoneTexte;
		QPushButton* test;

	public:
		Window(){
			// On change le titre et la taille de la fenetre principale 
			setWindowTitle("Binary Tree");
			setBaseSize(360,240);
			
			// On creer la zone principale des widgets
			layout = new QVBoxLayout(this);
			setLayout(layout);

			zoneTexte = new QTextEdit(this);
			zoneTexte->setTextColor(Qt::white);
			zoneTexte->setFontWeight(QFont::Normal);
			// zoneTexte->setFontFamily("Yrsa Bold");
			zoneTexte->setFontPointSize(20);
			zoneTexte->setReadOnly(true);	//permet d'interdire l'ecriture dans le layout

			// On creer la zone de texte qui affiche l'arbre
			infoArbre = new QVBoxLayout(this);
			infoArbre->setAlignment(Qt::AlignRight);
			setLayout(infoArbre);
			layout->addLayout(infoArbre);

			zoneInfo = new QTextEdit(this);
			zoneInfo->setFontPointSize(30);


			/*********** CREATION DES BOUTON ***********/
			// On connect le bouton a une fonction
			test = new QPushButton("Afficher les tests");
			connect(test, SIGNAL(clicked()), this, SLOT(afficherTest()));

			quitter = new QPushButton("Quitter");
			connect(quitter, SIGNAL(clicked()), qApp, SLOT(quit()));

			afficher = new QPushButton("Afficher l'arbre");
			connect(afficher, SIGNAL(clicked()), this, SLOT(afficherArbre()));

			supprimer = new QPushButton("Nettoyer la zone");
			connect(supprimer, SIGNAL(clicked()), this, SLOT(supprimerArbre()));

			secret = new QPushButton("Ne pas cliquer !");
			connect(secret, SIGNAL(clicked()), this, SLOT(secretbutton()));
			/************* FIN CREATION *************/

			infoArbre->addWidget(zoneInfo);
			layout->addWidget(zoneTexte);
			layout->addWidget(test);
			layout->addWidget(afficher);
			layout->addWidget(supprimer);
			layout->addWidget(secret);
			layout->addWidget(quitter);

		}

		~Window(){
			delete zoneTexte;
			delete quitter;
			delete afficher;
			delete supprimer;
			delete secret;
			delete layout;
		}

	public slots:
		void afficherArbre(){
			//on ouvre le fichier
			QString fileName = "src/txtQT/binary.txt";
			QFile fichier(fileName);
			fichier.open(QIODevice::ReadOnly | QIODevice::Text);
			QTextStream flux(&fichier);

			//on lit la premiere line qui correspond a la racine
			QString ligne;
			ligne = flux.readLine();
			int compt = 0;
			//on compte le nombre de ligne
			QString ligne2;
			while(!flux.atEnd()){
				ligne2 = flux.readLine();
				compt++;
			}
			
			QString aff("Racine de notre arbre : " + ligne + "\nNombre de noeud : " + QString::number(compt));
			//on ajoute le texte dans le layout
			zoneInfo->setText(aff);
			fichier.close();

			//On affiche l'arbre
			QFile fichier2(fileName);
			fichier.open(QIODevice::ReadOnly | QIODevice::Text);
			QTextStream flux2(&fichier);

			QString tout = flux2.readAll();
			zoneTexte->setText(tout);
			resize(720,480);
			zoneTexte->show();
			fichier2.close();
		}

		void supprimerArbre(){
			zoneTexte->setText(nullptr);
			zoneInfo->setText(nullptr);
			resize(360, 240);
			zoneTexte->show();
		}

		void secretbutton(){
			qDebug() << "QU'EST CE QUE J'AI DIS ????";
			QMessageBox::information(this, "décéption...", "QU'EST CE QUE J'AI DIS ????");
		}

		void afficherTest(){
			QString fileName = "src/txtQT/resultTest.txt";
			QFile fichier(fileName);
			fichier.open(QIODevice::ReadOnly | QIODevice::Text);
			QTextStream flux(&fichier);

			QString tout = flux.readAll();
			zoneTexte->setText(tout);
			resize(720,480);
			zoneTexte->show();
			fichier.close();
		}

};

#endif