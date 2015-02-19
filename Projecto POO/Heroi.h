/*
Her�i. Gasta 20 unidades de ouro a ser constru�do e demora 8 instantes a �ser feito�. Visibilidade 4, Lentid�o 1.

o Consome recursos: Consome tr�s unidades de comida por instante.
o N�o produz nada.
o Ataca: Tem uma probabilidade de 100% de matar o oponente, calcando-o com o seu cavalo branco.
o Age: N�o faz nada de especial (ver comportamento autom�tico).
o Na cidade vai para cima da torre mais elevada e fica a puxar lustro � sua armadura reluzente. 
Fora da cidade desloca-se a esmo com uma ligeira probabilidade de se afastar da cidade base
(esta ligeira probabilidade n�o vai ser testada nem avaliada, mas fica mais interessante de ver se for implementado). 
� provido de um fervor quase fan�tico contra tudo o que � de outra fac��o. 
Se vir um habitante �inimigo� vai logo mostrar-lhe o lado de baixo dos cascos do seu cavalo. 
Dada a sua velocidade e for�a, este habitante � uma aut�ntica m�quina de matar, 
pelo que deve ser usado com cuidado e sempre sob a supervis�o de um observador da ONU. 
O her�i n�o quer saber dos artefactos antigos porque o materialismo n�o lhe interessa.
*/
#pragma once
#ifndef HEROI_H
#define HEROI_H

#include <iostream>
#include "Habitantes.h"
#include "Cidades.h"
#include "Faccoes.h"

using namespace std;


class Heroi : public habitantes{

//bool foge; //se esta a fugir do inimigo

public:

	Heroi(int x=0,int y=0,int inst=0,string t="HH");


	//virtual bool getFoge();
	//virtual void setFoge(bool r);
	
	virtual void Accao(jogo *j,int hab,faccoes &fac,int l,int a,vector <faccoes> &vfac,int nfac,vector <artefactos*> &vart);


	//atribuir cidade base (se o habitante estiver em cima de alguma cidade da sua faccao, esta passa a ser a sua cidade base)
	virtual void atribuir_cidade_base(jogo *j, cidade *cdd, faccoes &fac, int nhab);


	//detectar cidade (verifica se um determinado habitante esta em cima de alguma cidade da sua faccao)
	virtual int verificar_cidade(jogo *j,cidade *cdd, faccoes &fac, int nhab);


	virtual void consumir_comida(faccoes &fac);

	void movimenta();


	

};

#endif