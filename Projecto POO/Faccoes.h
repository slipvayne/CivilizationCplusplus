#pragma once
#ifndef FACCOES_H
#define FACCOES_H

#include <iostream>
#include <string>
#include <vector>
#include "Consola.h"
#include "Cidades.h"
#include "Habitantes.h"
#include "Artefactos.h"
using namespace std;

class habitantes;
class cidade;
class jogo;
class artefactos;

class faccoes{

	static int contaid;
	static int contacor;

	int id;       // id da faccao
	int cor_fac;  //cor da faccao
	string nome; //nome da faccao

vector <habitantes*> vhabitantes;
	
	int ouro;	//quantidade de ouro da faccao   //falta produçao e consumo
	int comida;	//quantidade de comida da faccao //falta produçao e consumo
	bool jogador; //1-se for controlada pelo jogador, 0-se for controlada pelo pc	
//	int habitantes; //numero total de habitantes dessa faccao
    bool activo; //se a faccao ta activa ou nao

public:

	//CONSTRUTOR
	faccoes(string n, bool jogador);

	//DESTRUTOR
	~faccoes(void);

	//SETS
	void setNome(string n);
	void setOuro(int n);
	void setComida(int n);
	void setJogador(bool n);
	void setCor(int n);
	void sethabx(int f,int n);
	void sethaby(int f,int n);
	void setHabOrdem(int f,bool ordem);

	void setActivo(bool n);
	bool getActivo();

	bool getHabOrdem(int f);

	void setvechab(habitantes* ha);
	void sethabcddbase(int f, int n);
	void eliminahab(int f);
	void habAccao(jogo *j,int n,faccoes &f,int l, int a,vector <faccoes> &vfac,int nfac,vector <artefactos*> vart);

	//GETS
	string getNome();
	int getOuro();
	int getComida();
	bool getJogador();
	int getCor();
	int getId();

	int gettamvechab();
	int gethabx(int f);
	int gethaby(int f);
	int gethabid(int f);
	int gethabcddbase(int f);

	string getHabTipo(int f);

	void setHabDestinoXY(int hab,int x, int y);

	void setHabInstantes(int hab);



	//verificar se a faccao tem cidades (1-sim 0-nao)
	  //recebe o id da faccao a verificar
	int verificar_cidades(jogo *j,cidade *cdd, int f_id);
	
	//verificar recursos
	  //verificar se existe num_c numero de comida e num_o numero de ouro
	  //1- recursos suficientes 0- recursos insuficientes
	int verificar_recursos(int num_c, int num_o);

	int verificar_cidade_id(jogo *j,cidade *cdd, int f_id);

};


#endif