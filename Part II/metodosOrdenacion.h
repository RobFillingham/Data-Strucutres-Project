#include <stdio.h>
#include <sys/time.h>


#include<stdlib.h>
#include<windows.h>
#include<ctime>


#include<iostream>



using namespace std;

class metodosOrdenacion{
	
	public:
		
		
		void quicksort( int*,int, int);
		void insercion(int*, int);
		void seleccion(int*, int);
		
		int getMax(int*, int);
		void CountingSort(int*, int, int);
		void RadixSort(int*, int);
		
		
		void Shell(int*, int);
		
		void heapSort(int*, int);
		void heapify(int*, int, int);
		
		void insercionBinaria(int*, int);
		void burbuja(int *vec, int n);
};


void metodosOrdenacion::quicksort(int *A,int primero,int ultimo){
    int central,i,j;
    double pivote;
    central=(primero+ultimo)/2;
    pivote=A[central];
    i=primero;
    j=ultimo;
    do{
            while(A[i]<pivote) i++;
            while(A[j]>pivote) j--;
            if(i<=j){
                double temp;
                temp=A[i];
                A[i]=A[j]; /*intercambia A[i] con A[j] */
                A[j]=temp;
                i++;
                j--;
            }
        }

    while(i<=j);
    if(primero<j)
        quicksort(A,primero,j); /*mismo proceso con sublista izquierda*/
    if(i<ultimo)
        quicksort(A,i,ultimo); /*mismo proceso con sublista derecha*/
}

void metodosOrdenacion::burbuja(int *vec, int n){
	int temp;
	for(int i=0;i<n;i++)
		for(int j=0;j<n-1;j++){
			if(vec[j]>vec[j+1]){
				temp=vec[j];
				vec[j]=vec[j+1];
				vec[j+1]=temp;
		
			}
			//mostrar(vec,n);			//Mostrar Comparaciones
		}
}

void metodosOrdenacion::insercion(int *arreglo2, int N){
	int j, clave;
	for (int i = 1; i < N; i++) {
		clave = arreglo2[i];
		j = i - 1;
		while (j >= 0 && arreglo2[j] > clave) {
			arreglo2[j + 1] = arreglo2[j];
			j = j - 1;
		}
		arreglo2[j + 1] = clave;
		
	}
}

void metodosOrdenacion::seleccion(int *numeros, int N){
	
	int aux, min;
	
	for(int i=0;i<N;i++){
		min = i;
									 //For que recorre las posiciones del vector, 
		for(int j=i+1;j<N;j++){ 		//y guarda la posicion si encuentra un numero menor 
			if(numeros[j] < numeros[min]){
				min = j; 			//Guarda la posicion del vector, que es menor hasta el momento
			}
		}
		aux = numeros[i];	//Guarda el numero de la posicion del vector en i en un auxiliar
		
		numeros[i] = numeros[min]; //Aqui reemplaza el numero que fue menor, al actual de la posicion, si no hubo, entonces solo reemplazaria el mismo numero.
		
		numeros[min] = aux;		//Aqui guarda el numero que se guardo en auxiliar para ser reemplazado, en el la posicion del numero que fue menor.
	
	}
}


//RADIX-----------------------------------------------------------------------------------------------------

int metodosOrdenacion::getMax(int *arr, int size) 
{ 
    int max = arr[0]; 
    for (int i = 1; i < size; i++) 
        if (arr[i] > max) 
            max = arr[i]; 
    return max; 
} 
  
void metodosOrdenacion::CountingSort(int *arr, int size, int div) 
{ 
    int output[size]; 
    int count[10] = {0}; 
  
    for (int i = 0; i < size; i++) 
        count[ (arr[i]/div)%10 ]++; 
  
    for (int i = 1; i < 10; i++) 
        count[i] += count[i - 1]; 
  
    for (int i = size - 1; i >= 0; i--) 
    { 
        output[count[ (arr[i]/div)%10 ] - 1] = arr[i]; 
        count[ (arr[i]/div)%10 ]--; 
    } 
  
    for (int i = 0; i < size; i++) 
        arr[i] = output[i]; 
} 
  
 
void metodosOrdenacion::RadixSort(int *arr, int size) 
{ 
    int m = getMax(arr, size); 
    for (int div = 1; m/div > 0; div *= 10) 
        CountingSort(arr, size, div); 
}

//-------------------------------------------------------------------------------------

void metodosOrdenacion::Shell (int *v, int n)
{
   int i , j , k , salto, aux ;  bool fin ;

   salto = n ;
   while ( salto > 0 )
   {
      salto = salto / 2 ;
      do
      {
      	
         fin = true ;
         k  = n - salto ;
         for ( i = 0 ; i < k ; i++ )
         {
		 	
            j = i + salto ;
            if ( v [ i ] < v [ j ] )
            {
                aux = v [ i ] ;
				v [ i ] = v [ j ] ;
				v [ j ] = aux ;
				fin = false ;
             }
             
            
          }

       }
       while ( ! fin ) ;
    }
}

//METODO HEAP SORT --------------------------------------------------
void metodosOrdenacion::heapify(int *arr, int N, int i) {  // n es el tamaño del heap
    int largest = i;                     // Inicializar largest como raíz

    int l = 2 * i + 1;  // Izquierda = 2*i 

    int r = 2 * i + 2;  // Derecha = 2*i + 1

    if (l < N && arr[l] > arr[largest])  // Si el hijo izquierdo es más grande que la raíz
        largest = l;

    if (r < N && arr[r] > arr[largest])  // Si el hijo derecho es más grande que la raiz
        largest = r;

    if (largest != i) {  // Si largest(Nuestra variable entera declarada) no es raiz
        swap(arr[i], arr[largest]);

        // Amontonar recursivamente a los afectados
        // sub-arbol
        heapify(arr, N, largest);
    }
}

void metodosOrdenacion::heapSort(int *arr, int N) {         // Función principal para hacer heap sort
    for (int i = N / 2 - 1; i >= 0; i--)  // Construir heap (reorganizar arreglo)
        heapify(arr, N, i);

    // Uno por uno extraer un elemento
    // Desde el heap
    for (int i = N - 1; i > 0; i--) {
        swap(arr[0], arr[i]);  // Mover la raíz actual al final

        heapify(arr, i, 0);  // llamar a max heapify en el heap reducido
    }
}

//------------------------------------------------------------------------------------------

void metodosOrdenacion::insercionBinaria(int A[],int n)
{
	int i,j,aux,izq,der,m;
	for(i=1;i<n;i++)
    	{
           		aux = A[i];
           		izq=0;
           		der=i-1;
           		while(izq<=der)
           		{
			m=((izq+der)/2);
			if (aux<A[m])
				der=m-1;
			else
              			izq=m+1;              
          		 }
           		j=i-1;
          		while(j>=izq)
          		{
	   		A[j+1]=A[j];
	    		j=j-1;
          		}
          		A[izq]=aux;
	}
}
