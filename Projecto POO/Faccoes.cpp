#include "Faccoes.h"
#include "Jogo.h"


//CONSTRUTOR
faccoes::faccoes(string n, bool j){

	id = ++contaid;
	cor_fac = ++contacor;
	nome = n;
	ouro = 250;
	comida = 250;
	jogador = j;
	activo = true;
	
}

//DESTRUTOR
faccoes::~faccoes(void){
	while (!vhabitantes.empty())
  {
     vhabitantes.erase(vhabitantes.begin());
  }
}

//SETS
void faccoes::setNome(string n){
	nome = n;
}
void faccoes::setOuro(int n){
	ouro = n;
}
void faccoes::setComida(int n){
	comida = n;
}
void faccoes::setJogador(bool n){
	jogador = n;
}
void faccoes::setCor(int n){
	cor_fac = n;
}

void faccoes::setvechab(habitantes* ha){
	this->vhabitantes.push_back(ha);
}
void faccoes::sethabx(int f,int n){
	vhabitantes[f]->setX(n);
}

void faccoes::sethaby(int f,int n){
	vhabitantes[f]->setY(n);
}

void faccoes::sethabcddbase(int f, int n){
	vhabitantes[f]->setCidadeBase(n);
}

void faccoes::eliminahab(int f){
	this->vhabitantes.erase(vhabitantes.begin()+f);
}

void faccoes::habAccao(jogo *j,int n,faccoes &f,int l, int a,vector <faccoes> &vfac,int nfac,vector <artefactos*> vart){
	vhabitantes[n]->Accao(j,n,f,l,a,vfac,nfac,vart);
}

void faccoes::setHabInstantes(int hab){
	vhabitantes[hab]->setInstantes(vhabitantes[hab]->getVelocidade());
}

//GETS
int faccoes::gettamvechab(){
	return vhabitantes.size();
}

string faccoes::getNome(){
	return nome;
}
int faccoes::getOuro(){
	return ouro;
}
int faccoes::getComida(){
	return comida;
}
bool faccoes::getJogador(){
	return jogador;
}
int faccoes::getCor(){
	return cor_fac;
}
int faccoes::getId(){
	return id;
}

bool faccoes::getActivo(){
	return activo;
}

void faccoes::setActivo(bool n){
	activo=n;
}

string faccoes::getHabTipo(int f){
	return vhabitantes[f]->getTipo();
}


int faccoes::gethabx(int f){
	return vhabitantes[f]->getX();

}

int faccoes::gethaby(int f){
	return vhabitantes[f]->getY();

}
int faccoes::gethabid(int f){
	return vhabitantes[f]->getID();
}
int faccoes::gethabcddbase(int f){
	return vhabitantes[f]->getCidadeBase();
}

void faccoes::setHabOrdem(int f,bool ordem)
{
	vhabitantes[f]->setOrdem(ordem);
}

bool faccoes::getHabOrdem(int f)
{
	return vhabitantes[f]->getOrdem();
}

void faccoes::setHabDestinoXY(int hab,int x, int y){
	vhabitantes[hab]->setDestinoX(x);
	vhabitantes[hab]->setDestinoY(y);
}



//verificar se a faccao tem cidades (1-sim 0-nao)
  //recebe o id da faccao a verificar
int faccoes::verificar_cidades(jogo *j,cidade *cdd, int f_id){
	//FALTA TOTAL DE CIDADES (alterou-se)
cdd=j->getCidades();
	//percorrer o vector das cidades e ver se alguma tem um fid = ao id da faccao recebido
	for(int i=0; i<j->getTotalCidades(); i++){
		if(cdd[i].getFid() == f_id){ return 1;}
	}

	return 0;
}

int faccoes::verificar_cidade_id(jogo *j,cidade *cdd, int f_id){
	//FALTA TOTAL DE CIDADES (alterou-se)
	//percorrer o vector das cidades e ver se alguma tem um fid = ao id da faccao recebido
	cdd=j->getCidades();
	for(int i=0; i<j->getTotalCidades(); i++){
		if(cdd[i].getFid() == f_id){ return i;}
	}

	return -1;
}

//verificar recursos
  //verificar se existe num_c numero de comida e num_o numero de ouro
  //1- recursos suficientes 0- recursos insuficientes
int faccoes::verificar_recursos(int num_c, int num_o){
	if( (this->getComida() >= num_c) && (this->getOuro() >= num_o) )
		return 1;
	else
		return 0;
}