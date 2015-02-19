/*
Camponês. “Unidade” básica de população. 
Gasta 5 unidades de ouro a ser construído e demora 3 instantes a “ser feito”. Visibilidade 2, lentidão 2.

o Consome recursos: Consome uma unidade de comida por instante.
o Produz recursos: Produz três unidades de comida por instante se se deslocar fora de uma cidade. 
Dentro da cidade produz apenas uma unidade de comida.
o Ataca: Um camponês não ataca ninguém, nunca.
o Age: Na cidade não faz nenhum (já produz comida). Quando anda a passear fora da cidade produz as tais três unidades de comida.
o O comportamento automático é o seguinte: 
Tal como já descrito, na cidade produz uma unidade de comida, e fora da cidade deambula aleatoriamente, 
fazendo comida e nunca se afastando da sua cidade base mais do que 5 quadrículas. 
Se vir um soldado inimigo foge para a cidade base. O camponês só se interessa por cebolas e batatas. 
Apanha um artefacto se por acaso passar por cima dele e apenas nesse caso. 
Quando está a mais de 3 quadrículas da cidade da sua facção mais próxima, 
o camponês tem 10% de probabilidade de fundar uma nova cidade (desde que exista ouro suficiente). 
No caso de a facção não ter nenhuma cidade, essa probabilidade aumenta para 80%.
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

	//função que evita que o camponês saia dos limites da cidade (area de 5x5)
	  //nao se afasta mais do que 5 quadriculas da sua cidade base
	  //se ele sair do limite, é colocado dentro da area novamente (cidade[X] é a cidade base do habitante!) habitante.getCidadeBase().getPosX() ?
	//tem que passar a cidade base e o habitante
	virtual void limite_cidade(jogo *j, faccoes &fac, int hab);

	//criar cidade
	  //recebe como argumentos, o ponteiro para as cidades, a facção do habitante e o habitante que vai criar a cidade
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