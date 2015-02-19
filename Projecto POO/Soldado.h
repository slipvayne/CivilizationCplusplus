/*
Soldado. Gasta 10 unidades de ouro a ser construído e demora 5 instantes a “ser feito”. Visibilidade 2, Lentidão 3.
o Consome recursos: Consome duas unidades de comida por instante.
o Não produz nada.
o Ataca: Tem uma probabilidade de 75% de matar o oponente a golpes de espada.
o Age: Na cidade dorme. Fora da cidade fica quieto de guarda no sítio onde calhar estar.
o O seu comportamento automático é o seguinte: na cidade não faz nada, no território fica de guarda onde lhe mandaram estar, 
mas se vir algum inimigo vai tentar chegar à sua beira para amigavelmente tentar matá-lo. 
O soldado ganha pouco e por isso tenta sempre apanhar um artefacto que veja, 
ficando posicionado depois nesse sítio a não ser que veja outro artefacto
(curiosidade: pode-se “atrair” um soldado até uma armadilha “plantando” uma sequência de artefactos em fila).
*/

#pragma once
#ifndef SOLDADO_H
#define SOLDADO_H

#include <iostream>
#include "Habitantes.h"
#include "Cidades.h"
#include "Faccoes.h"
using namespace std;

class Soldado:public habitantes{

public:
	Soldado(int x=0,int y=0,int inst=0,string t="HS");

	virtual void Accao(jogo *j,int hab,faccoes &fac,int l,int a,vector <faccoes> &vfac,int nfac,vector <artefactos*> &vart);


	virtual void consumir_comida(faccoes &fac);


	virtual int verificar_cidade(jogo *j,cidade *cdd, faccoes &fac, int nhab);
	
	virtual void atribuir_cidade_base(jogo *j, cidade *cdd, faccoes &fac, int nhab);

	void movimenta();
};

#endif