#pragma once
#ifndef JOGO_H
#define JOGO_H

#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <sstream>
#include "Consola.h"
#include "Terreno.h"
#include "Faccoes.h"
#include "Habitantes.h"
#include "Campones.h"
#include "Artefactos.h"
#include "Cidades.h"
#include "Jogo.h"
#include "Menu.h"
#include "Sardinhas.h"
#include "AMisterio.h"
#include "Cola.h"
#include "Doencas.h"
#include "Espelho.h"
#include "Moedas.h"
#include "Panfletos.h"
#include "Heroi.h"
#include "Mineiro.h"
#include "HMisterio.h"
#include "Soldado.h"

using namespace std;

class habitantes;
class artefactos;
class faccoes;
class cidade;


class jogo{
	//proibir construtor por copia
	jogo(const jogo&);
	//proibir atribuicao
	jogo operator=(const jogo&);

	vector <habitantes*> vhab;
	vector <artefactos*> vart;
	vector <faccoes> vfac;

	Consola c;
	terreno t;
	int ncidades;
	cidade* cidades;

public:

	//CONSTRUTOR
	jogo(int nfaccoes, vector <string> nomefac);

	//DESTRUTOR
	~jogo();

	string randomizarArtefacto();

	void jogar(int nfaccoes, int largura, int altura);

	void adicionaArtefactos(string nomeart,int x, int y);

	cidade* getCidades();

	void setCidades(cidade* cidad);

	int randomizarPosArtefactos(int xy);

	int getTotalCidades();

	void setTotalCidades(int n);

	void CriarHabitantes(string tipohab,int jogafaccao,vector <faccoes> &vfac, jogo *j, cidade *cdd);

	habitantes* adicionarhab(int x,int y,string tipo);

	cidade* CriaObjectosCidade(cidade *anterior,int ncidades);

	void reloadinfo(int largura,int altura,vector <artefactos*> vart,vector <faccoes> &vfac,int x=0, int y=0, int jogafaccao=0);

	int verificaFaccoes(int largura,int altura,vector <artefactos*> vart,vector <faccoes> &vfac,int x, int y, int faccoesemjogo,int &jogafaccao);

	void tratacomandos(int largura,int altura,vector <artefactos*> vart,vector <faccoes> &vfac,int x, int y,vector <string> comandos,int jogafaccao, int ncidades, cidade* cidades);

	//funcao que troca o numero da cor da faccao pela cor em si
	void imprime_cor(int n); //recebe o numero da cor da faccao(consola)

	void imprime_cidades(int dph, int dpv,int px,int py,int cor,int id);

	//funcao que imprime o HABITANTE no mapa
	void imprime_habitante(int dph,int dpv,int px, int py,int cor,int id,string tipo);

	//funcao que imprime o ARTEFACTO no mapa
	void imprime_artefacto(int dph, int dpv, artefactos &a);

	//funcao para movimentar o HABITANTE
	 //recebe o habitante a movimentar, a largura e altura do mapa (para saber os limites)
	void movimenta_habitante(faccoes &fac, int l, int a, int hab);


	void movimenta_habitante_pos(habitantes &h, int l, int a, int x, int y);

	//funcao que gera artefactos consoante as dimensoes do mapa
	 //recebe a largura e a altura do mapa
	 //devolve o ponteiro para o 1º artefacto artefactos gera_artefactos(int l, int a);
	//void gera_artefactos(int l, int a);
//	artefactos *gera_artefactos(int l, int a);


	//verificar artefacto
	  //verifica se um habitante calcou um artefacto e se sim, executa o seu efeito
	  //recebe o vector de artefactos e o vector dos habitantes
	void verificar_artefacto();

	//verificar cidade
	  //verifica se um habitante esta dentro de uma cidade (nas mesmas coordenadas)
	  //recebe o vector de habitantes e as cidades*
	void verificar_cidade();

	void novojogotitle();





};


#endif