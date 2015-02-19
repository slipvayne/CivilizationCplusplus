#include "Jogo.h"

//inicializa os contadores todos a zero (melhores alternativas?)
int habitantes::contaHab=0;
int faccoes::contaid=0;
int faccoes::contacor=0;
int artefactos::conta=0;

//CONSTRUTOR
jogo::jogo(int nfaccoes,vector <string> nomefac){

for(int i=0;i<nfaccoes;i++)
{
if(nomefac.at(i).compare(0,3,"CPU")==0)
{ 
faccoes cria(nomefac.at(i),1); 
vfac.push_back(cria);
}else{
faccoes cria(nomefac.at(i),0); 
vfac.push_back(cria); } // 0-> jogador normal
}
}

//DESTRUTOR
jogo::~jogo(){

	while (!vart.empty())
  {
		vart.erase(vart.begin());
  }
	
	while (!vhab.empty())
  {
	vhab.erase(vhab.begin());
		
	}

	while(!vfac.empty()){
		vfac.erase(vfac.begin());
	}


}


void jogo::jogar(int nfaccoes, int largura,int altura){
	srand ((int)time(NULL) ); //seed do random
	int x=0,y=0,z=9;
	int ncidades=0;
	int numfaccoesactivas;
    
	novojogotitle();
	c.gotoxy(22,8); cout << "Nome das Faccoes:";
	for(int fac=0;fac<(signed)vfac.size();fac++)
{
	c.setBackgroundColor(vfac[fac].getCor());
	c.gotoxy(22,++z);
	cout << vfac[fac].getNome();
	c.setBackgroundColor(c.PRETO);
	if(vfac[fac].getJogador()==0) { cout << " (Pessoa)"; }else{cout << " (Computador)";}
}
	++z; c.gotoxy(22,++z);
	cout << "MAPA: " << largura <<" x "<< altura; 
	++z; c.gotoxy(22,++z);
	system("pause");	

	c.clrscr();
	c.setTextSize(8,8);
	c.setScreenSize(50,80);

	setTotalCidades(0);
	setCidades(new cidade(getTotalCidades()));
	
	
//GERAR ARTEFACTOS=================================================->PASSAR A FUNCAO
	
	int n_art = 0;//numero de artefactos;

	if((largura + altura) < 100)
		n_art = (largura + altura) / 20 + 1; //para mapas pequenos
	else
		n_art = (largura + altura) / 12; //para mapas maiores

n_art = 10; //DEMO
for(int i = 0; i < n_art; i++) 
{
	adicionaArtefactos(randomizarArtefacto(),randomizarPosArtefactos(largura),randomizarPosArtefactos(altura));
} //ELE VERIFICA SE O ESPAÇO JA TA A SER UTILIZADO?


	

//ARTEFACTOS end===================================================================


//TESTE RANDOM 1 HABITANTE
for(int i=0;i<(signed)vfac.size();i++)
{
int randomlarg,randomaltur;
randomlarg = rand() % largura;
randomaltur = rand() % altura;
vfac[i].setvechab(adicionarhab(randomlarg,randomaltur,"C")); 
// Cria habitante pra cada faccao teste (sim pode calhar em cima de qualquer coisa!.. para ja...)
}


	
reloadinfo(largura,altura,vart,vfac,x,y); //esta funcao substitiu as funcoes (grande SPAM) que estavam a fazer reload de tudo


//=======LINHA COMANDOS===========
vector <string> comandos;
string comando;
int linha_comandos;      //numero da actual linha, da linha de comandos
linha_comandos = 36;

//vai existir faccoesemjogo(que ainda nao foram eliminadas) / totalfaccoes(iniciais)
int jogafaccao=0; //comeca na faccao 0
int totalfaccoes=nfaccoes; //alterar consoante faccoes introduzidas 
int faccoesemjogo=totalfaccoes; //no inicio o total de faccoes é igual as faccoes em jogo
int comandosintrosucesso=0;
char tecla;


while (1) {		
				

for(;jogafaccao<=faccoesemjogo;)
{
		c.gotoxy(0,linha_comandos); //imprimir linha de comandos
		imprime_cor(vfac[jogafaccao].getCor());
		cout << vfac[jogafaccao].getNome() << " >";
		c.setBackgroundColor(c.PRETO);
		cout << " ";
			
tecla = c.getch();

	if(tecla == c.ENTER){

getline(cin,comando);	
comandos.push_back(comando); //armazena todo o texto que foi introduzido

	
	if(comando=="NEXT" || comando=="next")
	{

	tratacomandos(largura,altura,vart,vfac,x,y,comandos,jogafaccao,ncidades,cidades); //VALIDA E TRATA OS COMANDOS

	c.gotoxy(0,46);
	cout << " [ Actualizacao: ] ";
	reloadinfo(largura,altura,vart,vfac,x,y,jogafaccao); //ACTUALIZA TUDO
	Sleep(1500); //para ver alteracoes de COMIDA E OURO da faccao actual e prossegue
	c.gotoxy(0,46);
	cout << "                     ";

	for(int fac=0;fac<(signed)vfac.size();fac++){
	for(int i=0;i<vfac[fac].gettamvechab();i++)	{		
	vfac[fac].habAccao(this,i,vfac[fac],largura,altura,vfac,fac,vart); //accao por parte de todos os habiantes
	}
	}
	
	
	numfaccoesactivas=verificaFaccoes(largura,altura,vart,vfac,x,y,faccoesemjogo,jogafaccao); //verifica se alguma faccao foi eliminada


	if(jogafaccao==faccoesemjogo-1) //se for a ultima faccao
	{
		jogafaccao=0; //voltar a primeira faccao
	}else{
		jogafaccao++;} //passa para a proxima faccao!

	if(vfac[jogafaccao].getActivo()==false)
	{
		for(int i=jogafaccao;i<(signed)vfac.size();i++)
		{
		if(vfac[i].getActivo()==true)
		{jogafaccao=i; break; }
		}
	if(vfac[jogafaccao].getActivo()==false){
	  for(int i=0;i<(signed)vfac.size();i++){
		if(vfac[i].getActivo()==true){
		{jogafaccao=i; break; }
		}
	  }
	}
	}
	if(numfaccoesactivas<=1) 
	{ 
	c.gotoxy(0,46);
	cout << "THE END! A faccao ' " << vfac[jogafaccao].getNome() << " ' ganhou o jogo! " << endl << endl;
	system("pause"); 
	//delete jogo;
	menu Iniciar;
	Iniciar;
	}


	comandos.clear(); //elimina todos os comandos do vector apos serem executados! 	

	

	reloadinfo(largura,altura,vart,vfac,x,y,jogafaccao); //ACTUALIZA TUDO para a nova fac

	}
				
			linha_comandos++;

//limpar a linha de comandos
if(linha_comandos > 44){
linha_comandos = 36;
c.clrscr();
reloadinfo(largura,altura,vart,vfac,x,y,jogafaccao); //ACTUALIZA TUDO
}
			
	}
	
	//ESCAPE
	if(tecla == c.ESCAPE) { break; }
		
	//ESQUERDA	
	if(tecla == c.ESQUERDA){
			c.gotoxy(0,0);
			if(x!=0)			//so anda para a esquerda se nao estiver no limite do mapa
				x--;
			c.setBackgroundColor(c.PRETO);
			reloadinfo(largura,altura,vart,vfac,x,y,jogafaccao); //ACTUALIZA TUDO
	}

	//DIREITA
	if(tecla == c.DIREITA){
			c.gotoxy(0,0);
			if((largura > 38) && (largura - x != 38)) //so anda para a direita se nao estiver no limite do mapa
				x++;
			c.setBackgroundColor(c.PRETO);
			reloadinfo(largura,altura,vart,vfac,x,y,jogafaccao); //ACTUALIZA TUDO
		
	}
	
	//CIMA
	if(tecla == c.CIMA){
			c.gotoxy(0,0);
			if(y!=0)			//so anda para cima se nao estiver no limite do mapa
				y--;
			c.setBackgroundColor(c.PRETO);
			reloadinfo(largura,altura,vart,vfac,x,y,jogafaccao); //ACTUALIZA TUDO


	}

	//BAIXO
	if(tecla == c.BAIXO){
			c.gotoxy(0,0);
			if((altura > 16) && (altura - y != 16))	//so anda para baixo se nao estiver no limite do mapa
				{y++;
			 c.setBackgroundColor(c.PRETO);
	         reloadinfo(largura,altura,vart,vfac,x,y,jogafaccao); //ACTUALIZA TUDO
			}

	}

}
}
}

