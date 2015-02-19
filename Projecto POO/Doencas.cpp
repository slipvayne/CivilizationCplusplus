#include "Doencas.h"


Doencas::Doencas(string s, int x, int y):artefactos(s,x,y)
{
}


void Doencas::Art(jogo *j,faccoes &f,int hab,int numfaccoes,vector <faccoes> &vfac, int largura, int altura, int ncidades)
{
int habitanteid=f.gethabid(hab);

f.eliminahab(hab);


c.gotoxy(0,46);
cout << " Caixinha de doencas! O habitante "<< habitanteid <<" ja era!";
Sleep(2000);
c.gotoxy(0,46);
cout << "                                                                             ";
}

