#include "Cola.h"
#include "Jogo.h"


Cola::Cola(string s, int x, int y):artefactos(s,x,y)
{
}


void Cola::Art(jogo *j,faccoes &f,int hab,int numfaccoes,vector <faccoes> &vfac, int largura, int altura, int ncidades)
{

j->setCidades(j->CriaObjectosCidade(j->getCidades(),j->getTotalCidades()));

j->getCidades()[j->getTotalCidades()].setNomeCidade("CidadeTCola"); //nome da cidade 
j->getCidades()[j->getTotalCidades()].setFid(f.getId()); //Id da faccao 
j->getCidades()[j->getTotalCidades()].setPosX( f.gethabx(hab) ); //PosX
j->getCidades()[j->getTotalCidades()].setPosY( f.gethaby(hab) ); //PosY
j->getCidades()[j->getTotalCidades()].setId(j->getTotalCidades()+1);


c.gotoxy(0,46);
cout << "Tudo de Cola! O habitante "<< f.gethabid(hab) <<" fundou uma nova cidade para a sua faccao!("<< f.getNome() <<")";
Sleep(2000);
c.gotoxy(0,46);
cout << "                                                                                                     ";

j->setTotalCidades(j->getTotalCidades()+1); // importante
}

