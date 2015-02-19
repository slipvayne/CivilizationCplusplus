/*
AS - Sardinhas enlatadas. 
Contém entre 50 e 100 unidades de comida.
*/
#pragma once
#ifndef SARDINHAS_H
#define SARDINHAS_H

#include "Artefactos.h"

using namespace std;

class Sardinhas:public artefactos{

public:
	Sardinhas(string s,int x,int y);
	virtual void Art(jogo *j,faccoes &f,int hab,int numfaccoes,vector <faccoes> &vfac, int largura, int altura, int ncidades); 
};

#endif