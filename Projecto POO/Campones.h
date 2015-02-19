/*
Campon�s. �Unidade� b�sica de popula��o. 
Gasta 5 unidades de ouro a ser constru�do e demora 3 instantes a �ser feito�. Visibilidade 2, lentid�o 2.

o Consome recursos: Consome uma unidade de comida por instante.
o Produz recursos: Produz tr�s unidades de comida por instante se se deslocar fora de uma cidade. 
Dentro da cidade produz apenas uma unidade de comida.
o Ataca: Um campon�s n�o ataca ningu�m, nunca.
o Age: Na cidade n�o faz nenhum (j� produz comida). Quando anda a passear fora da cidade produz as tais tr�s unidades de comida.
o O comportamento autom�tico � o seguinte: 
Tal como j� descrito, na cidade produz uma unidade de comida, e fora da cidade deambula aleatoriamente, 
fazendo comida e nunca se afastando da sua cidade base mais do que 5 quadr�culas. 
Se vir um soldado inimigo foge para a cidade base. O campon�s s� se interessa por cebolas e batatas. 
Apanha um artefacto se por acaso passar por cima dele e apenas nesse caso. 
Quando est� a mais de 3 quadr�culas da cidade da sua fac��o mais pr�xima, 
o campon�s tem 10% de probabilidade de fundar uma nova cidade (desde que exista ouro suficiente). 
No caso de a fac��o n�o ter nenhuma cidade, essa probabilidade aumenta para 80%.
*/

#pragma once
#ifndef CAMPONES_H
#define CAMPONES_H

#include <iostream>
#include "Habitantes.h"
#include "Cidades.h"
#include "Faccoes.h"
using namespace std;



class Campones : public habitantes{

bool foge; //se esta a fugir do inimigo

public:

	Campones(int x=0,int y=0,int inst=0,string t="HC");


	//virtual bool getFoge();
	//virtual void setFoge(bool r);

	virtual void Accao(jogo *j,int hab,faccoes &fac,int l,int a,vector <faccoes> &vfac,int nfac,vector <artefactos*> &vart);

	//fun��o que evita que o campon�s saia dos limites da cidade (area de 5x5)
	  //nao se afasta mais do que 5 quadriculas da sua cidade base
	  //se ele sair do limite, � colocado dentro da area novamente (cidade[X] � a cidade base do habitante!) habitante.getCidadeBase().getPosX() ?
	//tem que passar a cidade base e o habitante
	virtual void limite_cidade(jogo *j, faccoes &fac, int hab);

	//criar cidade
	  //recebe como argumentos, o ponteiro para as cidades, a fac��o do habitante e o habitante que vai criar a cidade
	//void criar_cidade(cidade *cdd, vector <faccoes> &vfac, int nfac, int nhab);
	virtual void criar_cidade(jogo *j,faccoes &fac, int hab);

	//produzir comida (+1 dentro da cidade ou +3 fora)
	virtual void produzir_comida(jogo *j,cidade *cdd, faccoes &vfac, int nhab);

	//atribuir cidade base (se o habitante estiver em cima de alguma cidade da sua faccao, esta passa a ser a sua cidade base)
	virtual void atribuir_cidade_base(jogo *j, cidade *cdd, faccoes &fac, int nhab);


	//detectar cidade (verifica se um determinado habitante esta em cima de alguma cidade da sua faccao)
	virtual int verificar_cidade(jogo *j,cidade *cdd, faccoes &fac, int nhab);

	//consumir comida (1 unidade) (classe habitantes)
	virtual void consumir_comida(faccoes &fac);

	void movimenta();




};

#endif