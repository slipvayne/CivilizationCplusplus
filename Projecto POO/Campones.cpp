#include "Campones.h"
#include "Jogo.h"


Campones::Campones(int x,int y,int inst,string t):habitantes(2,2,x,y,t,inst){

//foge=false;
//init();

}

 // bool Campones::getFoge(){ return foge;}

//	void Campones::setFoge(bool r){ foge=r; }

void Campones::Accao(jogo *j,int hab,faccoes &fac,int l,int a,vector <faccoes> &vfac,int nfac,vector <artefactos*> &vart){ 


	for(int z=0; z <(signed)vart.size(); z++) {
		if (vart[z]->getY()==this->getY() && vart[z]->getX()==this->getX()){
		{ vart[z]->Art(j,vfac[nfac],hab,vfac.size(),vfac,l,a,j->getTotalCidades()); vart[z]->setX(-1); vart[z]->setY(-1);}}
}

	this->criar_cidade(j, fac, hab);

	this->atribuir_cidade_base(j,j->getCidades(),fac,hab);

	this->produzir_comida(j,j->getCidades(),fac,hab);
	


	if(this->getOrdem()==false){
	//j->movimenta_habitante(fac, l, a, hab); //andar aleatoriamente se PC , se pessoa verificaar pos
	}else{
this->movimenta();
	}


	this->limite_cidade(j, fac, hab);

	this->consumir_comida(fac);

}


//consumir comida (campones consome 1)
void Campones::consumir_comida(faccoes &fac){

	if(fac.getComida() < 0)
		fac.setComida(0);
	else
		fac.setComida( fac.getComida() - 1 );

}

void Campones::movimenta()
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


//função que evita que o camponês saia dos limites da cidade (area de 5x5)
  //nao se afasta mais do que 5 quadriculas da sua cidade base
  //se ele sair do limite, é colocado dentro da area novamente (cidade[X] é a cidade base do habitante!) habitante.getCidadeBase().getPosX() ?
void Campones::limite_cidade(jogo *j, faccoes &fac, int hab){
	
	//j->getCidades()[fac.gethabcddbase(hab)].getPosX()


	//limite canto s.e.
	if((j->getCidades()[fac.gethabcddbase(hab)].getPosX() - fac.gethabx(hab) > 5) && (j->getCidades()[fac.gethabcddbase(hab)].getPosY() - fac.gethaby(hab) > 5)){
		fac.sethabx(hab, fac.gethabx(hab) + 1);
		fac.sethaby(hab, fac.gethaby(hab) + 1);
		return;
	}
	//limite canto s.d.
	if((fac.gethabx(hab) - j->getCidades()[fac.gethabcddbase(hab)].getPosX() > 5) && (j->getCidades()[fac.gethabcddbase(hab)].getPosY() - fac.gethaby(hab) > 5)){
		fac.sethabx(hab, fac.gethabx(hab) - 1);
		fac.sethaby(hab, fac.gethaby(hab) + 1);
		return;
	}
	//limite canto i.e.
	if((j->getCidades()[fac.gethabcddbase(hab)].getPosX() - fac.gethabx(hab) > 5) && (fac.gethaby(hab) > 5 - j->getCidades()[fac.gethabcddbase(hab)].getPosY() > 5)){
		fac.sethabx(hab, fac.gethabx(hab) + 1);
		fac.sethaby(hab, fac.gethaby(hab) - 1);
		return;
	}
	//limite canto i.d.
	if((fac.gethabx(hab) - j->getCidades()[fac.gethabcddbase(hab)].getPosX() > 5) && (fac.gethaby(hab) - j->getCidades()[fac.gethabcddbase(hab)].getPosY() > 5)){
		fac.sethabx(hab, fac.gethabx(hab) - 1);
		fac.sethaby(hab, fac.gethaby(hab) - 1);
		return;
	}

	//limite esquerdo
	if(j->getCidades()[fac.gethabcddbase(hab)].getPosX() - fac.gethabx(hab) > 5)
		fac.sethabx(hab, fac.gethabx(hab) + 1);
	//limite direito
	if(fac.gethabx(hab) - j->getCidades()[fac.gethabcddbase(hab)].getPosX() > 5)
		fac.sethabx(hab, fac.gethabx(hab) - 1);
	//limite baixo
	if(fac.gethaby(hab) - j->getCidades()[fac.gethabcddbase(hab)].getPosY() > 5)
		fac.sethaby(hab, fac.gethaby(hab) - 1);
	//limite cima
	if(j->getCidades()[fac.gethabcddbase(hab)].getPosY() - fac.gethaby(hab) > 5)
		fac.sethaby(hab, fac.gethaby(hab) + 1);
	
	return;

}

