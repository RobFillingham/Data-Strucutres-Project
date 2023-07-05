#include<iostream>
#include<stack>
#include<cstring>
#include<windows.h>
#include <cmath>
using namespace std;

 void gotoxy(int x,int y){  //Debemos agregar esta funcion
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 }


class ArbolDeExpresion{
	public:
		class Nodo{ //constructor para los nodos de los operadores
			public:
				Nodo *izquierdo;
				Nodo *derecho;
				char dato[15];
		
				Nodo(){ //constructor con argumentos, para los nodos de los operandos
					izquierdo=NULL;
					derecho=NULL;
					strcpy(dato, "\0");
				}
				Nodo(char dato[]){
					izquierdo=NULL;
					derecho=NULL;
					strcpy(this->dato, dato);	
				}
		};
	private:
		Nodo *raiz;
		Nodo *nodoActual;
		stack<Nodo*>pilaDeNodos;
	public:
		
		inline ArbolDeExpresion(){
			nodoActual=NULL;
		}
		inline Nodo* getRaiz(){
			return raiz;
		}
		
		void insertarParentesis();

		void insertarOperandos(char cifraOperandos[]);

		void asignarOperadorANodo(char operador);

		void recorridoEnOrden(Nodo *nodo);
		
		void imprimirArbol(Nodo*, const int, const int);
		
		int alturaArbol(Nodo*);
		
		void imprimirArbol2(Nodo*,  int,  int, int, int);

		void imprimirArbol3(Nodo*,  int,  int, int, int);
		
		void preOrden(Nodo *);
		
		void postOrden(Nodo*);	

};


void ArbolDeExpresion::insertarParentesis(){
	if(nodoActual==NULL){
		nodoActual=raiz=new Nodo;
		pilaDeNodos.push(nodoActual);
	}
	else{
		Nodo *nuevoNodo=new Nodo;
		if(nodoActual->izquierdo==NULL)
			nodoActual->izquierdo=nuevoNodo;
		else
			nodoActual->derecho=nuevoNodo;
		
		pilaDeNodos.push(nuevoNodo);
		nodoActual=nuevoNodo;
	}
}

void ArbolDeExpresion::insertarOperandos(char cifraOperandos[]){
	Nodo *nuevoNodo=new Nodo(cifraOperandos);
	if(nodoActual->izquierdo==NULL)
		nodoActual->izquierdo=nuevoNodo;
	else
		nodoActual->derecho=nuevoNodo;
	
}

void ArbolDeExpresion::asignarOperadorANodo(char operador){
	Nodo *nodoASacar=pilaDeNodos.top();
	pilaDeNodos.pop();
	nodoASacar->dato[0]=operador;
	nodoASacar->dato[1]='\0';
	//LINEA MODIFICADA:
	nodoActual=nodoASacar;
}

void ArbolDeExpresion::recorridoEnOrden(Nodo *nodo){
	if(nodo!=NULL){
		recorridoEnOrden(nodo->izquierdo);
		cout<<nodo->dato;
		recorridoEnOrden(nodo->derecho);
	}
}

int ArbolDeExpresion::alturaArbol(Nodo *nodo){
	int der=(nodo->derecho==NULL ? 0 : 1+alturaArbol(nodo->derecho));
	int izq=(nodo->izquierdo==NULL ? 0 : 1+alturaArbol(nodo->izquierdo));
	
	return (izq>der) ? izq : der;
}

void ArbolDeExpresion::imprimirArbol(Nodo *nodo, const int Xinicial, const int Yinicial){
	if(nodo!=NULL){
		
		gotoxy(Xinicial, Yinicial);
		cout<<nodo->dato;
		imprimirArbol(nodo->izquierdo, Xinicial-3, Yinicial+3);
		imprimirArbol(nodo->derecho, Xinicial+3, Yinicial+3);
	}
}

void ArbolDeExpresion::imprimirArbol2(Nodo *nodo,  int Xinicial, int Yinicial, int n, int baseGuiones){
	if(nodo!=NULL){
		
		gotoxy(Xinicial, Yinicial);
		cout<<nodo->dato;
/*added*/	gotoxy(Xinicial-1, Yinicial+1);
		cout<<"/";
		gotoxy(Xinicial+1, Yinicial+1);
		cout<<"\\";
		imprimirArbol2(nodo->izquierdo, Xinicial-n, Yinicial+3, n/2, baseGuiones/2);
		imprimirArbol2(nodo->derecho, Xinicial+n, Yinicial+3, n/2, baseGuiones/2);	

	}
}
void ArbolDeExpresion::imprimirArbol3(Nodo *nodo,  int Xinicial, int Yinicial, int n, int nivel){
	if(nodo!=NULL){
		
		gotoxy(Xinicial, Yinicial);
		cout<<nodo->dato;
		
			for(int i=1; i<=nivel*nivel; i++){
				if(nodo->izquierdo!=NULL){
					gotoxy(Xinicial-i, Yinicial+i);
					cout<<"/";
				}
				if(nodo->derecho!=NULL){
					gotoxy(Xinicial+i, Yinicial+i);
					cout<<"\\";
				}
				
			}
		if(nodo->derecho!=NULL&&nodo->izquierdo!=NULL)	
			nivel= (alturaArbol(nodo->izquierdo)>alturaArbol(nodo->derecho)) ? alturaArbol(nodo->izquierdo) : alturaArbol(nodo->derecho); 
				
		imprimirArbol3(nodo->izquierdo, Xinicial-n, Yinicial+n, n/2, nivel);
		imprimirArbol3(nodo->derecho, Xinicial+n, Yinicial+n, n/2, nivel);	

	}
}

void ArbolDeExpresion::preOrden(Nodo *nodo){
    if(nodo!=NULL){
        cout<<nodo->dato<<" ";
        preOrden(nodo->izquierdo);
        preOrden(nodo->derecho);
    }
}

void ArbolDeExpresion::postOrden(Nodo *nodo){
    if(nodo!=NULL){
        postOrden(nodo->izquierdo);
        postOrden(nodo->derecho);
        cout<<nodo->dato<<" ";
    }
}

