#include <algorithm>
#include <iostream>
using namespace std;

#include "tablahash.h"

// Constructor
TablaHash::TablaHash (int size=11):buffer(size) {
			longitudActual = 0;
}
// Funcion Hash usando modulo
int TablaHash::funcionHash (int &x) {
		int valorHash = x % buffer.size ();
		if (valorHash < 0)
			valorHash = valorHash + buffer.size ();
		return valorHash;
}

// Adicion
bool TablaHash::adicionar (int x) {
		int k=funcionHash (x);
		list <int> &ls = buffer [k];
		ls.push_back (x);

		longitudActual++;
		return true;
		

	// Rehash
	if (longitudActual > buffer.size ())
		rehash ();

	return true;
}

// Elimnacion (incompleta)
bool TablaHash:: eliminar (int & x) { 
}

// Limpia la tabla (limpia las listas)
void TablaHash::limpiar() {
	for (int i=0; i < buffer.size();i++)
		buffer [i].clear ();
}

// Exite elemento
bool TablaHash::existe (int x) {
		int k=funcionHash (x);
		list <int> ls = buffer [k];

		std::list<int>::iterator findIter = std::find(ls.begin(), ls.end(), x);

		if (findIter!=ls.end())
			return true;
		else
			return false;
}

// Muestra los elementos
void TablaHash::mostrarse () {
	typename list<int> ::iterator itr;
	for (int i=0; i < buffer.size (); i++) {
		list<int> & ls = buffer [i];
		if (ls.size() > 0) {
			for (itr=ls.begin (); itr!= ls.end (); itr++)
					cout << *itr << ", ";
			cout << endl;
		}
	}
}