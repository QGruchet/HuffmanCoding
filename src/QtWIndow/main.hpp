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
		QPushButton* quitter;
		QPushButton* afficher;
		QPushButton* supprimer;
		QPushButton* secret;
		QTextEdit* zoneTexte;

	public:
		Window(){

			setWindowTitle("Binary Tree");
			setBaseSize(300,300);

			zoneTexte = new QTextEdit(this);
			zoneTexte->setTextColor(Qt::green);
			zoneTexte->setFontWeight(QFont::Normal);
			//zoneTexte->setFontFamily("Yrsa Bold");
			zoneTexte->setFontPointSize(20);
			zoneTexte->setReadOnly(true);

			layout = new QVBoxLayout(this);
			setLayout(layout);

			quitter = new QPushButton("Quitter");
			connect(quitter, SIGNAL(clicked()), qApp, SLOT(quit()));

			afficher = new QPushButton("Afficher l'arbre");
			connect(afficher, SIGNAL(clicked()), this, SLOT(afficherArbre()));

			supprimer = new QPushButton("Supprimer l'arbre");
			connect(supprimer, SIGNAL(clicked()), this, SLOT(supprimerArbre()));

			secret = new QPushButton("Ne pas cliquer !");
			connect(secret, SIGNAL(clicked()), this, SLOT(secretbutton()));

			layout->addWidget(zoneTexte);
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

			QString tout = flux.readAll();
			zoneTexte->setText(tout);
			resize(1000,1000);
			zoneTexte->show();
			fichier.close();
		}

		void supprimerArbre(){
			zoneTexte->setText(nullptr);
			resize(300, 300);
			zoneTexte->show();
		}

		void secretbutton(){
			qDebug() << "QU'EST CE QUE J'AI DIS ????";
			QMessageBox::information(this, "décéption...", "QU'EST CE QUE J'AI DIS ????");
		}

};