/*
AA - Artefacto-mistério. 
Funcao escolhida: Retira metade ou Duplica a Comida e Ouro!
*/
#pragma once
#ifndef AMISTERIO_H
#define AMISTERIO_H

#include "Artefactos.h"
using namespace std;

class AMisterio:public artefactos{

public:
	AMisterio(string s,int x,int y);
	virtual void Art(jogo *j,faccoes &f,int hab,int numfaccoes,vector <faccoes> &vfac, int largura, int altura, int ncidades); //accao por parte de AC no habitante
};
#endif