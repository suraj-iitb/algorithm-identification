#include "stdio.h"

void countingSort(int input[], int output[], int input_size, int count_size){
  
  int* counter = new int [count_size];
  for(int i=0;i<count_size;i++){
    counter[i]=0;
  }
  
  for(int a=0;a<input_size;a++){
    counter[input[a]]++;
  }

  for(int i=1;i<count_size;i++){
    counter[i] = counter[i] + counter[i-1];
  }

  for(int a=input_size-1;a>=0;a--){
    output[counter[input[a]]-1] = input[a];
    counter[input[a]]--; 
  }

  delete [] counter;  

}

void outputMatrix(int matrix[], int N){
  for(int i=0;i<N;i++){
    if(i>0){
      printf(" ");
    }
    printf("%d", matrix[i]);
  }
  printf("\n");
}


int main(void){

  int N;
  scanf("%d", &N);

  int* input  = new int [N];
  int* output = new int [N]; 
  for(int i=0;i<N;i++){
    scanf("%d", &(input[i]));
  }

  int MAXSIZE = 20000;

  countingSort(input, output, N, MAXSIZE);
  outputMatrix(output, N);

  delete [] input;
  delete [] output;

  return 0;
}
