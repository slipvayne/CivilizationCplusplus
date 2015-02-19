#include "Sardinhas.h"


Sardinhas::Sardinhas(string s, int x, int y):artefactos(s,x,y)
{
}


void Sardinhas::Art(jogo *j,faccoes &f,int hab,int numfaccoes,vector <faccoes> &vfac, int largura, int altura, int ncidades)
{
int comida = rand()%50+51;
f.setComida(f.getComida()+comida);

c.gotoxy(0,46);
cout << " Sardinhas enlatadas! A faccao ganhou mais "<< comida <<" porcoes de comida! ";
Sleep(2000);
c.gotoxy(0,46);
cout << "                                                                             ";
}