//ADICIONAR HABITANTES
habitantes* jogo::adicionarhab(int x,int y,string tipo){
	if(tipo=="C"){
	habitantes* hab=new Campones(x,y);
	vhab.push_back(hab);
		return hab;}
	if(tipo=="H"){
		habitantes* hab=new Heroi(x,y);
	vhab.push_back(hab);
	return hab;
	}
	if(tipo=="M"){
		habitantes* hab=new Mineiro(x,y);
	vhab.push_back(hab);
	return hab;
	}
	if(tipo=="S"){
		habitantes* hab=new Soldado(x,y);
	vhab.push_back(hab);
	return hab;
	}
	if(tipo=="P"){
		habitantes* hab=new HMisterio(x,y);
	vhab.push_back(hab);
	return hab;
	}	
	return 0;
}

void jogo::reloadinfo(int largura,int altura,vector <artefactos*> vart,vector <faccoes> &vfac,int x, int y,int jogafaccao) //faz reload de tudo, falta cidade e etc
{
c.gotoxy(0,0);
t.imprime_mapa(largura,altura,x,y); // IMPRIME MAPA

vector <artefactos*>::iterator it;
for(it=vart.begin(); it < vart.end(); it++) //IMPRIME ARTEFACTOS
		imprime_artefacto(x,y,**it);

for(int fac=0;fac<(signed)vfac.size();fac++)
{
	for(int i=0;i<vfac[fac].gettamvechab();i++) // IMPRIME HABITANTES
	{		

	imprime_habitante(x,y,vfac[fac].gethabx(i),vfac[fac].gethaby(i),vfac[fac].getCor(),vfac[fac].gethabid(i),vfac[fac].getHabTipo(i));
	}
}

for(int cid=0;cid<getTotalCidades();cid++)
{
	imprime_cidades(x,y,getCidades()[cid].getPosX(),getCidades()[cid].getPosY(),vfac[getCidades()[cid].getFid()-1].getCor(),getCidades()[cid].getId());
}
c.gotoxy(0,47); for(int i=0; i<80;i++){cout << "=";}
c.gotoxy(0,48); for(int i=0; i<80;i++){cout << " ";} //limpa primeiro a linha
c.gotoxy(0,48);	cout << "COMIDA: " << vfac[jogafaccao].getComida() << " | OURO: " << vfac[jogafaccao].getOuro(); 

}



