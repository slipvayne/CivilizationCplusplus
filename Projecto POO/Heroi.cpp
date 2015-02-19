#include "Heroi.h"
#include "Jogo.h"


Heroi::Heroi(int x,int y,int inst,string t):habitantes(1,4,x,y,t,inst){

//foge=false;
//init();

}


   // bool Campones::getFoge(){ return foge;}

//	void Campones::setFoge(bool r){ foge=r; }

void Heroi::Accao(jogo *j,int hab,faccoes &fac,int l,int a,vector <faccoes> &vfac,int nfac,vector <artefactos*> &vart){ 

	for(int z=0; z <(signed)vart.size(); z++) {
		if (vart[z]->getY()==this->getY() && vart[z]->getX()==this->getX()){
		{ vart[z]->Art(j,vfac[nfac],hab,vfac.size(),vfac,l,a,j->getTotalCidades()); vart[z]->setX(-1); vart[z]->setY(-1);}}
}

	atribuir_cidade_base(j,j->getCidades(),fac,hab);

for(int facc=0;facc<(signed)vfac.size();facc++)
	{
	for(int i=0;i<vfac[facc].gettamvechab();i++) // Verifica o que ha no preciso instante
	{	
	if(this->getX()==vfac[facc].gethabx(i) && this->getY()==vfac[facc].gethaby(i) && nfac!=facc) 
	{ vfac[facc].eliminahab(i);}
	}
}
	

for(int cid=0;cid<j->getTotalCidades();cid++)
{
	if(this->getX()==j->getCidades()[cid].getPosX() && this->getY()==j->getCidades()[cid].getPosY() && j->getCidades()[cid].getFid()-1!=nfac){
		{ j->getCidades()[cid].setFid(nfac+1); }
	}
}	



	if(this->getOrdem()==false){
//	j->movimenta_habitante(fac, l, a, hab); //andar aleatoriamente se PC , se pessoa verificaar pos
	}else{
		
		this->movimenta();
	}


	this->consumir_comida(fac);

}


//consumir comida (campones consome 1)
void Heroi::consumir_comida(faccoes &fac){

	if(fac.getComida() < 0)
		fac.setComida(0);
	else
		fac.setComida( fac.getComida() - 3 );

}



//detectar cidade (verifica se um determinado habitante esta em cima de alguma cidade da sua faccao)
//1- sim, 0- nao
int Heroi::verificar_cidade(jogo *j,cidade *cdd, faccoes &fac, int nhab){
	for(int i=0; i<j->getTotalCidades(); i++)
		if( cdd[i].getPosX() == fac.gethabx(nhab) )
			if( cdd[i].getPosY() == fac.gethaby(nhab) )
				return 1;

	return 0;
}

//atribuir cidade_base
void Heroi::atribuir_cidade_base(jogo *j, cidade *cdd, faccoes &fac, int nhab){
	for(int i=0; i<j->getTotalCidades(); i++)
		if( cdd[i].getPosX() == fac.gethabx(nhab) )
			if( cdd[i].getPosY() == fac.gethaby(nhab) )
				fac.sethabcddbase(nhab, i);
}


void Heroi::movimenta()
{
	if(this->getDestinoX()!=this->getX() || this->getDestinoY()!=this->getY()) //é porque ainda nao xegou ao destino
		{
			if (this->getInstantes()!=0 ) { this->setInstantes(this->getInstantes()-1); }
			if (this->getInstantes()==0 ) //ja se pode mover
			{

				if (this->getX() > this->getDestinoX()) { this->setX(this->getX()-1); } 
				if (this->getY() > this->getDestinoY()) { this->setY(this->getY()-1); } 
	
				if (this->getX() < this->getDestinoX()) { this->setX(this->getX()+1); }
				if (this->getY() < this->getDestinoY()) { this->setY(this->getY()+1); }

			if(this->getDestinoX()!=this->getX() || this->getDestinoY()!=this->getY()) //é porque depois de se mover ainda nao se encontra no destino
			{
				this->setInstantes(this->getVelocidade()); //volta os instantes a velocidade do hab

			}else{ this->setOrdem(false); }	//ja chegou ao destino
			}
		}		

}