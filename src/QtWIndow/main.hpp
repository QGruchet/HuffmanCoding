#pragma once

#include <iostream>
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QFile>
#include <QTextEdit> 
#include <QLabel>
#include <QColor>
#include <QDebug>
#include <QMessageBox>


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

			setWindowTitle("Binary Tree");
			setBaseSize(300,300);
			
			layout = new QVBoxLayout(this);
			setLayout(layout);

			zoneTexte = new QTextEdit(this);
			zoneTexte->setTextColor(Qt::white);
			zoneTexte->setFontWeight(QFont::Normal);
			//zoneTexte->setFontFamily("Yrsa Bold");
			zoneTexte->setFontPointSize(20);
			zoneTexte->setReadOnly(true);

			infoArbre = new QVBoxLayout(this);
			infoArbre->setAlignment(Qt::AlignRight);
			setLayout(infoArbre);
			layout->addLayout(infoArbre);

			zoneInfo = new QTextEdit(this);
			zoneInfo->setFontPointSize(30);


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
			
			QString fileName = "src/out/binary.txt";
			QFile fichier(fileName);
			fichier.open(QIODevice::ReadOnly | QIODevice::Text);
			QTextStream flux(&fichier);

			QString ligne;
			ligne = flux.readLine();
			int compt = 1;
			QString ligne2;
			while(!flux.atEnd()){
				ligne2 = flux.readLine();
				compt++;
			}
			QString aff("Racine de notre arbre : " + ligne + "\nNombre de noeud : " + QString::number(compt));
			zoneInfo->setText(aff);
			fichier.close();

			QFile fichier2(fileName);
			fichier.open(QIODevice::ReadOnly | QIODevice::Text);
			QTextStream flux2(&fichier);

			QString tout = flux2.readAll();
			zoneTexte->setText(tout);
			resize(1000,1000);
			zoneTexte->show();
			fichier2.close();

			
		}

		void supprimerArbre(){
			zoneTexte->setText(nullptr);
			zoneInfo->setText(nullptr);
			resize(300, 300);
			zoneTexte->show();
		}

		void secretbutton(){
			qDebug() << "QU'EST CE QUE J'AI DIS ????";
			QMessageBox::information(this, "décéption...", "QU'EST CE QUE J'AI DIS ????");
		}

		void afficherTest(){
			QString fileName = "src/out/result.txt";
			QFile fichier(fileName);
			fichier.open(QIODevice::ReadOnly | QIODevice::Text);
			QTextStream flux(&fichier);

			QString tout = flux.readAll();
			zoneTexte->setText(tout);
			resize(1000,1000);
			zoneTexte->show();
			fichier.close();
		}

};