int jogo::verificaFaccoes(int largura,int altura,vector <artefactos*> vart,vector <faccoes> &vfac,int x, int y,int faccoesemjogo,int &jogafaccao) //faz reload de tudo, falta cidade e etc
{
int conta=0;
for(int fac=0;fac<(signed)vfac.size();fac++)
{
	if(vfac[fac].gettamvechab()==0) //a faccao n tem habitantes! verificar por ultimo se tem alguma cidade
	{
		
		for(int cid=0;cid<getTotalCidades();cid++){
			if(getCidades()[cid].getFid()-1 == fac) { //tem uma cidade pelo menos!
				conta++; }
		}
		if (conta<=0) { 
		vfac[fac].setActivo(false);
		faccoesemjogo--;
		}
		conta=0;

	}
}
return faccoesemjogo;
}

void jogo::adicionaArtefactos(string nomeart,int x, int y)
{

	if(nomeart=="AM")
	vart.push_back((artefactos *)new Moedas(nomeart,x,y));

	if(nomeart=="AC")
	vart.push_back((artefactos *)new Doencas(nomeart,x,y));

	if(nomeart=="AE")
	vart.push_back((artefactos *)new Espelho(nomeart,x,y));

	if(nomeart=="AP")
	vart.push_back((artefactos *)new Panfletos(nomeart,x,y));

	if(nomeart=="AS")
	vart.push_back((artefactos *)new Sardinhas(nomeart,x,y));
	
	if(nomeart=="AT")
	vart.push_back((artefactos *)new Cola(nomeart,x,y));
	
	if(nomeart=="AA")
	vart.push_back((artefactos *)new AMisterio(nomeart,x,y));

}

void jogo::CriarHabitantes(string tipohab,int jogafaccao,vector <faccoes> &vfac, jogo *j, cidade *cdd)
{

if((tipohab=="C" && vfac[jogafaccao].getOuro()>=3) || (tipohab=="H" && vfac[jogafaccao].getOuro()>=20) || (tipohab=="M" && vfac[jogafaccao].getOuro()>=10)
	|| (tipohab=="S" && vfac[jogafaccao].getOuro()>=10) || (tipohab=="P" && vfac[jogafaccao].getOuro()>=10))
{
if(vfac[jogafaccao].verificar_cidade_id(j,cdd,jogafaccao+1)!=-1)
	{
		
vfac[jogafaccao].setvechab(adicionarhab(cdd[vfac[jogafaccao].verificar_cidade_id(j,cdd,jogafaccao+1)].getPosX(),cdd[vfac[jogafaccao].verificar_cidade_id(j,cdd,jogafaccao+1)].getPosY(),tipohab));

if(tipohab=="C"){ vfac[jogafaccao].setOuro(vfac[jogafaccao].getOuro()-3); }

if(tipohab=="C" || tipohab=="P" || tipohab=="S"){ vfac[jogafaccao].setOuro(vfac[jogafaccao].getOuro()-10); }

if(tipohab=="H") { vfac[jogafaccao].setOuro(vfac[jogafaccao].getOuro()-20); }
}
	
}
}

