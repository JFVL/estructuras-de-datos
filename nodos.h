#ifndef __NODOS_H__		
#define __NODOS_H__

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>


using namespace std;
struct nodo{
	int data;
	nodo *next;
};

//<template class><typename T> solo cambiar todos los int por T
class Lista{
	protected:
		nodo *head, *tail;
		nodo *crearNodo(int valor){
			nodo *n;
			n -> data = valor;
			n -> next = NULL;
		}
	public:
		//template <class T>
		Lista(){
			head = tail = NULL;
		}
		bool estaVacia(){
			return(head == NULL && tail == NULL);
		}
		void adicionarFinal(int valor){
			nodo *n = crearNodo(valor);
			if(estaVacia())
				head = tail = n;
			else
				tail -> next = n;
				tail = n;
		}
		void mostrarse(){
			nodo *tmp;
			tmp = head;
			while(tmp != NULL)
				cout<<tmp -> data << ",";
				tmp = tmp -> next;
		}
		int longitud(){
			int k=0;
			nodo *tmp;
			tmp = head;
			while(tmp != NULL){
				cout<< tmp->data<<",";
				tmp = tmp -> next;
				k++;
			}
			return k;
		}
		void insertar(int valor, int pos){
			nodo *n = crearNodo(valor);
			if(pos == 1){
				n -> next = head;
				head = n;
			}
			else{
				if(pos ==longitud()-1){
					adicionarFinal(valor);
				}
				else{
					int k = 0;
					nodo* tmp = head;
					while (k < pos){
						k++;
						tmp = tmp->next;
						n -> next = tmp -> next;
						tmp->next = n;
					}
				}
			}		
		}
		int buscarElemento(int valor){
			if(estaVacia()){
				return -1;
			}
			else{
				nodo* t = head;
				int i = 1;
				while(i<longitud()){
					i++;
					if(t->data==valor){
						return i;
					}
					else{
						t = t->next;
					}
					return -1;
				}
			}
		}
		bool existeElemento(int valor){
			if(buscarElemento(valor) != -1)
				return true;
			else{
				return false;
			}
		}
		void eliminarPrimero(int pos){

			nodo *tmp=head;
			if(pos==1){
				tmp = head -> next;
				delete(tmp);
			}	
			else{
				int pos = longitud();
				tmp = tail;
			}
		}
		void eliminar(int pos){
			nodo *tmp = head;
			if(pos==1){
				tmp = head->next;
			}
			else{
				nodo* tmp = head;
				int i = 0;
				while(i<pos-1){
					i++;
				}
				tmp = tmp->next;
				if(pos != longitud()-1){
					nodo* x = tmp -> next;
					tmp->next = x->next;
					delete(x);
				}
				else{
					delete(tmp->next);
					tail = tmp;
					tmp->next = NULL;
				}
			}
		}	
		int getElemento(int pos){
			if(pos==1)
				return head->data;
			else{
				int i = 1;
				nodo* t=head;
				while(i<pos){
					i++;
					t=t->next;
				}
				return t->data;
			}				
		}
		int setElemento(int valor, int pos){
			if(pos==1)
				head->data = valor;
			else{
				int i = 1;
				nodo* t=head;
				while(i<pos){
					i++;
					t=t->next;
				}
				t->data = valor;
			}				
		}		
		void guardar(const char *nombreArchivo){
			nodo *tmp = head;
			ofstream archivoSalida;
			archivoSalida.open(nombreArchivo);
			while(tmp != NULL){
				archivoSalida << tmp -> data << endl;
				tmp = tmp -> next;
			}
			archivoSalida.close();
		}
		void cargar(const char *nombreArchivo){
			ifstream archivoEntrada;
			archivoEntrada.open(nombreArchivo);
			while(archivoEntrada.eof() == false){
				int valor;
				archivoEntrada >> valor;
				if(!archivoEntrada.eof()){
					adicionarFinal(valor);
				}
			}
			archivoEntrada.close();
		}
};

/*
int main ();
	Lista <int> ls(6);
	
	ls.setElemento (3, 11);

	ls.adicionar (5);
	ls.adicionar (4);
	ls.adicionar (3);
	ls.adicionar (2);

	ls.mostrarse ();

	ls.setElemento (0, 55);
	cout << endl;
	ls.mostrarse ();
	cout << endl;
	ls.insertar (0, 66);
	cout << endl;
	ls.mostrarse ();
	cout << endl;
	ls.eliminar (3);
	ls.mostrarse ();
	cout << endl;

	cout << ls.longitud() << " " << ls.emp();
	return 0;
}
*/

#endif
