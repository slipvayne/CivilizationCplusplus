#include "Moedas.h"


Moedas::Moedas(string s, int x, int y):artefactos(s,x,y)
{
}


void Moedas::Art(jogo *j,faccoes &f,int hab,int numfaccoes,vector <faccoes> &vfac, int largura, int altura, int ncidades)
{
int moedas;
moedas=rand()%50+51;
f.setOuro(f.getOuro()+moedas);

c.gotoxy(0,46);
cout << " Montinho de rodelas metalicas! A faccao ganhou mais "<< moedas <<" moedas de ouro! ";
Sleep(2000);
c.gotoxy(0,46);
cout << "                                                                                        ";
}
