/*
Herói. Gasta 20 unidades de ouro a ser construído e demora 8 instantes a “ser feito”. Visibilidade 4, Lentidão 1.

o Consome recursos: Consome três unidades de comida por instante.
o Não produz nada.
o Ataca: Tem uma probabilidade de 100% de matar o oponente, calcando-o com o seu cavalo branco.
o Age: Não faz nada de especial (ver comportamento automático).
o Na cidade vai para cima da torre mais elevada e fica a puxar lustro à sua armadura reluzente. 
Fora da cidade desloca-se a esmo com uma ligeira probabilidade de se afastar da cidade base
(esta ligeira probabilidade não vai ser testada nem avaliada, mas fica mais interessante de ver se for implementado). 
É provido de um fervor quase fanático contra tudo o que é de outra facção. 
Se vir um habitante “inimigo” vai logo mostrar-lhe o lado de baixo dos cascos do seu cavalo. 
Dada a sua velocidade e força, este habitante é uma autêntica máquina de matar, 
pelo que deve ser usado com cuidado e sempre sob a supervisão de um observador da ONU. 
O herói não quer saber dos artefactos antigos porque o materialismo não lhe interessa.
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