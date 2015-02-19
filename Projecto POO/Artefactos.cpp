#include "Artefactos.h"


//CONSTRUTOR
artefactos::artefactos(string s, int x, int y){

	tipo = s;
	pos_x = x;
	pos_y = y;
}

//DESTRUTOR
artefactos::~artefactos(void){
}

//SETS
void artefactos::setTipo(string s){
	tipo = s;
}
void artefactos::setX(int n){
	pos_x = n;
}
void artefactos::setY(int n){
	pos_y = n;
}

//GETS
string artefactos::getTipo(){
	return tipo;
}
int artefactos::getX(){
	return pos_x;
}
int artefactos::getY(){
	return pos_y;
}

void artefactos::Art(jogo *j,faccoes &f,int hab,int numfaccoes,vector <faccoes> &vfac, int largura, int altura, int ncidades){
//NAS "SUB"CLASS
}




