#include "Habitantes.h"


//CONSTRUTOR
habitantes::habitantes(int vel, int vis, int x, int y, string t, int cdd_base, int inst){
	
	id = ++contaHab;
	velocidade = vel;
	visao = vis;
	pos_x = x;
	pos_y = y;
	dest_x = x;
	dest_y = y;
	tipo = t;
	cidade_base = cdd_base;
	instantes=inst;
	ordem = false;
}

//NOVAS

void habitantes::setDestinoX(int n){
	dest_x=n;
}
void habitantes::setDestinoY(int n){
	dest_y=n;
}

int habitantes::getDestinoX(){
	return dest_x;
}
int habitantes::getDestinoY(){
	return dest_y;
}



//DESTRUTOR
habitantes::~habitantes(void){

}

void habitantes::setOrdem(bool n){
	ordem = n;
}
void habitantes::setInstantes(int inst){
	instantes=inst;
}
//SETS
void habitantes::setVelocidade(int n){
	velocidade = n;
}
void habitantes::setVisao(int n){
	visao = n;
}
void habitantes::setX(int n){
	pos_x = n;
}
void habitantes::setY(int n){
	pos_y = n;
}
void habitantes::setTipo(string n){
	tipo = n;
}

void habitantes::setID(int n){
	id = n;

}
void habitantes::setCidadeBase(int n){
	cidade_base = n;
}


//GETS
int habitantes::getId(){
	return id;
}
int habitantes::getVelocidade(){
	return velocidade;
}
int habitantes::getVisao(){
	return visao;
}
int habitantes::getX(){
	return pos_x;
}
int habitantes::getY(){
	return pos_y;
}
string habitantes::getTipo(){
	return tipo;
}

int habitantes::getID(){
	return id;
}

int habitantes::getCidadeBase(){
	return cidade_base;
}

int habitantes::getInstantes(){
	return instantes;
}
bool habitantes::getOrdem(){
	return ordem;
}


void habitantes::Accao(jogo *j,int hab,faccoes &fac,int l,int a,vector <faccoes> &vfac,int nfac,vector <artefactos*> &vart)
	{ 
	
	}



//randomizar tipo
void habitantes::randomizar_tipo(){
	int aux; //variavel auxiliar para o random
	//srand ( time(NULL) ); //inicializar seed do random
	aux = rand() % 5 + 1; //obter valor random entre 1 e 5

	switch (aux){
		case 1:
			setTipo("HC"); //campones
			break;
		case 2:
			setTipo("HM"); //mineiro
			break;
		case 3:
			setTipo("HS"); //soldado
			break;
		case 4:
			setTipo("HH"); //heroi
			break;
		case 5:
			setTipo("HZ"); //habitante misterio
			break;
	}

}

//randomizar posicao
 //recebe a largura e altura do mapa
void habitantes::randomizar_pos(int l, int a){
	setX(rand() % l); //randomizar coordenada de 0 a "largura"
	setY(rand() % a); //randomizar coordenada de 0 a "altura"
}

void habitantes::poshabitante(int x, int y){
//falta verificar limites!!!
	setX(x); //randomizar coordenada de 0 a "largura"
	setY(y); //randomizar coordenada de 0 a "altura"
}


//consumir comida
  //cada habitante consome um nº diferente de comida
  //recebe o numero de comida a consumir
void habitantes::consumir_comida(faccoes &fac, int n){
	
	if(fac.getComida() < 0)
		fac.setComida(0);
	else
		fac.setComida( fac.getComida() - n );

}