string jogo::randomizarArtefacto(){

	int aux;
	aux = rand() % 7 + 1; //obter valor random entre 1 e 7
	string tipo;

	switch (aux){
		case 1:
			tipo="AM"; //montinho de rodelas metalicas
			break;
		case 2:
			tipo="AC"; //caixinha de doencas
			break;
		case 3:
			tipo="AE"; //espelho magico
			break;
		case 4:
			tipo="AP"; //panfletos deprimentes
			break;
		case 5:
			tipo="AS"; //sardinhas enlatadas
			break;
		case 6:
			tipo="AT"; //tubo de cola
			break;
		case 7:
			tipo="AA"; //artefacto misterio
			break;
	}
	return tipo;
}

int jogo::randomizarPosArtefactos(int xy){
	return (xy=(rand() % xy)); //randomizar coordenada de 0 a "largura ou altura"
}


void jogo::tratacomandos(int largura,int altura,vector <artefactos*> vart,vector <faccoes> &vfac,int x, int y,vector <string> comandos,int jogafaccao, int ncidades, cidade* cidades)
{

vector <string>::iterator itc;   
for(itc=comandos.begin(); itc < comandos.end(); itc++) //para depois fazer pop_back
{

istringstream comandolido(*itc);

int contapalavras=0;
string palavra[50];
	do
    {
            comandolido >> palavra[contapalavras]; //extrai palavra a palavra (conta o ultimo espaço tb)        		
			contapalavras++;

    } while (comandolido); //ate ultima palavra


//TRATA COMANDOS:
	

	if(palavra[0]=="MKHAB")
	{
//	cout << "MKHAB <tipo> <linha> <coluna> para criar um habitante";


		vfac[jogafaccao].setvechab(adicionarhab(atoi(palavra[3].c_str()),atoi(palavra[2].c_str()),palavra[1]));

		//FALTA VERIFICAR LIMITES E SE ESTA ALGUM JA NESSE QUADRADO!
	}

	if(palavra[0]=="H")
	{
//	H <tipo> <NUMERO-da-cidade>

		CriarHabitantes(palavra[1],jogafaccao,vfac,this,cidades);
	
	//vfac[jogafaccao].setvechab(adicionarhab(atoi(palavra[2].c_str()),atoi(palavra[1].c_str()),&vfac[jogafaccao]));

		//FALTA VERIFICAR LIMITES E SE ESTA ALGUM JA NESSE QUADRADO!
	}
	
	else if(palavra[0]=="D")
	{
//	cout << "D <dir> <id> para deslocar um habitante";
for(int i=0;i<vfac[jogafaccao].gettamvechab();i++){
	if(vfac[jogafaccao].gethabid(i)==atoi(palavra[2].c_str()))
	{
if(palavra[1]=="N"){ 
	vfac[jogafaccao].setHabDestinoXY(i,vfac[jogafaccao].gethabx(i),vfac[jogafaccao].gethaby(i)-1);}
if(palavra[1]=="S"){
	vfac[jogafaccao].setHabDestinoXY(i,vfac[jogafaccao].gethabx(i),vfac[jogafaccao].gethaby(i)+1);}
if(palavra[1]=="O"){
	vfac[jogafaccao].setHabDestinoXY(i,vfac[jogafaccao].gethabx(i)-1,vfac[jogafaccao].gethaby(i));}
if(palavra[1]=="E"){
	vfac[jogafaccao].setHabDestinoXY(i,vfac[jogafaccao].gethabx(i)+1,vfac[jogafaccao].gethaby(i));}
	}
	
	vfac[jogafaccao].setHabInstantes(i); //inicializa instantes ate se mover
	vfac[jogafaccao].setHabOrdem(i,true); //indica que este habitante vai ter uma ordem e vai executa-la nos instantes que sao requeridos
	

}}
	
	else if(palavra[0]=="G")
	{
		vfac[jogafaccao].gettamvechab();
//	cout << "G <id> <linha> <coluna> para deslocar um habitante";
//VER LIMITES PARA CAMPONES! Maximo 5 de uma cidade!
	
for(int i=0;i<vfac[jogafaccao].gettamvechab();i++){
	if(vfac[jogafaccao].gethabid(i)==atoi(palavra[1].c_str()))
	{
	vfac[jogafaccao].setHabDestinoXY(i,atoi(palavra[3].c_str()),atoi(palavra[2].c_str()));
	vfac[jogafaccao].setHabInstantes(i); //inicializa instantes ate se mover
	vfac[jogafaccao].setHabOrdem(i,true); //indica que este habitante vai ter uma ordem e vai executa-la nos instantes que sao requeridos

	}	
	

}

	}
	
	else if(palavra[0]=="DISB")
	{
//	cout << "DISB <id-habitante> para fazer desaparecer um habitante";

	for(int i=0;i<vfac[jogafaccao].gettamvechab();i++){
	if(vfac[jogafaccao].gethabid(i)==atoi(palavra[1].c_str()))
	{
	vfac[jogafaccao].eliminahab(i);
	}

	}

	}
	
	else if(palavra[0]=="ART")
	{
//	cout << "ART <tipo> <linha> <coluna> para criar um artefacto";

	adicionaArtefactos(palavra[1],atoi(palavra[2].c_str()),atoi(palavra[3].c_str()));

	}


	else if(palavra[0]=="GOLD"){
		int quantidade_ouro; //quantidade de ouro recebida pelo comando e que será adicionada ao total de ouro da faccao
		quantidade_ouro = atoi(palavra[1].c_str());
		vfac[jogafaccao].setOuro( vfac[jogafaccao].getOuro() + quantidade_ouro ); //adicionar ouro à faccao actual
		if(vfac[jogafaccao].getOuro() < 0)
			vfac[jogafaccao].setOuro( 0 );
	}

	else if(palavra[0]=="FOOD"){
		int quantidade_comida; //quantidade de comida recebida pelo comando e que será adicionada ao total de comida da faccao
		quantidade_comida = atoi(palavra[1].c_str());
		vfac[jogafaccao].setComida( vfac[jogafaccao].getComida() + quantidade_comida ); //adicionar comida à faccao actual
		if(vfac[jogafaccao].getComida() < 0)
			vfac[jogafaccao].setComida( 0 );
	}

	else if(palavra[0]=="INFOC"){

		 c.gotoxy(30,37);
		cout << "Cidade: " << palavra[1].c_str();
	for(int i=0; i< vfac[jogafaccao].gettamvechab();i++)
	{
	for(int cid=0;cid<getTotalCidades();cid++)
	{
		if(atoi(palavra[1].c_str())==getCidades()[cid].getId() && vfac[jogafaccao].gethabx(i)==getCidades()[cid].getPosX() && vfac[jogafaccao].gethaby(i)==getCidades()[cid].getPosY() && getCidades()[cid].getFid()-1==jogafaccao){
		{ c.gotoxy(30,38);
		cout << vfac[jogafaccao].getHabTipo(i) << vfac[jogafaccao].gethabid(i);
		}
		}
	}


		
	}

	}



	

	//FALTA:
/*	A <id-do-atacante> <id-do-atacado>: Ordena ao habitante com identificador <id-do-atacante> que se mova em direcção ao habitante com identificador <id-do-atacado> e, quando chegar ao local onde se encontra, ataca-o (se isso estiver na sua natureza).
	F <id-campones> <nome-nova-cidade>: Ordena ao camponês com identificador <id-campones> que faça a fundação de uma nova cidade com nome <nome-nova-cidade>, no local onde se encontra. O camponês fica dentro da cidade.
	*/

	else if(palavra[0]=="EXIT"){
		cout << "Prima qualquer tecla para sair";
		cin.get();
		exit(0);
	}


}

}



