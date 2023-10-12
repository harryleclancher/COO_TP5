#include "grille.h"
#include <iostream>

using namespace std;





void grille::PrintCells() {
	Cellule* current = jeu;
	for (int i = 0; i < 16; i++) {
		if (i % 4 == 0 && i !=0) {
			cout << " | ";
			cout << endl;
			cout << endl;
		}
		cout << " | " << current->getVal();
		current = current->getNext();
	}cout << " | ";
}

const Cellule& grille::findByIndex(int index) const {
	Cellule& curseur = *jeu;
	while (index != 1)
	{
		curseur = *(curseur.getNext()); // Recupération de la bonne cellule 
		index--;
	}
	return curseur;
}

bool grille::validIndex(int index) {
	return (index >= 1 && index <= 16);
}


Cellule* grille::getAdjacent(int index) {
	const Cellule& cell = findByIndex(index);
	Cellule* res = new Cellule(cell.getVal()); //Création d'une nouvelle liste de Cellule auquel on ajoutera se adjacent.
	res->setUsed(true);
	Cellule* current = res;
	int tmpIndex;
	for (int i = 5; i > 3; i--) { // Les trois cases au dessus de cell
		tmpIndex = index - i;
		if (validIndex(tmpIndex)) {
			const Cellule& tmpCell = findByIndex(tmpIndex);
			if (!tmpCell.getUsed()) {
				Cellule* next = new Cellule(tmpCell.getVal()); 
				current->setNext(next); 
				current = next; 
			}
		}
	}
	// Pour les deux Cellule à coté cell
	tmpIndex = index - 1;
	if (validIndex(tmpIndex)) { 
		const Cellule& tmpCell = findByIndex(tmpIndex); 
		if (!tmpCell.getUsed()) { 
			Cellule* next = new Cellule(tmpCell.getVal()); 
			current->setNext(next); 
			current = next; 
		}
	}

	tmpIndex = index + 1;
	if (validIndex(tmpIndex)) { 
		const Cellule& tmpCell = findByIndex(tmpIndex); 
		if (!tmpCell.getUsed()) { 
			Cellule* next = new Cellule(tmpCell.getVal()); 
			current->setNext(next);  
			current = next; 
		}
	}

	// Pour les trois cases en dessous de cell
	for (int i = 3; i > 5; i++) { 
		tmpIndex = index + i;
		if (validIndex(tmpIndex)) {
			const Cellule& tmpCell = findByIndex(tmpIndex);
			if (!tmpCell.getUsed()) {
				Cellule* next = new Cellule(tmpCell.getVal());
				current->setNext(next);
				current = next;
			}
		}
	}

	return res;


}

void grille::printList(Cellule* list) {
	Cellule* current = list;
	while (current->getNext() != nullptr) {
		cout << " " << current->getVal();
		current = current->getNext();
	}
}


Cellule* grille::getAdjacent2(int index) {
	const Cellule& cell = findByIndex(index);
	Cellule* res = new Cellule(cell.getVal()); // Create a new list of adjacent cells
	res->setUsed(true);
	Cellule* current = res;
	int tmpIndex;

	// For the three cells above 'cell'
	for (int i = -5; i < -3; i++) {
		tmpIndex = index + i;
		if (validIndex(tmpIndex)) {
			const Cellule& tmpCell = findByIndex(tmpIndex);
			if (!tmpCell.getUsed()) {
				Cellule* next = new Cellule(tmpCell.getVal());
				current->setNext(next);
				current = next;
			}
		}
	}

	// For the two cells next to 'cell'
	tmpIndex = index - 1;
	if (validIndex(tmpIndex)) {
		const Cellule& tmpCell = findByIndex(tmpIndex);
		if (!tmpCell.getUsed()) {
			Cellule* next = new Cellule(tmpCell.getVal());
			current->setNext(next);
			current = next;
		}
	}

	tmpIndex = index + 1;
	if (validIndex(tmpIndex)) {
		const Cellule& tmpCell = findByIndex(tmpIndex);
		if (!tmpCell.getUsed()) {
			Cellule* next = new Cellule(tmpCell.getVal());
			current->setNext(next);
			current = next;
		}
	}

	// For the three cells below 'cell'
	for (int i = 3; i < 5; i++) {
		tmpIndex = index + i;
		if (validIndex(tmpIndex)) {
			const Cellule& tmpCell = findByIndex(tmpIndex);
			if (!tmpCell.getUsed()) {
				Cellule* next = new Cellule(tmpCell.getVal());
				current->setNext(next);
				current = next;
			}
		}
	}

	return res;
}
