#pragma once
#ifndef MENU_H
#define MENU_H
#include "Consola.h"
#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <sstream>
#include "Consola.h"
#include "Terreno.h"
#include "Faccoes.h"
#include "Habitantes.h"
#include "Artefactos.h"
#include "Cidades.h"
#include "Jogo.h"
#include <stdlib.h> 
#include "time.h"
#include "windows.h"
using namespace std;



class menu{

	Consola c;
	
public:

	menu();

	void preenchebackgroundCYAN();
	void animacaoinicial();
	void logo();
	void novojogotitle();
	void loadgametitle();	

	int inicio();

};


#endif