//funcao que troca o numero da cor da faccao pela cor em si (para o fundo)
void jogo::imprime_cor(int n){
	Consola c;

	switch (n){
		case 0:
			c.setBackgroundColor(c.PRETO); 	break;
		case 1:
			c.setBackgroundColor(c.AZUL); 	break;
		case 2:
			c.setBackgroundColor(c.VERDE); 	break;
		case 3:
			c.setBackgroundColor(c.CYAN); 	break;
		case 4:
			c.setBackgroundColor(c.VERMELHO); break;
		case 5:
			c.setBackgroundColor(c.ROXO); break;
		case 6:
			c.setBackgroundColor(c.AMARELO); break;
		case 7:
			c.setBackgroundColor(c.BRANCO); break;
		case 8:
			c.setBackgroundColor(c.CINZENTO);  	break;
		case 9:
			c.setBackgroundColor(c.AZUL_CLARO);  break;
		case 10:
			c.setBackgroundColor(c.VERDE_CLARO); break;
		case 11:
			c.setBackgroundColor(c.CYAN_CLARO);  break;
		case 12:
			c.setBackgroundColor(c.VERMELHO_CLARO);  break;
		case 13:
			c.setBackgroundColor(c.COR_DE_ROSA); break;
		case 14:
			c.setBackgroundColor(c.AMARELO_CLARO); break;
		case 15:
			c.setBackgroundColor(c.BRANCO_CLARO); break;
		default:
			c.setBackgroundColor(c.PRETO); 	break;
	}

}

//funcao que imprime o habitante no mapa
// recebe o nº de deslocações na horizontal e vertical e o array de habitantes
void jogo::imprime_habitante(int dph, int dpv,int px,int py,int cor,int id,string tipo){

	int x, y;
	//converter coordenadas para o mapa
	x = ((px+1) * 2) - (dph*2);
	y = ((py+1) * 2) - (dpv*2);

	//so imprime o habitante, se este se encontrar na secção mostrada pelo mapa
	if(x <= 76 && y <= 32 && x > 0 && y > 0){
		c.gotoxy(x,y);
		//troca a cor de fundo para a da faccao do habitante
		imprime_cor(cor);
		//cout << h.getTipo();	//imprimir o tipo de habitante
		cout << tipo;
		c.gotoxy(x,y+1);		//mudar para a linha abaixo
		if(id < 10)		//imprimir o id do habitante
			cout << "0" << id;		//acrescenta um 0 se o id for menor que 10 (1 --> 01)
		else
		cout << id;
	}

	c.setBackgroundColor(c.PRETO);

}


