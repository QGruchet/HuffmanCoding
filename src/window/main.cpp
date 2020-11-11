#include <iostream>
#include <gtkmm/main.h>
#include <gtkmm/stock.h>

#include "main.hpp"



Fenetre::Fenetre() : boutonEnregistrer(Gtk::Stock::SAVE), boutonOuvrir(Gtk::Stock::OPEN), boutonAgrandir("Agrandir"){
    //Configurer la fenêtre.
    set_position(Gtk::WIN_POS_CENTER);
    set_default_size(480, 360);
    add(boiteV);
    
    //Empêcher les boutons d'avoir le focus.
    boutonOuvrir.set_can_focus(false);
    boutonEnregistrer.set_can_focus(false);
    boutonAgrandir.set_can_focus(false);
    
    //Configurer les barres de défilement.
    barresDeDefilement.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
    barresDeDefilement.add(zoneTexte);
    
    //Ajout de widgets dans les boîtes.
    boiteV.pack_start(barresDeDefilement);
    boiteV.pack_start(boiteH, Gtk::PACK_SHRINK);
    
    boiteH.pack_start(boutonOuvrir);
	boiteH.pack_start(boutonEnregistrer);
	boiteH.pack_start(boutonAgrandir);
    
    //Connexion des signaux aux fonctions de rappel.
    boutonOuvrir.signal_clicked().connect(sigc::mem_fun(*this, &Fenetre::dialogueOuvrirFichier));
    boutonEnregistrer.signal_clicked().connect(sigc::mem_fun(*this, &Fenetre::dialogueEnregistrerFichier));
    boutonEnregistrer.signal_clicked().connect(sigc::mem_fun(*this, &Fenetre::augmenterTaille));

    show_all();
}

void Fenetre::dialogueOuvrirFichier() {
    //Création d'une boîte de dialogue d'ouverture de fichier.
    Gtk::FileChooserDialog dialogue(*this, "Ouverture d'un fichier");
    
    //Ajout de filtres.
    Glib::RefPtr<Gtk::FileFilter> filtreFichierTexte = Gtk::FileFilter::create(); //Création du filtre.
    filtreFichierTexte->set_name("Fichiers Image"); //Lui donner un nom.
    filtreFichierTexte->add_mime_type("image/png"); //Ajouter un type MIME.
    dialogue.add_filter(filtreFichierTexte); //Ajouter le filtre au dialogue.
    
    Glib::RefPtr<Gtk::FileFilter> filtreFichierCCPP = Gtk::FileFilter::create();
    filtreFichierCCPP->set_name("Fichiers C/C++");
    filtreFichierCCPP->add_mime_type("text/x-c");
    filtreFichierCCPP->add_mime_type("text/x-c++");
    filtreFichierCCPP->add_mime_type("text/x-c-header");
    dialogue.add_filter(filtreFichierCCPP);    
    
    Glib::RefPtr<Gtk::FileFilter> filtreTout = Gtk::FileFilter::create();
    filtreTout->set_name("Tous les fichiers");
    filtreTout->add_pattern("*"); //Ajout d'une expression.
    dialogue.add_filter(filtreTout);
    
    //Ajout de boutons.
    dialogue.add_button(Gtk::Stock::CANCEL, Gtk::RESPONSE_CANCEL);
    dialogue.add_button(Gtk::Stock::OPEN, Gtk::RESPONSE_OK);
    
    int resultat = dialogue.run();
    
    if(resultat == Gtk::RESPONSE_OK) {
        //Obtenir le nom du fichier.
        std::string nomFichier = dialogue.get_filename();
        ouvrirFichier(nomFichier);
    }
}

void Fenetre::dialogueEnregistrerFichier() {
    //Création d'une boîte de dialogue de sauvegarde de fichier.
    Gtk::FileChooserDialog dialogue(*this, "Sauvegarde d'un fichier", Gtk::FILE_CHOOSER_ACTION_SAVE);
    
    //Demande de confirmation lors du remplacement d'un fichier existant.
    dialogue.set_do_overwrite_confirmation();
    //Permettre la création de dossiers.
    dialogue.set_create_folders();
    
    //Ajout de boutons.
    dialogue.add_button(Gtk::Stock::CANCEL, Gtk::RESPONSE_CANCEL);
    dialogue.add_button(Gtk::Stock::SAVE, Gtk::RESPONSE_OK);
    
    int resultat = dialogue.run();
    
    if(resultat == Gtk::RESPONSE_OK) {
        Gtk::MessageDialog dialog(*this, "Sauvegarde du fichier réussie");
        dialog.run();
    }
}

void Fenetre::ouvrirFichier(std::string nomFichier) {
    std::ifstream fichier(nomFichier.c_str(), std::ios::in);
    
    std::string texte, ligne;
    if(fichier) {
        
        while(getline(fichier, ligne)) {
            texte += ligne + "\n";
        }
        
        fichier.close();
    }
    else {
        Gtk::MessageDialog dialogue(*this, "Erreur lors de l'ouverture du fichier " + nomFichier + ".", false, Gtk::MESSAGE_INFO);
        dialogue.run();
    }
    
    //Obtenir le buffer de la zone de texte.
    Glib::RefPtr<Gtk::TextBuffer> buffer = zoneTexte.get_buffer();
    buffer->set_text(texte); //Modifier le texte du buffer.
}

void Fenetre::augmenterTaille() {
	int largeur(0);
	int hauteur(0);
	get_size(largeur, hauteur);
	resize(largeur + 100, hauteur + 100);
}


int main(int argc, char *argv[])
{
   	Gtk::Main app(argc, argv);
   	Fenetre window;
   	window.show_all_children();
   	Gtk::Main::run(window);
    return 0;

}