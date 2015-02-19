#include "Cidades.h"


//CONSTRUTOR
cidade::cidade(int idcid,string nome,int x,int y,int idf){
	id=idcid;
	pos_x=x;
	pos_y=y;
	nomedacidade=nome;
	fid=idf;
}

//DESTRUTOR
cidade::~cidade(void){
}

//SETS
void cidade::setNomeCidade(string nome){
	nomedacidade = nome;
}
void cidade::setPosX(int n){
	pos_x = n;
}
void cidade::setPosY(int n){
	pos_y = n;
}
void cidade::setFid(int n){
	fid = n;
}

//GETS
string getNomeCidade();
int cidade::getId(){
	return id;
}
int cidade::getPosX(){
	return pos_x;
}
int cidade::getPosY(){
	return pos_y;
}
int cidade::getFid(){
	return fid;
}

void cidade::setId(int n){
	id=n;
}


//OPERADORES

/*cidade &cidade::operator=(const cidade& c){

	return this;
}*/
