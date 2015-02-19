#include "Menu.h"
#include <conio.h> //para o getch


//CONSTRUTOR
menu::menu(void){
	c.setConsoleTitle(L"World of War v0.26");
	vector <string> nomefac;
	string nomef;
	int i=0;
	int escolha=0;

animacaoinicial(); //comentar para fazer skip

while (escolha< 1 || escolha > 3)
{
c.clrscr();
escolha=inicio();

switch(escolha)
	{
// ============== AO SELECCIONAR OPÇÃO 1 -> NOVO JOGO ==============
  case '1':
	  {
c.clrscr();
/* Para testar o jogo, depois comenta-se para ser mais rapido..etc */
int n_faccoes = 0;
int n_jogadores = 0;
	do{ 
		novojogotitle(); //CRIA TEXT NOVO JOGO
		c.gotoxy(15,13);
		cout << "Qual o numero de faccoes total para jogar? (min 2)" << endl;
		c.gotoxy(15,14);
		cin >> n_faccoes;
		c.clrscr();
	}while(n_faccoes < 2);
	do{ 
		novojogotitle();
		c.gotoxy(5,13);
		cout << "Das "<< n_faccoes <<" faccoes, qual o numero de jogadores reais que vao jogar? (min 1)" << endl;
		c.gotoxy(5,14);
		cin >> n_jogadores;
		c.clrscr();
	}while(n_jogadores < 1);
	

fflush(stdin);	
	for(i=0;i<n_jogadores;i++)
	{
	novojogotitle();
	c.gotoxy(13,13);
	cout << "Para a faccao [ "<<i+1<<" ] introduza um nome: (min 3 caracteres)" << endl;
	c.gotoxy(13,14);
	getline(cin,nomef);
	if(nomef.length()>=3)
	{	
	nomefac.push_back(nomef);
	}else{ i--; }
	c.clrscr();
	}

	for(i=(n_faccoes-n_jogadores);i>0;i--) //dar um numero ao CPU auto (ou gera-se/pede-se um nome?)
	{
	char cpunum[6];
	sprintf_s(cpunum,"CPU%d",i);	
	nomefac.push_back(cpunum);
	}		

	jogo novojogo(n_faccoes,nomefac); //CONSTROI UM NOVO JOGO COM AS FACCOES!! (ainda tem ke se alterar algumas cenas)

int largura,altura;
	do{
		novojogotitle();
		c.gotoxy(22,12);
		cout << "Qual a largura do mapa? (min 5)" << endl;
		c.gotoxy(22,13);
		cin >> largura;
		c.gotoxy(22,15);
		cout << "... e a altura do mapa? (min 5)" << endl;
		c.gotoxy(22,16);
		cin >> altura;
		c.clrscr();
	}while(largura < 5 || altura < 5);

	novojogo.jogar(n_faccoes,largura,altura); //COMECA A JOGAR O JOGO!! (ainda tem ke se alterar algumas cenas)

	escolha=0;
	break;
	  }

// ============== AO SELECCIONAR OPÇÃO 2 -> LOAD GAME ==============
case '2':
	{
c.clrscr();
loadgametitle();
		c.gotoxy(20,10);
		cout << "Escolha um jogo para retomar: (DEMO)";
		c.gotoxy(22,12);
		cout << " 1 - oiasjfij";
		c.gotoxy(22,13);
		cout << " 2 - insane";
		c.gotoxy(22,14);
		cout << " 3 - lolol";
		c.gotoxy(22,15);
c.setTextColor(c.CINZENTO);
		cout << " 4 - LIVRE";
		c.gotoxy(22,16);
		cout << " 5 - LIVRE";
		c.gotoxy(22,18);
c.setTextColor(c.AMARELO_CLARO);
		cout << " 0 - << VOLTAR";
c.setTextColor(c.BRANCO);

escolha=_getch();
switch(escolha)
{
case '0': { break; }
}
	escolha=0;
	break;
	}
case '3':
	{
	c.clrscr();
	animacaoinicial();
	exit(0);
	}
}
}
}

void menu::preenchebackgroundCYAN()
{
	c.setBackgroundColor(c.CYAN);
	for(int i=0; i<=(50*45);i++)
	{ cout <<" "; 	}
}

int menu::inicio()
{ 
logo();
c.setTextColor(c.AMARELO_CLARO);

c.gotoxy(25,4); cout << ".-.   .-..----..-. .-..-. .-.";
c.gotoxy(25,5); cout << "|  `.'  || {_  |  `| || | | |";
c.gotoxy(25,6); cout << "| |\\ /| || {__ | |\\  || |_| |";
c.gotoxy(25,7); cout << "`-' ` `-'`----'`-' `-'`-----'";
c.setTextColor(c.BRANCO);
c.gotoxy(30,10); cout << " 1 - NOVO JOGO ";
c.gotoxy(30,12); cout << " 2 - LOAD GAME ";
c.gotoxy(30,14); cout << " 3 -   SAIR ";
c.gotoxy(31,16);

return _getch();
}

void menu::logo()
{
c.setTextColor(c.CYAN);
c.gotoxy(17,0);
cout << ". . . .-. .-. .   .-.   .-. .-.   . . . .-. .-. ";
c.gotoxy(17,1);
cout << "| | | | | |(  |   |  )  | | |-    | | | |-| |(   ";
c.gotoxy(17,2);
cout << "`.'.' `-' ' ' `-' `-'   `-' '     `.'.' ` ' ' '  ";
c.setTextColor(c.BRANCO);
}

