#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#define SEED 5
int *array;

void createFile(char c[],int n);
void loadFile(char c[]);

int main(int argc, char const *argv[]) {
  int n=500;
  char c[]="Array1.txt";
  createFile(c,n);
  loadFile(c);
  clock_t ti, tf;
  ti = clock();//Comienza a medir el tiempo
  //BubbleSort
  for(int i=0;i<n;i++)
    for(int j=0;j<n-1-i;j++)
      if(array[j]>array[j+1]){
        //Intercambio binario
				array[j]^=array[j+1];
				array[j+1]^=array[j];
				array[j]^=array[j+1];
      }
  tf = clock();//Termina de medir el tiempo
  //Imprime el arreglo ordenado
  for (int i = 0; i < n; ++i){
 			printf("array[%d]= %d\n",i,array[i]);
 	}
  double segundos = (double)(tf - ti) / CLOCKS_PER_SEC;
	printf("Tiempo de ejecucion: %lf Segundos\n",segundos);

  free(array);
  return 0;
}

void createFile(char c[],int n){
	//Crea un puntero tipo file
	FILE *file;
	file=fopen(c,"w");
	if( file==NULL )
		printf("Error to create File\n");
	else
	{
		//Escribe una linea en el archivo
		fprintf(file,"%d\n",n);
		//Define la semilla para generar numeros aleatorios
		srand(SEED);
		//Escribe los n numeros en el archivo
		for(int i=0;i<n;i++){
			fprintf(file,"%d\n",rand());
		}
	}
	fclose(file);
}
void loadFile(char c[]){
	//Creamos un puntero de tipo FILE
	FILE *fp;
	//Abrimos el archivo a leer
 	if((fp = fopen (c,"r" ))==NULL){
 		printf("No se pudo leer el archivo\n");
 	}else{
 		int n=0;
 		fscanf(fp,"%d",&n);
 		array=(int *)malloc(n*sizeof(int));
 		//Cargamos los elementos del arreglo
 		for (int i = 0; i < n; ++i)
 			fscanf(fp,"%d",&array[i]);
 	}
}