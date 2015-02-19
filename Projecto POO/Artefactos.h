/*
Artefactos antigos.
Existem espalhados pelo territ�rio alguns artefactos deixados por uma civiliza��o muito antiga.
T�m o aspecto de cofres e n�o se sabe o que l� est� dentro antes de os abrir. 
Sempre que um habitante entra numa quadr�cula em que existe um artefacto antigo, 
esse artefacto � achado e aberto, desencadeando um efeito que depende do artefacto.
Depois de desencadear o devido efeito, o artefacto desaparece por artes m�gicas e n�o volta a ser encontrado.
*/
#pragma once
#ifndef ARTEFACTOS_H
#define ARTEFACTOS_H

#include <iostream>
#include <string>
#include <time.h>
#include "Habitantes.h"
#include "Artefactos.h"
#include "Faccoes.h"
#include "Consola.h"
#include "Cidades.h"

using namespace std;

class habitantes;
class faccoes;
class jogo;


class artefactos{

	static int conta;

	string tipo; //tipo do artefacto AM, AC, AE....
	int pos_x;	//posicao x do artefacto no mapa
	int pos_y;	//posicao y do artefacto no mapa


public:

	Consola c;

	//CONSTRUTOR
	artefactos(string s, int x, int y);

	//DESTRUTOR
	~artefactos(void);

	//SETS
	void setTipo(string s);
	void setX(int n);
	void setY(int n);

	//GETS
	string getTipo();
	int getX();
	int getY();

	virtual void Art(jogo *j,faccoes &f,int hab,int numfaccoes,vector <faccoes> &vfac, int largura, int altura, int ncidades); //ac��o do artefacto no habitante


		

};

#endif