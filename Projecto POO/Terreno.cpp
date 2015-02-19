#include "Terreno.h"


//CONSTRUTOR
terreno::terreno(int l, int a){
	largura = l;
	altura = a;
}

//SETS
void terreno::setLargura(int l){
	largura = l;
}
void terreno::setAltura(int a){
	altura = a;
}

//GETS
int terreno::getLargura(){
	return largura;
}
int terreno::getAltura(){
	return altura;
}

//OPERADORES


//imprimir mapa (xadrez)
void terreno::imprime_mapa(int l, int a, int cph, int cpv){
	Consola c;

	int aux_largura;
	int aux_altura;

	aux_largura = l - cph;
	aux_altura = a - cpv;


	//se as dimensões ultrapassarem os limites
	if(aux_largura > 38)
		aux_largura = 38;
	if(aux_altura > 16)
		aux_altura = 16;


	for(int i=0;i<aux_largura;i+=2){
		cout << "  "; //espaçamento

		if(i+cph<10)
			cout << "0" << i+cph; //coloca um 0 atras do numero 1 --> 01
		else
			cout << i+cph;	
	}

	cout << endl << "  "; //espaçamento inicial
	for(int i=1; i<aux_largura; i+=2){
		cout << "  "; //espacamento

		if(i+cph<10)
			cout << "0" << i+cph; //coloca um 0 atras do numero 1 --> 01
		else
			cout << i+cph;
	}

	//===== IMPRIMIR LINHAS =====
	cout << endl;

	for(int i=0; i<aux_altura; i++){
		if(i+cpv<10){
			c.setBackgroundColor(c.PRETO);
			cout << "0" << i+cpv; //coloca um 0 atras do numero 1 --> 01
		}else{
			c.setBackgroundColor(c.PRETO);
			cout << i+cpv;
		}

		if(i%2==0){
			for(int j=0; j<aux_largura; j++){
				if(j%2==0){
					if((cph%2==0 && cpv%2==0) || (cph%2==1 && cpv%2==1)){
						c.setBackgroundColor(c.CINZENTO);
						cout << "  ";
					}else{
						c.setBackgroundColor(c.BRANCO);
						cout << "  ";
					}
				}
				if(j%2==1){
					if((cph%2==0 && cpv%2==0) || (cph%2==1 && cpv%2==1)){
						c.setBackgroundColor(c.BRANCO);
						cout << "  ";
					}else{
						c.setBackgroundColor(c.CINZENTO);
						cout << "  ";
					}
				}
		}
			c.setBackgroundColor(c.PRETO);
			cout << endl << "  ";
			for(int j=0; j<aux_largura; j++){
				if(j%2==0){
					if((cph%2==0 && cpv%2==0) || (cph%2==1 && cpv%2==1)){
						c.setBackgroundColor(c.CINZENTO);
						cout << "  ";
					}else{
						c.setBackgroundColor(c.BRANCO);
						cout << "  ";
					}
				}
				if(j%2==1){
					if((cph%2==0 && cpv%2==0) || (cph%2==1 && cpv%2==1)){
						c.setBackgroundColor(c.BRANCO);
						cout << "  ";
					}else{
						c.setBackgroundColor(c.CINZENTO);
						cout << "  ";
					}
				}
		}
			cout << endl;
		}
		
		if(i%2==1){
			for(int j=0; j<aux_largura; j++){
				if(j%2==0){
					if((cph%2==0 && cpv%2==0) || (cph%2==1 && cpv%2==1)){
						c.setBackgroundColor(c.BRANCO);
						cout << "  ";
					}else{
						c.setBackgroundColor(c.CINZENTO);
						cout << "  ";
					}
				}
				if(j%2==1){
					if((cph%2==0 && cpv%2==0) || (cph%2==1 && cpv%2==1)){
						c.setBackgroundColor(c.CINZENTO);
						cout << "  ";
					}else{
						c.setBackgroundColor(c.BRANCO);
						cout << "  ";
					}
				}
		}
			c.setBackgroundColor(c.PRETO);
			cout << endl << "  ";
			for(int j=0; j<aux_largura; j++){
				if(j%2==0){
					if((cph%2==0 && cpv%2==0) || (cph%2==1 && cpv%2==1)){
						c.setBackgroundColor(c.BRANCO);
						cout << "  ";
					}else{
						c.setBackgroundColor(c.CINZENTO);
						cout << "  ";
					}
				}
				if(j%2==1){
					if((cph%2==0 && cpv%2==0) || (cph%2==1 && cpv%2==1)){
						c.setBackgroundColor(c.CINZENTO);
						cout << "  ";
					}else{
						c.setBackgroundColor(c.BRANCO);
						cout << "  ";
					}
				}
		}
			cout << endl;
		}
	}

	//imprimir a barra =======
	cout << endl;
	c.setBackgroundColor(c.PRETO);
	for(int i=0; i<80;i++)
		cout << "=";

	//imprimir os ^ v < > caso seja preciso
	// >
	if((l > 38) && (l - cph != 38)){
		c.gotoxy(77,34);
		cout << ">";
	}else{
		c.gotoxy(77,34);
		cout << " ";
	}
	// <
	if(cph > 0){
		c.gotoxy(2,34);
		cout << "<";
	}else{
		c.gotoxy(2,34);
		cout << " ";
	}
	// ^
	if(cpv > 0){
		c.gotoxy(79,2);
		cout << "^";
	}else{
		c.gotoxy(79,2);
		cout << " ";
	}
	// v
	if((a > 16) && (a - cpv != 16)){
		c.gotoxy(79,32);
		cout << "v";
	}else{
		c.gotoxy(79,32);
		cout << " ";
	}

}