#include "AMisterio.h"


AMisterio::AMisterio(string s, int x, int y):artefactos(s,x,y)
{
}


void AMisterio::Art(jogo *j,faccoes &f,int hab,int numfaccoes,vector <faccoes> &vfac, int largura, int altura, int ncidades)
{
if(rand()%2==0) //BONUS DUPLICA
{
f.setComida(f.getComida()*2);
f.setOuro(f.getOuro()*2);

c.gotoxy(0,46);
cout << " Artefacto Misterio! A faccao ganhou o dobro da comida e ouro! ";
Sleep(2000);
c.gotoxy(0,46);
cout << "                                                                             ";
}else{  //RETIRA METADE

f.setComida(f.getComida()/2);
f.setOuro(f.getOuro()/2);

c.gotoxy(0,46);
cout << " Artefacto Misterio! UPS! A faccao perdeu metade da comida e ouro! ";
Sleep(2000);
c.gotoxy(0,46);
cout << "                                                                             ";

}
}