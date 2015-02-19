#include "Panfletos.h"

Panfletos::Panfletos(string s, int x, int y):artefactos(s,x,y)
{
}


void Panfletos::Art(jogo *j,faccoes &f,int hab,int numfaccoes,vector <faccoes> &vfac, int largura, int altura, int ncidades)
{

int habitanteid=f.gethabid(hab);
string tipo;

if(f.getHabTipo(hab)=="HC"){ tipo="C";}
if(f.getHabTipo(hab)=="HH"){ tipo="H";}
if(f.getHabTipo(hab)=="HP"){ tipo="P";}
if(f.getHabTipo(hab)=="HM"){ tipo="M";}
if(f.getHabTipo(hab)=="HS"){ tipo="S";}

while(1)
{
int aleatorio=rand()%numfaccoes;
	if(vfac[aleatorio].getId() != f.getId())
	{	
		//f.eliminahab(hab); //elimina o habitante da faccao actual
		vfac[aleatorio].setvechab(j->adicionarhab(j->randomizarPosArtefactos(largura),j->randomizarPosArtefactos(altura),tipo));

	

c.gotoxy(0,46);
cout << "Panfletos deprimentes! O habitante "<< habitanteid <<" desertou para uma faccao inimiga! (" << vfac[aleatorio].getNome() <<")";
Sleep(2000);
c.gotoxy(0,46);
cout << "                                                                                                     ";
		break;
	}
}



//passar a informacao total das faccoes e fzr random a uma sem ser a mesma, eliminar o habitante e criar um novo habitante na nova faccao
//fora outros pormenores..
}
