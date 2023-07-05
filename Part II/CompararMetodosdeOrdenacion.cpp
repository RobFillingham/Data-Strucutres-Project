
#include"metodosOrdenacion.h"
#define TAM 10

struct resultados{
	string metodo;
	double tiempo;
};


void portada();
int* copiaVector(int*);
void pantallaResultados(resultados[]);
ostream& operator<<(ostream&, resultados);
void burbuja(resultados[], int);

void gotoxy(int x,int y){  //Debemos agregar esta funcion
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 }


HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);

int main () {
	
	
	//LLENADO VECTOR
	
	int vector[TAM];
	int *vectorCopia;
	metodosOrdenacion A;
	resultados tabla[8]={{"Quicksort", 0},{"Insercion", 0},{"Seleccion",0},{"Radix", 0},{"Shell", 0}, {"HeapSort", 0},{"InsercionB", 0}, {"Burbuja", 0}};
	
    double sum = 0;
    double add = 1;


	

	portada();

	SetConsoleTextAttribute(color, 2);

    struct timeval begin, end;
    gettimeofday(&begin, 0);
    
    for (int i=0; i<TAM; i++) {
        vector[i]=rand()%100000+1;
    }
    

    gettimeofday(&end, 0);
    long seconds = end.tv_sec - begin.tv_sec;
    long microseconds = end.tv_usec - begin.tv_usec;
    double elapsed = seconds + microseconds*1e-6;
    
    
    

    cout.precision(10);
    cout<<endl<<"Tiempo que se tardo en llenar el vector: "<<elapsed<<endl;
    
    
    //QUICKSORT
    SetConsoleTextAttribute(color, 4);
    cout<<endl<<"Ordenando con Quicksort...";
    
    gettimeofday(&begin, 0);
	
	vectorCopia=copiaVector(vector);
	A.quicksort(vectorCopia, 0, TAM-1);

	
	
    gettimeofday(&end, 0);
     seconds = end.tv_sec - begin.tv_sec;
     microseconds = end.tv_usec - begin.tv_usec;
     elapsed = seconds + microseconds*1e-6;
    
    tabla[0].tiempo=elapsed;
    
	SetConsoleTextAttribute(color, 2);
	gotoxy(0, 3);
    cout.precision(10);
    cout<<"Quicksort: "<<elapsed<<"         "<<endl;
	
	
	//METODO DE INSERCION
	
	vectorCopia=copiaVector(vector);
	
	SetConsoleTextAttribute(color, 4);
	cout<<endl<<"Ordenando con el Metodo de Insercion...";
	
	
	gettimeofday(&begin, 0);
	
	A.insercion(vectorCopia, TAM);
	
	gettimeofday(&end, 0);
    seconds = end.tv_sec - begin.tv_sec;
    microseconds = end.tv_usec - begin.tv_usec;
    elapsed = seconds + microseconds*1e-6;
	
	tabla[1].tiempo=elapsed;
	
	SetConsoleTextAttribute(color, 2);
	gotoxy(0,5);
	cout.precision(10);
    cout<<"Metodo de Insercion: "<<elapsed<<"                      "<<endl;
	
	//METODO DE SELECCION
	
	vectorCopia=copiaVector(vector);
	
	SetConsoleTextAttribute(color, 4);
	cout<<endl<<"Ordenando con el metodo de seleccion...";
	
	gettimeofday(&begin, 0);
	
	A.seleccion(vectorCopia, TAM);
	
	gettimeofday(&end, 0);
    seconds = end.tv_sec - begin.tv_sec;
    microseconds = end.tv_usec - begin.tv_usec;
    elapsed = seconds + microseconds*1e-6;
	
	tabla[2].tiempo=elapsed;	
	SetConsoleTextAttribute(color, 2);
	gotoxy(0, 7);
	cout.precision(10);
    cout<<"Metodo de Seleccion: "<<elapsed<<"                   "<<endl;
    
    
    //METODO RADIX
    
    vectorCopia=copiaVector(vector);
	
    
    gettimeofday(&begin, 0);
    
    A.RadixSort(vectorCopia, TAM); 
    
	gettimeofday(&end, 0);
    seconds = end.tv_sec - begin.tv_sec;
    microseconds = end.tv_usec - begin.tv_usec;
    elapsed = seconds + microseconds*1e-6;
	
	tabla[3].tiempo=elapsed;
	
	SetConsoleTextAttribute(color, 2);
	cout.precision(10);
    cout<<endl<<"Metodo Radix: "<<elapsed<<endl;
	
	
	
	//METODO SHELL
	
	vectorCopia=copiaVector(vector);
	
	SetConsoleTextAttribute(color, 4);
	cout<<endl<<"Ordenando con el metodo Shell...";
    
    gettimeofday(&begin, 0);
    
    A.Shell(vectorCopia, TAM); 
    
	gettimeofday(&end, 0);
    seconds = end.tv_sec - begin.tv_sec;
    microseconds = end.tv_usec - begin.tv_usec;
    elapsed = seconds + microseconds*1e-6;
	
	tabla[4].tiempo=elapsed;
	
	SetConsoleTextAttribute(color, 2);
	gotoxy(0, 11);
	cout.precision(10);
    cout<<"Metodo Shell: "<<elapsed<<"                 "<<endl;
	
	//HEAPSORT
	
	vectorCopia=copiaVector(vector);
	
	SetConsoleTextAttribute(color, 4);
	cout<<endl<<"Ordenando con el metodo HeapSort...";
    
    gettimeofday(&begin, 0);
    
    A.heapSort(vectorCopia, TAM); 
    
	gettimeofday(&end, 0);
    seconds = end.tv_sec - begin.tv_sec;
    microseconds = end.tv_usec - begin.tv_usec;
    elapsed = seconds + microseconds*1e-6;
	
	tabla[5].tiempo=elapsed;
	
	SetConsoleTextAttribute(color, 2);
	gotoxy(0, 13);
	cout.precision(10);
    cout<<"Metodo HeapSort: "<<elapsed<<"                  "<<endl;	
	
//cout<<endl<<vectorCopia[0]<<endl<<endl<<vectorCopia[1]<<endl<<endl<<vectorCopia[2]<<endl<<endl<<vectorCopia[100]<<endl<<endl<<vectorCopia[101]<<endl<<endl<<vectorCopia[300]<<endl<<endl<<vectorCopia[301]<<endl;	

	//METODO DE INSERCION BINARIA

	vectorCopia=copiaVector(vector);
	
	SetConsoleTextAttribute(color, 4);
    cout<<endl<<"Ordenando con Insercion Binaria...";
    
    gettimeofday(&begin, 0);
    
    A.insercionBinaria(vectorCopia, TAM); 
    
	gettimeofday(&end, 0);
    seconds = end.tv_sec - begin.tv_sec;
    microseconds = end.tv_usec - begin.tv_usec;
    elapsed = seconds + microseconds*1e-6;
	
	tabla[6].tiempo=elapsed;
	
	SetConsoleTextAttribute(color, 2);
	gotoxy(0, 15);
	cout.precision(10);
    cout<<"Insercion Binaria: "<<elapsed<<"                     "<<endl;

	

	
	//METODO DE LA BURBUJA
	
	vectorCopia=copiaVector(vector);
	
	SetConsoleTextAttribute(color, 4);
	cout<<endl<<"Ordenando con el metodo de la Burbuja...";
	
	gettimeofday(&begin, 0);
	
	A.burbuja(vectorCopia, TAM);
	
 	gettimeofday(&end, 0);
     seconds = end.tv_sec - begin.tv_sec;
     microseconds = end.tv_usec - begin.tv_usec;
     elapsed = seconds + microseconds*1e-6;
    
    tabla[7].tiempo=elapsed;
    
	SetConsoleTextAttribute(color, 2);
	gotoxy(0, 17);
    cout.precision(10);
    cout<<"Time measured burbuja: "<<elapsed<<"                 "<<endl;
    
    
    
    burbuja(tabla, 8);
    
    
    //system("pause");
    system("cls");
    
    
    pantallaResultados(tabla);
    
    gotoxy(10, 25);
    SetConsoleTextAttribute(color, 5);
    
    return 0;
}