//funcao que imprime o artefacto no mapa
 //recebe o nº de deslocações na horizontal e vertical e o array de habitantes
void jogo::imprime_artefacto(int dph, int dpv, artefactos &a){

	int x, y;
	//converter coordenadas para o mapa
	x = ((a.getX()+1) * 2) - (dph*2);
	y = ((a.getY()+1) * 2) - (dpv*2);

	//so imprime o habitante, se este se encontrar na secção mostrada pelo mapa
	if(x <= 76 && y <= 32 && x > 0 && y > 0){
		c.gotoxy(x,y);
		//troca a cor de fundo para a da faccao do habitante
		c.setTextColor(c.PRETO);
		c.setBackgroundColor(c.AMARELO_CLARO);		//cor amarela para os artefactos
		cout << a.getTipo();					//imprimir o tipo de artefacto
		c.gotoxy(x,y+1);						//mudar para a linha abaixo
		cout << "  ";							//imprimir os espacos (para ficar com fundo vermelho)
	}

	c.setBackgroundColor(c.PRETO);
	c.setTextColor(c.BRANCO);
}

//funcao que movimento um habitante
 //recebe o habitante a mover e a largura e altura do mapa
void jogo::movimenta_habitante(faccoes &fac, int l, int a, int hab){
	//calcular as coordenadas adjacentes
	//cima,baixo,esquerda,direita e s.e. s.d. i.e. i.d.

		int aux;

	// cout << hab << " | " << l << a << " | " << fac.getNome << fac.gethabx(hab) << fac.gethaby(hab) <<endl;
	//system("pause");
	//se o habitante estiver no canto s.e.
	 //deslocar para baixo OU i.d. OU direita
	if((fac.gethabx(hab) == 0) && (fac.gethaby(hab) == 0)){
		aux = rand() % 3 + 1; //random entre 1 e 3
		//se der 1 -> deslocar para baixo
		if(aux == 1){
			//fac.sethaby(hab,fac.gethaby(hab)+1);
			fac.sethaby(hab,fac.gethaby(hab)+1);
			return;
		}
		//se der 2 -> deslocar para i.d.
		if(aux == 2){
			//fac.sethabx(hab,fac.gethabx(hab)+1);
			fac.sethabx(hab,fac.gethabx(hab)+1);
			//fac.sethaby(hab,fac.gethaby(hab)+1);
			fac.sethaby(hab,fac.gethaby(hab)+1);
			return;
		}
		//se der 3 -> deslocar para direita
		if(aux == 3){
			//fac.sethabx(hab,fac.gethabx(hab)+1);
			fac.sethabx(hab,fac.gethabx(hab)+1);
			return;
		}
	}
	//se o habitante estiver no canto s.d.
	if((fac.gethabx(hab) == l-1) && (fac.gethaby(hab) == 0)){
		//deslocar para baixo OU i.e. OU esquerda
		aux = rand() % 3 + 1; //random entre 1 e 3
		//se der 1 -> deslocar para baixo
		if(aux == 1){
			fac.sethaby(hab,fac.gethaby(hab)+1);
			return;
		}
		//se der 2 -> deslocar para i.e.
		if(aux == 2){
			fac.sethabx(hab,fac.gethabx(hab)-1);
			fac.sethaby(hab,fac.gethaby(hab)+1);
			return;
		}
		//se der 3 -> deslocar para esquerda
		if(aux == 3){
			fac.sethabx(hab,fac.gethabx(hab)-1);
			return;
		}
	}
	//se o habitante estiver no canto i.e.
	if((fac.gethabx(hab) == 0) && (fac.gethaby(hab) == a-1)){
		//deslocar para cima OU s.d. OU direita
		aux = rand() % 3 + 1; // random entre 1 e 3
		//se der 1 -> deslocar para cima
		if(aux == 1){
			fac.sethaby(hab,fac.gethaby(hab)-1);
			return;
		}
		//se der 2 -> deslocar para s.d.
		if(aux == 2){
			fac.sethabx(hab,fac.gethabx(hab)+1);
			fac.sethaby(hab,fac.gethaby(hab)-1);
			return;
		}
		//se der 3 -> deslocar para direita
		if(aux == 3){
			fac.sethabx(hab,fac.gethabx(hab)+1);
			return;
		}
	}
	//se o habitante estiver no canto i.d.
	if((fac.gethabx(hab) == l-1) && (fac.gethaby(hab) == a-1)){
		//deslocar para cima OU s.e. OU esquerda
		aux = rand() % 3 + 1; // random entre 1 e 3
		//se der 1 -> deslocar para cima
		if(aux == 1){
			fac.sethaby(hab,fac.gethaby(hab)-1);
			return;
		}
		//se der 2 -> deslocar para s.e.
		if(aux == 2){
			fac.sethabx(hab,fac.gethabx(hab)-1);
			fac.sethaby(hab,fac.gethaby(hab)-1);
			return;
		}
		//se der 3 -> deslocar para esquerda
		if(aux == 3){
			fac.sethabx(hab,fac.gethabx(hab)-1);
			return;
		}
	}
	//se o habitante estiver na ultima linha
	if(fac.gethaby(hab) == a-1){
		//deslocar para cima OU esquerda OU direita OU s.e. OU s.d.
		aux = rand() % 5 + 1; // random entre 1 e 5
		//se der 1 -> deslocar para cima
		if(aux == 1){
			fac.sethaby(hab,fac.gethaby(hab)-1);
			return;
		}
		//se der 2 -> deslocar para esquerda
		if(aux == 2){
			fac.sethabx(hab,fac.gethabx(hab)-1);
			return;
		}
		//se der 3 -> deslocar para direita
		if(aux == 3){
			fac.sethabx(hab,fac.gethabx(hab)+1);
			return;
		}
		//se der 4 -> deslocar para s.e.
		if(aux == 4){
			fac.sethabx(hab,fac.gethabx(hab)-1);
			fac.sethaby(hab,fac.gethaby(hab)-1);
			return;
		}
		//se der 5 -> deslocar para s.d.
		if(aux == 5){
			fac.sethabx(hab,fac.gethabx(hab)+1);
			fac.sethaby(hab,fac.gethaby(hab)-1);
			return;
		}
	}
	//se o habitante estiver na primeira linha
	if(fac.gethaby(hab) == 0){
		//deslocar para baixo OU esquerda OU direita OU i.e. OU i.d.
		aux = rand() % 5 + 1; //random entre 1 e 5
		//se der 1 -> deslocar para baixo
		if(aux == 1){
			fac.sethaby(hab,fac.gethaby(hab)+1);
			return;
		}
		//se der 2 -> deslocar para esquerda
		if(aux == 2){
			fac.sethabx(hab,fac.gethabx(hab)-1);
			return;
		}
		//se der 3 -> deslocar para direita
		if(aux == 3){
			fac.sethabx(hab,fac.gethabx(hab)+1);
			return;
		}
		//se der 4 -> deslocar para i.e.
		if(aux == 4){
			fac.sethabx(hab,fac.gethabx(hab)-1);
			fac.sethaby(hab,fac.gethaby(hab)+1);
			return;
		}
		//se der 5 -> deslocar para i.d.
		if(aux == 5){
			fac.sethabx(hab,fac.gethabx(hab)+1);
			fac.sethaby(hab,fac.gethaby(hab)+1);
			return;
		}
	}
	//se o habitante estiver na ultima coluna
	if(fac.gethabx(hab) == l-1){
		//deslocar para cima OU baixo OU esquerda OU i.e. OU s.e.
		aux =  rand() % 5 + 1; //random entre 1 e 5
		//se der 1 -> deslocar para cima
		if(aux == 1){
			fac.sethaby(hab,fac.gethaby(hab)-1);
			return;
		}
		//se der 2 -> deslocar para baixo
		if(aux == 2){
			fac.sethaby(hab,fac.gethaby(hab)+1);
			return;
		}
		//se der 3 -> deslocar para esquerda
		if(aux == 3){
			fac.sethabx(hab,fac.gethabx(hab)-1);
			return;
		}
		//se der 4 -> deslocar para i.e.
		if(aux == 4){
			fac.sethabx(hab,fac.gethabx(hab)-1);
			fac.sethaby(hab,fac.gethaby(hab)+1);
			return;
		}
		//se der 5 -> deslocar para s.e.
		if(aux == 5){
			fac.sethabx(hab,fac.gethabx(hab)-1);
			fac.sethaby(hab,fac.gethaby(hab)-1);
			return;
		}
	}
	//se o habitante estiver na primeira coluna
	if(fac.gethabx(hab) == 0){
		//deslocar para cima OU baixo OU direita OU i.d. OU s.d.
		aux = rand() % 5 + 1; //random entre 1 e 5
		//se der 1 -> deslocar para cima
		if(aux == 1){
			fac.sethaby(hab,fac.gethaby(hab)-1);
			return;
		}
		//se der 2 -> deslocar para baixo
		if(aux == 2){
			fac.sethaby(hab,fac.gethaby(hab)+1);
			return;
		}
		//se der 3 -> deslocar para direita
		if(aux == 3){
			fac.sethabx(hab,fac.gethabx(hab)+1);
			return;
		}
		//se der 4 -> deslocar para i.d.
		if(aux == 4){
			fac.sethabx(hab,fac.gethabx(hab)+1);
			fac.sethaby(hab,fac.gethaby(hab)+1);
			return;
		}
		//se der 5 -> deslocar para s.d.
		if(aux == 5){
			fac.sethabx(hab,fac.gethabx(hab)+1);
			fac.sethaby(hab,fac.gethaby(hab)-1);
			return;
		}
	}
	//se o habitante estiver em qualquer outra parte do mapa
	//deslocar para qualquer lado
	aux = rand() % 8 + 1; //random entre 1 e 8
	//se der 1 -> deslocar para cima
	if(aux == 1){
		fac.sethaby(hab,fac.gethaby(hab)-1);
		return;
	}
	//se der 2 -> deslocar para baixo
	if(aux == 2){
		fac.sethaby(hab,fac.gethaby(hab)+1);
		return;
	}
	//se der 3 -> deslocar para esquerda
	if(aux == 3){
		fac.sethabx(hab,fac.gethabx(hab)-1);
		return;
	}
	//se der 4 -> deslocar para direita
	if(aux == 4){
		fac.sethabx(hab,fac.gethabx(hab)+1);
		return;
	}
	//se der 5 -> deslocar para s.e.
	if(aux == 5){
		fac.sethabx(hab,fac.gethabx(hab)-1);
		fac.sethaby(hab,fac.gethaby(hab)-1);
		return;
	}
	//se der 6 -> deslocar para s.d.
	if(aux == 6){
		fac.sethabx(hab,fac.gethabx(hab)+1);
		fac.sethaby(hab,fac.gethaby(hab)-1);
		return;
	}
	//se der 7 -> deslocar para i.e.
	if(aux == 7){
		fac.sethabx(hab,fac.gethabx(hab)-1);
		fac.sethaby(hab,fac.gethaby(hab)+1);
		return;
	}
	//se der 8 -> deslocar para i.d.
	if(aux == 8){
		fac.sethabx(hab,fac.gethabx(hab)+1);
		fac.sethaby(hab,fac.gethaby(hab)+1);
		return;
	}
}


