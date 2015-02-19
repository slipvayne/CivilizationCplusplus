#pragma once
#ifndef TERRENO_H
#define TERRENO_H


#include "Consola.h"
#include <iostream>
using namespace std;



class terreno{
	
	int largura; //largura do mapa
	int altura;  //altura do mapa

public:

	//CONSTRUTOR
	terreno(int l=0, int a=0);

	//SETS
	void setLargura(int l);
	void setAltura(int a);

	//GETS
	int getLargura();
	int getAltura();

	//OPERADORES

	//imprimir mapa (xadrez)
	//argumentos: largura (l) e altura (a) do mapa, nº de casas percorridas para a direita(horizontal)(cph) e para baixo(vertical)(cpv)
	void imprime_mapa(int l, int a, int cph, int cpv);
	


};



#endif
