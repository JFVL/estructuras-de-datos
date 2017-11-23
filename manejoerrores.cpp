//manejo de errores
//Lanzamiento
void func(){
	if(detecto_error1)
		throw tipo1(); //constructor
		...
	if(detecto_error2)
		throw tipo2(); //constructor
		...
}

//captura
try{
	//codigo de ejecucion normal
	func(); //puede lanzar excepciones
	...
} catch(tipo1 &ex){
	//Gestion de excepcion tipo1
} catch(tipo2 &ex){
	//Gestion de excepcion tipo2
} catch(...){
	//Gestion de cualquier excepcion captura mediante los catch anteriores
}

//crear una excepcion nuestra; para decir que la excepcion es de tipo MIEXCEPCION
class miExcepcion
{
private:
	int x;
	string msg;
public:
	miExcepcion(int a, string m) : x(a), msg(m) {} //llama el constructor de los atributos, es como si colocaramos x=a y msg=m
	string queHaPasado() const{
		return msg;
	}
	int getElCulpable() const { //const sirve para que no lance excepciones dentro de esa funcion
		return x;
	}
	
};

//ejemplo
//lanzamiento:
int llamameConCuidado(int x){
	if(condicion_de_error(x) == true) 
		throw miExcepcion(x, "lo has vuelto a hacer");
		//codigo a ejecutar si no hay error
}

//llamado:
int main() {
	try{
		llamameConCuidado(0);
		//Argumento: mas lineas de codigo
	}catch (miExcepcion &ex){
		//por referencia //la excepciones las envia por referencia
		cerr << ex.queHaPasado() //cerr(es un cout que lo direcciona a otra parte): dice que "esto no me lo tire a la pantalla sino que lo mande a la salida estandar de errores" en otras palabras no lo manda a la salida estandar sino que lo guarda en archivo
			 << ex.getElCulpable()<< endl;	
	}
}