//funcao para movimentar o habitante
 //recebe o habitante a movimentar, a largura e altura do mapa (para saber os limites)

void jogo::movimenta_habitante_pos(habitantes &h, int l, int a, int x, int y){

	//vfac[fac].sethabx(x);
	//vfac[fac].sethaby(y);

	return;
}


//verificar artefacto
  //verifica se um habitante calcou um artefacto e se sim, executa o seu efeito
  //recebe o vector de artefactos e o vector dos habitantes
void verificar_artefacto(){

	//for para correr todos os artefactos
		//for para correr todos os habitantes
			//se existirem coordenadas iguais
			//chamar a função com o efeito do artefacto

}

//verificar cidade
  //verifica se um habitante esta dentro de uma cidade (nas mesmas coordenadas)
  //recebe o vector de habitantes e as cidades*
void verificar_cidade(){

	//for para correr todas as cidades
		//for para correr todos os habitantes
			//se existirem coordenadas iguais
			//quer dizer que o habitante esta dentro da cidade

}

void jogo::novojogotitle(){
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

cidade* jogo::CriaObjectosCidade(cidade *anterior,int ncidades)
{
cidade *aux=new cidade[ncidades+1]; //cria mais um espaço para + uma cidade
for(int i=0; i<ncidades;i++)
{	
aux[i]=anterior[i];
}
return aux;
}

int jogo::getTotalCidades(){
return ncidades;
}

void jogo::setTotalCidades(int n){
	ncidades=n;
}

//funcao que imprime uma cidade no mapa
// recebe o nº de deslocações na horizontal e vertical
void jogo::imprime_cidades(int dph, int dpv,int px,int py,int cor,int id){

	int x, y;
	//converter coordenadas para o mapa
	x = ((px+1) * 2) - (dph*2);
	y = ((py+1) * 2) - (dpv*2);

	//so imprime o habitante, se este se encontrar na secção mostrada pelo mapa
	if(x <= 76 && y <= 32 && x > 0 && y > 0){
		c.gotoxy(x,y);
		//troca a cor de fundo para a da faccao do habitante
		imprime_cor(cor);
		//cout << h.getTipo();	//imprimir o tipo de habitante
		cout << "Ci";
		c.gotoxy(x,y+1);		//mudar para a linha abaixo
		if(id < 10)		//imprimir o id do habitante
			cout << "0" << id;		//acrescenta um 0 se o id for menor que 10 (1 --> 01)
		else
		cout << id;
	}

	c.setBackgroundColor(c.PRETO);

}

cidade* jogo::getCidades(){
	return cidades;
}

void jogo::setCidades(cidade* cidad){
	cidades=cidad;
}