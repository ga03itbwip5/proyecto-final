#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>//de la funcion rand
#include <list>

#define arrib 72
#define izq 75
#define der 77
#define abaj 80


using namespace std;





//quitar el cursor
void borrarcursor(){
	
	
	
	
	
	HANDLE o;
	o=GetStdHandle(STD_OUTPUT_HANDLE);
	
	CONSOLE_CURSOR_INFO a;
	a.dwSize = 100;
	a.bVisible = FALSE;
	
	SetConsoleCursorInfo(o,&a);
}

void coord_xy(int x,int y){
	
	
	
	
	HANDLE o;
	o=GetStdHandle(STD_OUTPUT_HANDLE);
	
	COORD coordenadas;/// declara coordenadas 
	coordenadas.X=x;/// coordenada x
	coordenadas.Y=y;
	
	SetConsoleCursorPosition(o,coordenadas); 
}





void marco_del_juego(){//dibujar el marco del juego space 
	
	
	for(int i=0;i<75;i++){
		coord_xy(i,1);cout<<"-";
		coord_xy(i,25);cout<<"-";}
	for(int i=1;i<25;i++){
		coord_xy(0,i);cout<<"|";
		coord_xy(74,i);cout<<"|";}
	coord_xy(0,1);cout<<"O";
	coord_xy(0,25);cout<<"O";
	coord_xy(74,1);cout<<"O";
	coord_xy(74,25);cout<<"O";
}
	
class avion{///////////////////////////////////////////////////la clase    avion
	
private:
	int x,y;
	int corazon;
	int vida;//nuevo atributo
public:
	avion(int x,int y,int corazon,int vida ){
		this->x=x;
		this->y=y;
		this->corazon=corazon;
		this->vida=vida;
	}
	
	int X(){return x;}//regresar el valor int  de la coordenada x de la nave
	int Y(){return y;}//regresar el valor int  de la coordenada y de la nave
	int V(){return vida;}/// esto es para el IF que hara el GAME OVER
	void cor(){corazon--;}
	
	void printavion(){
		
		coord_xy(x+2,y);cout<<"j";
		coord_xy(x+1,y+1);cout<<"jjj";
		coord_xy(x,y+2);cout<<"jjjjj";
	}
	void borrarnave(){
		
		coord_xy(x,y);cout<<"     ";
		coord_xy(x,y+1);cout<<"     ";
		coord_xy(x,y+2);cout<<"     ";
	}
	void moverse(){
		
		if(kbhit()){
			char tecla=getch();
			
			borrarnave();
			if(tecla== izq and x-1>0 )x--;
			if(tecla== der and x+5<74)x++;
			if(tecla== arrib and y-2>0)y--;
			if(tecla== abaj and y+3<25)y++;
			
			
			if(tecla== 'g')corazon--;				
			printavion();	
			printcorazon();					
		}
	}
	void printcorazon(){
		
		coord_xy(2,0),cout<<"SPACE INVADER";
		coord_xy(45,0),cout<<"vidas "<<vida;//colocar print de vidas 
	
	
		coord_xy(64,0);cout<<"salud";
		coord_xy(70,0);cout<<"      ";
		for(int i=0;i<corazon;i++){
			coord_xy(70+i,0);cout<<char(3);
		}
	}
	void muere(){///////////////nueva funcion morir
		if(corazon==0){///////////////
			
			borrarnave();
			coord_xy(x+1,y);cout<<"**";
			coord_xy(x,y+1);cout<<"****";
			coord_xy(x+1,y+2);cout<<"**";
			
			Sleep(500);
			
			borrarnave();
			coord_xy(x,y);cout<<"*--*";
			coord_xy(x,y+1);cout<<"----";
			coord_xy(x,y+2);cout<<"*--*";
			Sleep(200);
			borrarnave();
			
			vida--;///////////////
			corazon=3;///////////////
			printcorazon();///////////////
			printavion();///////////////
		}
	}
	
};//////////////////////////////////////////////////////////////////////////////


class asteroide{//////////////////////////////////////////////la clase asteroide
	
private:
	int x,y;//atributos coordenadas
public:
	asteroide(int x,int y){//constructor de asteroide
		this->x=x;//x=_x;
		this->y=y;//y=_y;
	}
	void print_asteroide(){
		coord_xy(x,y);cout<<"G";
	}
	
	void mover(){
		coord_xy(x,y);cout<<" ";
		y++;
		if(y>24){
			x=rand()%73+1; 
			y=2;
		}
		print_asteroide();//////////////////////////////////////////////////////
	}
	void choque_asteroide_avion(avion &n){       //funcion void --detecte la colision de las coordenadas de asteoride con el de la nave----(class avion &n)
		if(  n.X() <= x    and   x <= n.X()+4   and   n.Y() <= y   and   y <= n.Y()+2  ){      //la x es la del asteroide como la y  -- comparar  con las coordendas de la nave
			n.cor();
			n.borrarnave();
			
			n.printavion();
			n.printcorazon();
			x=rand()%73+1; 
			y=2;
		}
	}
};


class bala{/////////////////////////////////////////////////////nueva clase bala
	
private:
	int x,y;
public:
	bala(int x,int y){
		this->x=x;
		this->y=y;
	}
	void print_bala(){
		coord_xy(x,y);cout<<"o";
	}
		
	void mover(){
		coord_xy(x,y);cout<<" ";
		if(y>2){
		y--;
		print_bala();}
	}
};



int main(int argc, char *argv[]) {
	
	borrarcursor();
	marco_del_juego();
	avion j(20,20,3,3);
	j.printavion();
	j.printcorazon();
	
	asteroide jj(10,2);asteroide jj1(2,10);asteroide jj2(50,14);asteroide jj3(30,7);//4 asteroides
	asteroide jj4(26,31);asteroide jj5(36,5);asteroide jj6(30,16);
	asteroide jj7(13,20);asteroide jj8(46,36);asteroide jj9(16,49);
	asteroide jj10(15,50);asteroide jj11(28,40);asteroide jj12(37,11);
	
	bool gg = false;
	
	while(!gg){
		
	
		
		//jj.mover();jj.choque_asteroide_avion(j);//4 asteroides  verificar si tiene choque
		//jj1.mover();jj1.choque_asteroide_avion(j);
		jj2.mover();jj2.choque_asteroide_avion(j);
		jj3.mover();jj3.choque_asteroide_avion(j);
		jj4.mover();jj4.choque_asteroide_avion(j);
		jj5.mover();jj5.choque_asteroide_avion(j);
		jj6.mover();jj6.choque_asteroide_avion(j);
		jj7.mover();jj7.choque_asteroide_avion(j);
		jj8.mover();jj8.choque_asteroide_avion(j);
		jj9.mover();jj9.choque_asteroide_avion(j);
		jj10.mover();jj10.choque_asteroide_avion(j);
		jj11.mover();jj11.choque_asteroide_avion(j);
		jj12.mover();jj12.choque_asteroide_avion(j);
		
		
		j.muere();
		///este IF...
		/*if(j.V == 0 ){
			gg=true;
		}*/
		j.moverse();
		Sleep(100);
	}
	
	
	
	return 0;
}

