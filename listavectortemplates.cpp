#include <vector>
#include <iostream>
#include <stdlib.h>

using namespace std;

template <class T>

class Lista : public vector <T>{
	public:
		Lista ();
		//~Lista();
		void adicionar (T elem);
		T eliminar(int pos);
		void mostrar();
		int longitud();
		void insertar(int pos, T elem);
		int buscar(T elem);
		T getElemento(int pos);
		void setElemento(T elem, int pos);
};


template <class T>
Lista <T>::Lista():vector<T>(){}


template <class T>
void Lista <T>::adicionar (T elem){
	this -> push_back (elem);
}


template <class T>
T Lista <T>::eliminar (int pos){
	T elem = this->at(pos);
	this->erase(this->begin()+pos);
	return elem;
}


template <class T>
void Lista <T>::mostrar(){
	int n = this->size();
	for(int i=0; i<n;i++)
		cout << this->at(i) << " ";
	cout << endl;
}


template <class T>
int Lista <T>::longitud(){
	int n = this->size();
	return n;
}


template <class T>
void Lista <T>::insertar(int pos, T elem){
	this->insert (this->begin() + pos, elem);
}


template <class T>
int Lista <T>::buscar(T elem){
	int n = this->size ();
	for (int i=0; i < n; i++){
		if(elem==this->at (i)){
			cout<< "El elemento a buscar es: "<< elem<<" y esta en en la posicion: "<<i<<endl;
		} 
	}
}



template <class T>
T Lista <T>::getElemento(int pos){
	T elem = this->at(pos);
	return elem;
}


template <class T>
void Lista <T>::setElemento(T elem, int pos){
	this->at(pos)=elem;
}