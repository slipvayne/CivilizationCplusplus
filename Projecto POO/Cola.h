/*
AT - Tubo de cola. 
Faz com que o habitante funde uma cidade nesse instante e nesse sítio.
*/
#pragma once
#ifndef COLA_H
#define COLA_H

#include "Artefactos.h"
using namespace std;

class Cola:public artefactos{

public:
	Cola(string s,int x,int y);
	virtual void Art(jogo *j,faccoes &f,int hab,int numfaccoes,vector <faccoes> &vfac, int largura, int altura, int ncidades); 
};

#endif