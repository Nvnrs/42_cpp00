#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"
#include <iostream>
#include <string>

// • PhoneBook
// ◦ Représente le répertoire.
// ◦ Contient un tableau de contacts.
// ◦ Peut enregistrer 8 contacts maximum. Si l’utilisateur tente d’ajouter un 9ème
// contact, remplacez le plus ancien par celui-ci.
// ◦ Notez que l’allocation dynamique est interdite


// • ADD : enregistrer un nouveau contact
// ◦ Si l’utilisateur entre cette commande, le programme lui demande de remplir
// une par une les informations du nouveau contact. Une fois tous les champs
// complétés, le nouveau contact est ajouté au répertoire.
// ◦ Un contact possède les champs suivants : first name (prénom), last name
// (nom de famille), nickname (surnom), phone number (numéro de téléphone),
// et darkest secret (son plus lourd secret). Les champs d’un contact enregistré ne
// peuvent être vides.

// • SEARCH : affiche le contact demandé
// ◦ Affiche les contacts enregistrés sous la forme d’une liste de 4 colonnes : index,
// first name, last name et nickname.
// ◦ Chaque colonne doit faire 10 caractères de long. Elles doivent être séparées
// par un pipe (’|’). Leur texte est aligné à droite. Si le texte dépasse la largeur
// de la colonne, il faut le tronquer et remplacer le dernier caractère affiché par
// un point (’.’).
// ◦ Ensuite, le programme demande à l’utilisateur d’entrer l’index du contact à afficher. Si l’index ou son format sont incorrects, gérez cela de manière pertinente.
// Sinon, affichez les informations du contact, une par ligne.

// • EXIT
// ◦ Le programme quitte et les contacts sont perdus à jamais !

#include <cstdlib>

#define CONTACTS_MAX 8

class PhoneBook
{
	private :
		int 	index;
		Contact	array[CONTACTS_MAX];

	public :

		PhoneBook()
		{
			index = -1;
		}

		void push(Contact new_contact)
		{
			this->index++;
			if (this->index == CONTACTS_MAX -1)
				this->index = 0;
			this->array[this->index] = new_contact;			
		}

		void print();
		void search();
		Contact *find(int index);

		bool length();
		void	add();
	// register()
};
#endif