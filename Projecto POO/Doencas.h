/*
AC - Caixinha de doenças. 
Mata o desgraçado que apanhar o artefacto.
*/
#pragma once
#ifndef DOENCAS_H
#define DOENCAS_H

#include "Artefactos.h"
using namespace std;

class Doencas:public artefactos{

public:
	Doencas(string s,int x,int y);
	virtual void Art(jogo *j,faccoes &f,int hab,int numfaccoes,vector <faccoes> &vfac, int largura, int altura, int ncidades); 
};

#endif