#pragma once
#include "Cellule.h"
#include <vector>


using namespace std;

class grille
{
private:

	int taille;
	Cellule* jeu;// pointe sur la la première cellule 





public:

	grille() {
		jeu = new Cellule();
		Cellule* current = jeu;
		taille = 4;

		for (int i = 0; i<15; i++) {
			Cellule* tmp = new Cellule();
			current->setNext(tmp);
			current = tmp;
		}
	}

	~grille() {
		Cellule* tmp = jeu;
		while (tmp)
		{
			Cellule* next = tmp->getNext();
			delete tmp;
			tmp = next;

		}
	}

	void PrintCells();
	const Cellule& findByIndex(int) const;
	bool validIndex(int);
	Cellule* getAdjacent(int index); // Renvoie une liste de Cellule adjacente à partir d'un index dans la grille
	void printList(Cellule*); // Print une list d'adjacent 
	Cellule* getAdjacent2(int index);

};

