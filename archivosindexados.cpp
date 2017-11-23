//archivos secuenciales indexados
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <ifstream>
#include <string.h>

typedef struct diccionario{
	char palabra[10];
	char significado[50];

};

buscarSignificado(string palabra, string archIndices, string archBinario){
	ifstream archIndices;
	archIndices.open(archIndices);
	int indices;
	string tmppalabra;
	while(archIndices.eof())!= true){
		archIndices >> indice >> tmppalabra;
		if(tmppalabra == palabra)
			break;
	}
	archIndices.close();
	int posBin = indice* 60;
	diccionario dic;
	ifstream archBin;
	archBin.open(archBinario, ios::binary);
	archBin.seekg(posBin);
	archBin.read(&dic, sizeof(dic));
	archBin.close();
	return dic.significado();

}

main(){
	string sig = buscarSignificado("red", "indices.txt", "datos.bin");
		cout << sig;
}