/*
Mineiro. Gasta 10 unidades de ouro a ser construído e demora 5 instantes a “ser feito”. Visibilidade 2, lentidão 2.

o Consome recursos: Consome duas unidades de comida por instante.
o Produz recursos: Produz duas unidades de ouro por instante se estiver fora da cidade.
o Ataca: Um mineiro quando ataca, pega numa unidade de ouro e atira-a ao oponente, 
com 20% de probabilidade de o matar por overdose de ouro na cabeça (este é ouro perdido – a facção do mineiro fica sem esse ouro, 
e o inimigo também não fica com ele). 
Se não houver ouro nenhum o mineiro faz apenas o gesto de atirar algo ao inimigo e a probabilidade disso o magoar é 0%.
o Age: Na cidade, joga à batalha naval, pois na cidade não há minas. Se estiver fora da cidade encontra duas unidades de ouro por instante.
o O comportamento automático é estar quietinho e fazer nada se estiver na cidade ou encontrar ouro se estiver fora, 
tal como descrito acima (esta repetição de texto não se traduz em repetição de código). 
Sempre que se desloca tem uma probabilidade de 10% de tropeçar numa toca de lebre, cair e morrer. 
Se vir um soldado inimigo foge para a cidade base. 
Um mineiro tenta sempre apanhar um artefacto que esteja ao seu alcance visual, 
a não ser que vá a fugir para a sua cidade base.
*/

#pragma once
#ifndef MINEIRO_H
#define MINEIRO_H

#include <iostream>
#include "Habitantes.h"
#include "Cidades.h"
#include "Faccoes.h"
using namespace std;

class Mineiro:public habitantes{

public:
	Mineiro(int x=0,int y=0,int inst=0,string t="HM");

	virtual void Accao(jogo *j,int hab,faccoes &fac,int l,int a,vector <faccoes> &vfac,int nfac,vector <artefactos*> &vart);


	virtual void consumir_comida(faccoes &fac);

	virtual int verificar_cidade(jogo *j,cidade *cdd, faccoes &fac, int nhab);
	
	virtual void atribuir_cidade_base(jogo *j, cidade *cdd, faccoes &fac, int nhab);

	void movimenta();

};

#endif