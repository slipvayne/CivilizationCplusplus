/*
Ver a partir da pagina 3 do enunciado! - MAIN CLASS
( Observações: “Age” e “comportamento automático” não são necessariamente duas funções, 
ou duas funções diferentes. Uma descrição textual não é pseudo-código.)
*/

#pragma once
#ifndef HABITANTES_H
#define HABITANTES_H
#include <iostream>
#include <string>
#include <time.h>
#include "Faccoes.h"
#include "Cidades.h"
#include "Artefactos.h"
using namespace std;

class jogo;
class faccoes;
class artefactos;

class habitantes{

	static int contaHab;    //ultimo id do habitante

	int id; //começa em 01 e vai ate 99 (independente da faccao)
	int velocidade; //nº de turnos que o habitante demora a mexer-se
	int visao;		//raio de visao do habitante
	int pos_x;		//posicao x do habitante no mapa
	int pos_y;		//posicao y do habitante no mapa
	string tipo;		//tipo do habitante (campones, heroi, etc..) hc, hs etc..
	int cidade_base; //numero id da cidade base do habitante
	int instantes; //instantes que restam para alguma coisa
	bool ordem; //se tem uma ordem de accao ou nao
	int dest_x; //pos x destino
	int dest_y; //post_y destino


public:

	//CONSTRUTOR
	habitantes(int vel=0, int vis=0, int x=0, int y=0, string t="HC", int cdd_base=0,int inst=0); 

	//DESTRUTOR
	~habitantes(void);

	void setDestinoX(int n);
	void setDestinoY(int n);
	int getDestinoX();
	int getDestinoY();

	//SETS
	void setVelocidade(int n);
	void setVisao(int n);
	void setX(int n);
	void setY(int n);
	void setTipo(string n);
	void setID(int n);
	void setCidadeBase(int n);
	void setInstantes(int insts);
	void setOrdem(bool n);

	

	//GETS
	int getId();
	int getVelocidade();
	int getVisao();
	int getX();
	int getY();
	string getTipo();
	int getFaccao();
	int getID();
	int getCidadeBase();
	int getInstantes();
	bool getOrdem();
	
	
	//virtual bool getFoge();
//	virtual void setFoge(bool r);
	virtual void Accao(jogo *j,int hab,faccoes &fac,int l,int a,vector <faccoes> &vfac,int nfac,vector <artefactos*> &vart);


	//OPERADORES


	//randomizar tipo
	//so devera ser necessario depois para o jogador computador visto que o utilizador tem controlo sobre que habitantes criar
	void randomizar_tipo();

	//randomizar posicao
	 //recebe a largura e altura do mapa
	 //so devera ser necessario no inicio do jogo visto que os habitantes devem aparecer em cima das cidades onde sao criados.
	void randomizar_pos(int l, int a);

	//habitante pos fixa
	void poshabitante(int x, int y);


	//accao do habitante
	  //acções desempenhadas pelos habitantes (cada um com a sua)
//	virtual void accao() = 0;


	//consumir comida
	  //cada habitante consome um nº diferente de comida
	  //recebe o numero de comida a consumir
	virtual void consumir_comida(faccoes &fac, int n);




};


#endif