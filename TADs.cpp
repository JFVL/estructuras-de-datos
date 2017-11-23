/*TIPOS ABSTRACTOS DE DATOS
TAD = conjunto de objetos abstractos + conjunto de operacion
atributos + operaciones
abstractos independientes de la impletacion
EJEMPLO:
TAD Pila:
adicionar(elemento): Pila
construir(): Pila
tope(): elemento
eliminar(): Pila
El TAD lo que hace es mostrar la especificacion de las operaciones que se van
a hacer en una estructura. Con que objetos se va a trabajar.El TAD es mas concepto,
saber que operaciones se aplican sobre la pila.Los TADS son abstractos.

TAD contiene las funciones:
CREADORAS
MODIFICADORAS(adicionar, eliminar, insertar, reemplazar, sets)
ANALIZADORAS(obtener primero, obtener ultimo, gets, obtener por ubicacion)

----------------------------------------------------------
TAD PILA;
construirPila(): Pila
adicionarPila(Pila, elemento): Pila
eliminar(Pila): Pila
infoPila(Pila): elemento //devuelve el tope de la pila
estaVaciaPila(Pila): bool
----------------------------------------------------------
TAD COLA;
construirCola(): Cola
adicionarCola(Cola, elemento): Cola
eliminarCola(Cola): Cola
infoCola(Cola): elemento
estaVaciaPila(Cola): bool
----------------------------------------------------------
TAD LISTA;
construirLista():Lista
adicionarFinal(Lista, elemento): Lista
insertar(Lista, Posicion, elemento): Lista
eliminar(Lista, Posicion): Lista
infoLista(Lista, Posicion): elemento
estaVaciaLista(Lista): bool
longitudLista(Lista): entero
---------------------------------------------------------- 