/*
AM - Montinho de rodelas metálicas. 
Contém entre 50 e 100 unidades de ouro.
*/
#pragma once
#ifndef MOEDAS_H
#define MOEDAS_H

#include "Artefactos.h"
using namespace std;

class Moedas:public artefactos{

public:
	Moedas(string s,int x,int y);
	virtual void Art(jogo *j,faccoes &f,int hab,int numfaccoes,vector <faccoes> &vfac, int largura, int altura, int ncidades); 
};

#endif