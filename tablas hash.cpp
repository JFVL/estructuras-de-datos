//Tablas hash
// insertar:
Tabla[fh("john")] = <"jhon, 25000">;
//eliminar:
Tabla[fh("john")] = NULL
//busqueda:
Tabla[fh("john")]//retorna el elemento "hashed" por "john"

/*Del fh se va el nodo hacia el indice de la lista(1,2,3,4,5...)

Colisiones:
que pasa si fh("john") == fh("joe")
para manejarlas se usa el encadenamiento, direccionamiento abierto (apuntar a el que esta siguiente a la colision),
doble hashing, etc.

Funcion hash:
fh(key): {int
		  string
		  float
		  char
		  .
		  .
		  . 
} Puede ser de cualquier tipo
-----------------------------------------------------------------------------------------------------------------------------------------------
TablaHash.h
private:
buffer: vector<list<int(o puede ser de tipo T para que sea generico y se le asigne el tipo de elemento dependiendo del caso que se presente)>>
longitudActual(n:int)
fhash(k:T): int //funcion hashig le entra la clave y le devuelve un indice
public:
TablaHash(n::int)
adicionar(x:T): bool//en este caso se va a utilizar el tipo T para que sea generico
eliminar(x:T): bool	// a estas tres funciones les entra un elemento que es con el que se va a trabajar
buscar(x:T): bool	// y retornan bool para saber si se puede trabajar con ellos o no
mostrar()
limpiar()
-----------------------------------------------------------------------------------------------------------------------------------------------
*/
TablaHash(int n):vector(n){//esto lo que hace en el vector es inicializar en cada espacio de este una lista vacia
	longitudActual=0;
}

bool adicionar(int x){
	int k = fhash(x);
	/*while(vector[k] != NULL)
		k++;//esto es con direccionamiento directo
	}
	vector[k] = x
	*/
	list l<int> = vector[k];
	l.push_back(x)
}

bool buscar(int x){
	int k = fhash(x);
	list l<int> = vector[l];
	list<int>::iterador b = find (l.begin(), l.end(), x);
	return b;
}

bool eliminar(int x){
	if(buscar(x) == false)
		return false;
	list l<int> = vector[fhash(x)];
	list<int>::iterador itr = find(l.begin(), l.end(), x);
	l.erase(itr);
	return true;
}