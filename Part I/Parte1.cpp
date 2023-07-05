#include "ArbolDeExpresion.h"

using namespace std;

HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);



void portada();
bool validarOperador(char);

int main(){
    portada();
    system("pause");
    system("clear");
    
    SetConsoleTextAttribute(color, 4);
    
    ArbolDeExpresion ArbolExpresionUsuario;
    char expresionInfijo[50];
    int sizeOfExpresion;
    
    cout<<endl<<"Ingresa la expresion en infijo con todos los parentesis necesarios (Hay un par por cada operador):  ";
    cin.getline(expresionInfijo, 50);
    fflush(stdin);
    
    sizeOfExpresion=strlen(expresionInfijo);
    
    
    char cifraOperandos[15];
    
    for(int i=0; i<sizeOfExpresion; i++){
    	
		if(expresionInfijo[i]=='('){
    		
    		ArbolExpresionUsuario.insertarParentesis();
    		
		}
		
		else if(expresionInfijo[i]>=48&&expresionInfijo[i]<=57){
			
			int j=i, k=0;
			while(expresionInfijo[j]>=48&&expresionInfijo[j]<=57){
				cifraOperandos[k]=expresionInfijo[j];
				k++;
				j++;
			}
			i=j-1;
			cifraOperandos[k]='\0';
			ArbolExpresionUsuario.insertarOperandos(cifraOperandos);
			
		}
		
		else if(validarOperador(expresionInfijo[i])){
			ArbolExpresionUsuario.asignarOperadorANodo(expresionInfijo[i]);
		}
		

	}
	
	cout<<endl<<endl<<"En Orden: ";
	ArbolExpresionUsuario.recorridoEnOrden(ArbolExpresionUsuario.getRaiz());
	cout<<endl<<"PreOrden: ";
	ArbolExpresionUsuario.preOrden(ArbolExpresionUsuario.getRaiz());
	cout<<endl<<"PostOrden: ";
	ArbolExpresionUsuario.postOrden(ArbolExpresionUsuario.getRaiz());
	
	int baseDelArbol = pow(ArbolExpresionUsuario.alturaArbol(ArbolExpresionUsuario.getRaiz()),2)*3;
	ArbolDeExpresion::Nodo *aux=ArbolExpresionUsuario.getRaiz();
	SetConsoleTextAttribute(color, 2);
	ArbolExpresionUsuario.imprimirArbol3(aux, baseDelArbol/2+30, 40, baseDelArbol/4+4, ArbolExpresionUsuario.alturaArbol(aux));
    gotoxy(0, 100);
}

void portada(){

	
	SetConsoleTextAttribute(color, 6);
	cout.width(30);
    cout<<endl<<"UAA"<<endl;
    cout.width(49);
    cout<<"Ingenieria en Sistemas Computacionales";
    
    SetConsoleTextAttribute(color, 4);
	cout.width(47);
	cout<<endl<<endl<<"Proyecto Final Estructura de Datos"<<endl;
	cout.width(36);
	cout<<"Tercer Semestre";
	
	
	SetConsoleTextAttribute(color, 3);
	cout.width(32);
	cout<<endl<<endl<<"Parte I"<<endl;
	cout.width(48);
	cout<<"Construccion de Arboles de Expresion"<<endl<<endl<<endl;
	
	cout.width(15);
	cout<<"Integrantes: "<<endl;
	
	SetConsoleTextAttribute(color, 8);
	cout.width(30);
	cout<<endl<<"Carlos Alberto Contreras Martinez";
	cout.width(34);
	cout<<endl<<"Julio Cesar Gutierrez Martin";
	cout.width(37);
	cout<<endl<<"Robert Everett Fillingham Gaeta";

	SetConsoleTextAttribute(color, 3);	
	cout.width(12);
	cout<<endl<<endl<<"Profesor: "<<endl;
	
	SetConsoleTextAttribute(color, 8);
	cout.width(48);	
	cout<<endl<<"M. en Informatica Georgina Salazar Partida";
	
	SetConsoleTextAttribute(color,7);	
	cout<<endl<<endl<<endl<<"Aguascalientes, 3 de Diciembre 2022"<<endl<<endl<<endl;
	

}

bool validarOperador(char operador){
	if(operador==43||operador==45||operador==47||operador==37||operador==94||operador==42)
		return true;
	
	return false;
}


