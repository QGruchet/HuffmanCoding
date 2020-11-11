#ifndef MAIN_HPP
#define MAIN_HPP

#include <fstream>
#include <vector>

#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/buttonbox.h>
#include <gtkmm/filechooserdialog.h>
#include <gtkmm/filefilter.h>
#include <gtkmm/main.h>
#include <gtkmm/messagedialog.h>
#include <gtkmm/scrolledwindow.h>
#include <gtkmm/stock.h>
#include <gtkmm/textbuffer.h>
#include <gtkmm/textview.h>
#include <gtkmm/window.h>

class Fenetre : public Gtk::Window {
    public :
        Fenetre();
        void dialogueOuvrirFichier();
        void dialogueEnregistrerFichier();
        void ouvrirFichier(std::string nomFichier);
        void augmenterTaille();
        
    private :
        Gtk::ScrolledWindow barresDeDefilement;
        Gtk::HButtonBox boiteH;
        Gtk::VBox boiteV;
        Gtk::Button boutonEnregistrer;
        Gtk::Button boutonOuvrir;
        Gtk::Button boutonAgrandir;
        Gtk::TextView zoneTexte;
};

#endif