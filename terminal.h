/*Precondicion: Terminal es una clase donde el usuario
mediante mensajes puede darle ordenes a el juego, entre
estas estan leer movimiento, limpiar la pantalla y cerrar.
leer movimiento, lee desde teclado, el a y b que ingrese el usuario.
limpiar pantalla, detecta cual es la maquina con la que se esta trabajando.
*/
class Terminal
{
public:
	leermovimiento(cadena[2]);
	limpiarpantalla();
	
};
/*post-condicion: leermovimiento recibiria lo que digite
el usuario y devuelve lo que leyo del teclado.
limpiarpantalla si es windows cls, si es Mac ...
y deja la pantalla vacia.