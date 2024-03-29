
// nodo.h
// Autores: Gabriel Barboza Carvajal , Jorge Canales Espinoza , Joan Corea Aguilar
// Descripci�n: clase nodo con la cual se va a crear el la lista del interger , contiene un vector con cuatro celdas tipo short...

#ifndef NODO_H_
#define NODO_H_
#include"vector.h"
#include<iostream>
using namespace std;

class nodo {   // nodo gen�rico que genera nodos concretos
private:

	vector* vec;         // Flecha que a Futuro ser� objeto din�mico.(cualquier tipo)-		dato
	nodo* sig;    // Flecha que ver� a futuro otro nodo.(cualquier tipo de dato)-	signodo
	nodo* ant;    // Flecha que ver� a futuro otro nodo.(cualquier tipo de dato)-	signodo

	short carry = 0;


public:

	void set_carry(short c)
	{
		carry = c;
	}

	short get_carry() {
		return carry;
	}

	nodo();
	nodo(vector* v);

	nodo& operator = (nodo& a);

	//Mutadores

	void setVec(vector* v);
	void setSig(nodo*);
	void setAnt(nodo*);

	//Accesesores

	vector* getPtr();
	nodo* getSig();
	nodo* getAnt();

};

#endif