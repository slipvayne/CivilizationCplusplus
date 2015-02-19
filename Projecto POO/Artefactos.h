/*
Artefactos antigos.
Existem espalhados pelo território alguns artefactos deixados por uma civilização muito antiga.
Têm o aspecto de cofres e não se sabe o que lá está dentro antes de os abrir. 
Sempre que um habitante entra numa quadrícula em que existe um artefacto antigo, 
esse artefacto é achado e aberto, desencadeando um efeito que depende do artefacto.
Depois de desencadear o devido efeito, o artefacto desaparece por artes mágicas e não volta a ser encontrado.
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

	virtual void Art(jogo *j,faccoes &f,int hab,int numfaccoes,vector <faccoes> &vfac, int largura, int altura, int ncidades); //acção do artefacto no habitante


		

};

#endif