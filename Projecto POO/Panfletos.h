/*
AP - Panfletos deprimentes. 
Contém as projecções económicas para o ano seguinte e fazem com que o habitante deserte imediatamente para uma das facções inimigas.
*/
#pragma once
#ifndef PANFLETOS_H
#define PANFLETOS_H

#include "Artefactos.h"
#include "Jogo.h"

class jogo;

using namespace std;

class Panfletos:public artefactos{

public:
	Panfletos(string s,int x,int y);
	virtual void Art(jogo *j,faccoes &f,int hab,int numfaccoes,vector <faccoes> &vfac, int largura, int altura, int ncidades);
};

#endif