//criar cidade
  //recebe como argumentos, o ponteiro para as cidades, a facção do habitante e o habitante que vai criar a cidade
  //array das cidades, vector das faccoes, n da faccao, n do habitante
void Campones::criar_cidade(jogo *j, faccoes &fac, int hab){


	int aux; //variavel auxiliar para o random
	aux = rand() % 100; //probabilidade de criar uma cidade vai de 0 a 100%


	//	se ((nao existir nenhuma cidade desta faccao) && (existirem recursos suficientes para criar a cidade) ) {
	if( (fac.verificar_cidades(j,j->getCidades(), fac.getId()) == 0) && (fac.verificar_recursos(0,10) == 1) ){ // a cidade custa 0 de comida e 10 de ouro
	
		if(aux <= 80){
					
				//criar cidade
				j->setCidades(j->CriaObjectosCidade(j->getCidades(),j->getTotalCidades()));

				j->getCidades()[j->getTotalCidades()].setNomeCidade("Cidade"); //nome da cidade 
				j->getCidades()[j->getTotalCidades()].setFid(fac.getId()); //Id da faccao 
				j->getCidades()[j->getTotalCidades()].setPosX( fac.gethabx(hab) ); //PosX
				j->getCidades()[j->getTotalCidades()].setPosY( fac.gethaby(hab) ); //PosY
				j->getCidades()[j->getTotalCidades()].setId(j->getTotalCidades()+1);
				j->setTotalCidades(j->getTotalCidades()+1); // importante
				
				fac.setOuro( fac.getOuro() - 10 );  //consumir recursos (10 de ouro)		
				return;				
			}
		}else{
			//se tiver recursos suficientes (10 de ouro)
			if( fac.verificar_recursos(0,10) == 1){

				//LIMITE ESQUERDO
				//if(cidade[Nº_DA_CIDADE_BASE_DO_HABITANTE].getPosX() - habitante.getPosX() > 3){
				if(j->getCidades()[fac.gethabcddbase(hab)].getPosX() - fac.gethabx(hab) > 3){
					//if((aux <= 10) && (existirem recursos suficientes para criar a cidade)){
					if( aux <= 10 ){
						//criar cidade
						j->setCidades(j->CriaObjectosCidade(j->getCidades(),j->getTotalCidades()));

						j->getCidades()[j->getTotalCidades()].setNomeCidade("Cidade"); //nome da cidade 
						j->getCidades()[j->getTotalCidades()].setFid(fac.getId()); //Id da faccao 
						j->getCidades()[j->getTotalCidades()].setPosX( fac.gethabx(hab) ); //PosX
						j->getCidades()[j->getTotalCidades()].setPosY( fac.gethaby(hab) ); //PosY
						j->getCidades()[j->getTotalCidades()].setId(j->getTotalCidades()+1);
						j->setTotalCidades(j->getTotalCidades()+1); // importante

						fac.setOuro( fac.getOuro() - 10 );  //consumir recursos (10 de ouro)
						return;
					}
				}

				//LIMITE DIREITO
				//if(habitante.getPosX() - cidade[X].getPosX() > 3)
				if(fac.gethabx(hab) - j->getCidades()[fac.gethabcddbase(hab)].getPosX() > 3){
					//if((aux <= 10) && (existirem recursos suficientes para criar a cidade)){
					if( aux <= 10 ){
						//criar cidade
						j->setCidades(j->CriaObjectosCidade(j->getCidades(),j->getTotalCidades()));

						j->getCidades()[j->getTotalCidades()].setNomeCidade("Cidade"); //nome da cidade 
						j->getCidades()[j->getTotalCidades()].setFid(fac.getId()); //Id da faccao 
						j->getCidades()[j->getTotalCidades()].setPosX( fac.gethabx(hab) ); //PosX
						j->getCidades()[j->getTotalCidades()].setPosY( fac.gethaby(hab) ); //PosY
						j->getCidades()[j->getTotalCidades()].setId(j->getTotalCidades()+1);
						j->setTotalCidades(j->getTotalCidades()+1); // importante

						fac.setOuro( fac.getOuro() - 10 );  //consumir recursos (10 de ouro)
						return;
					}
				}
	
				//LIMITE BAIXO
				//if(habitante.getPosY() - cidade[X].getPosY() > 3)
				if(fac.gethaby(hab) - j->getCidades()[fac.gethabcddbase(hab)].getPosY() > 3){
					//if((aux <= 10) && (existirem recursos suficientes para criar a cidade)){
					if( aux <= 10 ){
						//criar cidade
						j->setCidades(j->CriaObjectosCidade(j->getCidades(),j->getTotalCidades()));

						j->getCidades()[j->getTotalCidades()].setNomeCidade("Cidade"); //nome da cidade 
						j->getCidades()[j->getTotalCidades()].setFid(fac.getId()); //Id da faccao 
						j->getCidades()[j->getTotalCidades()].setPosX( fac.gethabx(hab) ); //PosX
						j->getCidades()[j->getTotalCidades()].setPosY( fac.gethaby(hab) ); //PosY
						j->getCidades()[j->getTotalCidades()].setId(j->getTotalCidades()+1);
						j->setTotalCidades(j->getTotalCidades()+1); // importante

						fac.setOuro( fac.getOuro() - 10 );  //consumir recursos (10 de ouro)
						return;
					}
				}
	
				//LIMITE CIMA
				//if(cidade[X].getPosY() - habitante.getPosY() > 3)
				if(j->getCidades()[fac.gethabcddbase(hab)].getPosY() - fac.gethaby(hab) > 3){
					//if((aux <= 10) && (existirem recursos suficientes para criar a cidade)){
					if( aux <= 10 ){
						//criar cidade
						j->setCidades(j->CriaObjectosCidade(j->getCidades(),j->getTotalCidades()));

						j->getCidades()[j->getTotalCidades()].setNomeCidade("Cidade"); //nome da cidade 
						j->getCidades()[j->getTotalCidades()].setFid(fac.getId()); //Id da faccao 
						j->getCidades()[j->getTotalCidades()].setPosX( fac.gethabx(hab) ); //PosX
						j->getCidades()[j->getTotalCidades()].setPosY( fac.gethaby(hab) ); //PosY
						j->getCidades()[j->getTotalCidades()].setId(j->getTotalCidades()+1);
						j->setTotalCidades(j->getTotalCidades()+1); // importante

						fac.setOuro( fac.getOuro() - 10 );  //consumir recursos (10 de ouro)
						return;
					}
				}
			} //fim if(recursos)
		} //fim else

}