void menu::animacaoinicial()
{ 

int y=1;
int x=6;
int tempo=50;

c.setTextColor(c.VERDE);

c.gotoxy(x,y);
cout << "oooooo   oooooo     oooo                    oooo        .o8 ";Sleep(tempo);
c.gotoxy(x,++y);
cout << "`888.    `888.     .8'                     `888        888   ";Sleep(tempo);
c.gotoxy(x,++y);
cout << " `888.   .8888.   .8'    .ooooo.  oooo d8b  888   .oooo888   ";Sleep(tempo);
c.gotoxy(x,++y);
cout << "  `888  .8'`888. .8'    d88' `88b `888''8P  888  d88' `888 ";Sleep(tempo);
c.gotoxy(x,++y);
cout << "   `888.8'  `888.8'     888   888  888      888  888   888   ";Sleep(tempo);
c.gotoxy(x,++y);
cout << "    `888'    `888'      888   888  888      888  888   888   ";Sleep(tempo);
c.gotoxy(x,++y);
cout << "     `8'      `8'       `Y8bod8P' d888b    o888o `Y8bod88P""  ";

++y;
x=8;

c.setTextColor(c.CINZENTO);

c.gotoxy(x,++y);   
cout << "                               .o88o.  ";Sleep(tempo);
c.gotoxy(x,++y);   
cout << "                               888 `' ";Sleep(tempo);
c.gotoxy(x,++y);   
cout << "                    .ooooo.  o888oo    ";Sleep(tempo);
c.gotoxy(x,++y);   
cout << "                    d88' `88b  888     ";Sleep(tempo);
c.gotoxy(x,++y);   
cout << "                    888   888  888     ";Sleep(tempo);
c.gotoxy(x,++y);   
cout << "                    888   888  888     ";Sleep(tempo);
c.gotoxy(x,++y);   
cout << "                    `Y8bod8P' o888o    ";Sleep(tempo);

++y;
x=10;

c.setTextColor(c.AMARELO);

c.gotoxy(x,++y);   
cout << "      oooooo   oooooo     oooo    ";Sleep(tempo);                
c.gotoxy(x,++y);   
cout << "       `888.    `888.     .8'     ";Sleep(tempo);                
c.gotoxy(x,++y);   
cout << "        `888.   .8888.   .8'    .oooo.   oooo d8b  ";Sleep(tempo);
c.gotoxy(x,++y);   
cout << "        `888  .8'`888. .8'    `P  )88b  `888''8P  ";Sleep(tempo);
c.gotoxy(x,++y);   
cout << "         `888.8'  `888.8'      .oP'888   888      ";Sleep(tempo);
c.gotoxy(x,++y);   
cout << "          `888'    `888'      d8(  888   888      ";Sleep(tempo);
c.gotoxy(x,++y);   
cout << "            `8'      `8'       `Y888'8o d888b    ";Sleep(tempo);

Sleep(2000); 
x=0;
for(y=0;y<30;y++){
c.gotoxy(x,y);
cout << "                                                                             ";
Sleep(50);
}

c.setTextColor(c.BRANCO);
c.clrscr();
}

void menu::novojogotitle(){
int x=15;
int y=0;
c.setTextColor(c.AMARELO_CLARO);

		c.gotoxy(x,y);
		cout << "  _   _                        _                 ";
		c.gotoxy(x,++y);
		cout << " | \\ | |                      | |                  ";
		c.gotoxy(x,++y);
		cout << " |  \\| | _____   _____        | | ___   __ _  ___  ";
		c.gotoxy(x,++y);
		cout << " | . ` |/ _ \\ \\ / / _ \\   _   | |/ _ \\ / _` |/ _ \\ ";
		c.gotoxy(x,++y);
		cout << " | |\\  | (_) \\ V / (_) | | |__| | (_) | (_| | (_) |";
		c.gotoxy(x,++y);
		cout << " |_| \\_|\\___/ \\_/ \\___/   \\____/ \\___/ \\__, |\\___/ ";
		c.gotoxy(x,++y);
		cout << "                                        __/ |   ";  
		c.gotoxy(x,++y);
		cout << "                                       |___/  "; 
c.setTextColor(c.BRANCO);
}
  
void menu::loadgametitle(){
int x=12;
int y=0;
c.setTextColor(c.AMARELO_CLARO);

		c.gotoxy(x,y);
		cout << "  _                      _    _____                     ";
		c.gotoxy(x,++y);
		cout << " | |                    | |  / ____|                    ";
		c.gotoxy(x,++y);
		cout << " | |      ___   __ _  __| | | |  __  __ _ _ __ ___   ___";
		c.gotoxy(x,++y);
		cout << " | |     / _ \\ / _` |/ _` | | | |_ |/ _` | '_ ` _ \\ / _ \\";
		c.gotoxy(x,++y);
		cout << " | |____| (_) | (_| | (_| | | |__| | (_| | | | | | |  __/";
		c.gotoxy(x,++y);
		cout << " |______|\\___/ \\__,_|\\__,_|  \\_____|\\__,_|_| |_| |_|\\___|";
c.setTextColor(c.BRANCO);
}


                                                 


//TEXT ( http://patorjk.com/software/taag/ -> BANNER ASCII )