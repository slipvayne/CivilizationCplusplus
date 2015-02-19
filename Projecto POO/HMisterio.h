/* Habitante-mistério. A definir pelos alunos. 
Se dois grupos inventarem dois habitante-mistério iguais, 
os professores vão achar que é muita coincidência e submeter todos a uma “defesa especial”.

PRIEST -> CONVERTE COM 35%PROB UM DETERMINADO HABITANTE DA FACCAO INIMIGA (MAIS PERTO) 
CONSOME 2 DE COMIDA
GASTA 10 DE OURO A SER CONSTRUIDO
VISIBILIDADE 2
LENTIDAO 2 
*/
#pragma once
#ifndef HMISTERIO_H
#define HMISTERIO_H

#include <iostream>
#include "Habitantes.h"
#include "Cidades.h"
#include "Faccoes.h"
using namespace std;

class HMisterio:public habitantes{

public:
	HMisterio(int x=0,int y=0,int inst=0,string t="HP");

	virtual void Accao(jogo *j,int hab,faccoes &fac,int l,int a,vector <faccoes> &vfac,int nfac,vector <artefactos*> &vart);

	virtual void consumir_comida(faccoes &fac);

	virtual int verificar_cidade(jogo *j,cidade *cdd, faccoes &fac, int nhab);
	
	virtual void atribuir_cidade_base(jogo *j, cidade *cdd, faccoes &fac, int nhab);

	void movimenta();
};

#endif