//atribuir cidade_base
void Campones::atribuir_cidade_base(jogo *j, cidade *cdd, faccoes &fac, int nhab){
	for(int i=0; i<j->getTotalCidades(); i++)
		if( cdd[i].getPosX() == fac.gethabx(nhab) )
			if( cdd[i].getPosY() == fac.gethaby(nhab) )
				fac.sethabcddbase(nhab, i);
}



//detectar cidade (verifica se um determinado habitante esta em cima de alguma cidade da sua faccao)
//1- sim, 0- nao
int Campones::verificar_cidade(jogo *j,cidade *cdd, faccoes &fac, int nhab){
	for(int i=0; i<j->getTotalCidades(); i++)
		if( cdd[i].getPosX() == fac.gethabx(nhab) )
			if( cdd[i].getPosY() == fac.gethaby(nhab) )
				return 1;

	return 0;
}

//produzir comida (+1 dentro da cidade ou +3 fora)
void Campones::produzir_comida(jogo *j,cidade *cdd, faccoes &fac, int nhab){

	if( this->verificar_cidade(j,cdd, fac, nhab) == 1 )
		fac.setComida( fac.getComida() + 1 );	//produzir 1 unidade
	else
		fac.setComida( fac.getComida() + 3 ); //produzir 3 unidades

}