int* copiaVector(int *vectorOriginal){
	int *vectorCopia=new int[TAM];
	for(int i=0; i<TAM; i++){
		vectorCopia[i]=vectorOriginal[i];
	}
	return vectorCopia;
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
	
	system("pause");
	system("cls");
}

void pantallaResultados(resultados tabla[]){
	
	SetConsoleTextAttribute(color, 8);
	
	gotoxy(27,5);
	cout<<"METODO";
	
	gotoxy(40, 5);
	cout<<"TIEMPO DE EJECUCION";
	
	for(int i=0; i<39; i++){ // barras horizontales
		gotoxy(i+24, 6);
		cout<<char(205);
		
		gotoxy(i+24, 4);
		cout<<char(205);
		
		gotoxy(i+24, 22);
		cout<<char(205);	
		
	}
	cout<<char(187);
	
	gotoxy(63,4);
	cout<<char(187);
	//barras verticales
	
	gotoxy(23, 4);
	cout<<char(201);
	
	for(int i=0; i<17; i++){
		gotoxy(36, 5+i);
		cout<<char(186);
		
		gotoxy(63, 5+i);
		cout<<char(186);
		
		gotoxy(23, i+5);
		cout<<char(186);
	}
	gotoxy(23, 22);
	cout<<char(200);
	
	gotoxy(36, 4);
	cout<<char(203);
	
	gotoxy(63, 22);
	cout<<char(188);
	
	gotoxy(36, 22);
	cout<<char(188);
	
	
	int colores[8]={2, 2, 2, 6, 6, 4, 4,4};
	
	for(int i=0, j=0; i<8; i++, j+=2){ //metodos Y RESULTADOS
		SetConsoleTextAttribute(color, 7);
		gotoxy(25, 7+j);
		cout<<tabla[i];
		
		SetConsoleTextAttribute(color, colores[i]);
		gotoxy(44, 7+j);
		cout<<tabla[i].tiempo;
	}
	

	
	

}

void burbuja(resultados *vec, int n){
	resultados temp;
	for(int i=0;i<n;i++)
		for(int j=0;j<n-1;j++){
			if(vec[j].tiempo>vec[j+1].tiempo){
				temp=vec[j];
				vec[j]=vec[j+1];
				vec[j+1]=temp;
		
			}
			//mostrar(vec,n);			//Mostrar Comparaciones
		}
}

ostream&  operator<< (ostream &out, resultados metodoAImprimir){
	out<<metodoAImprimir.metodo;
	return out;
}

