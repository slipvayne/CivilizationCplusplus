/*
AE - Espelho mágico. 
Faz com que a cidade mais próxima seja duplicada (implica duplicar os habitantes que nela se encontrem),
ficando a nova cidade com o nome da original mais “DUP” e na posição do artefacto.
O código identificador da cidade duplicada também tem que ser diferente da cidade original.
*/
#pragma once
#ifndef ESPELHO_H
#define ESPELHO_H

#include "Artefactos.h"
using namespace std;

class Espelho:public artefactos{

public:
	Espelho(string s,int x,int y);
	virtual void Art(jogo *j,faccoes &f,int hab,int numfaccoes,vector <faccoes> &vfac, int largura, int altura, int ncidades); 
};

#endif