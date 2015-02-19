#pragma once
#ifndef CIDADES_H
#define CIDADES_H

#include <string>
#include "Habitantes.h"
using namespace std;

class cidade{	

	int id;
	string nomedacidade;	
	int pos_x;
	int pos_y;
	int fid;    //id da faccao da cidade

public:
	//construtor
	cidade(int idcid=0,string nome="Ci",int x=0,int y=0,int idf=0);
	
	//destrutor
	~cidade(void);
	

	//SETS
	void setNomeCidade(string nome);
	void setPosX(int n);
	void setPosY(int n);
	void setFid(int n);
	void setId(int n);

	//GETS
	string getNomeCidade();
	int getId();
	int getPosX();
	int getPosY();
	int getFid();

	//OPERADORES
	//cidade & operator=(const cidade& c);
	

};
#endif