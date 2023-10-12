#pragma once
#include <cstdlib>

using namespace std;

class Cellule
{
private:
	char val;
	bool used;
	Cellule* next;
	
public:

	Cellule() {
		int randNum = int('a') + rand() % 26;
		val = (char)randNum;
		used = false;
		next = nullptr;
	}


	//Constructeur permettant de faire des test 
	Cellule(char my_val) {
		val = my_val; 
		used = false;
		next = nullptr;
	}

	Cellule(Cellule& cell) {
		val = cell.getVal();
		used = cell.getUsed();
		next = nullptr;
	}



	char getVal() const {
		return val;
	}

	bool getUsed() const {
		return used;
	}

	Cellule* getNext() {
		return next;
	}


	void setUsed(bool b) {
		used = b;
	}

	void setNext(Cellule* my_cell) {
		next = my_cell;
	}



};

