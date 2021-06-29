#include <stdio.h>                                                                                          
#include <stdlib.h>                                                                                         
                                                                                                            
int* ReadArray(int N)                                                                                       
{                                                                                                           
  int* A = (int*)malloc(N * sizeof(int));                                                                   
  int i;                                                                                                    
  for(i=0; i<N; i++)                                                                                        
    scanf("%d", A+i);                                                                                       
  return A;                                                                                                 
}                                                                                                           
                                                                                                            
void PrintArray(int* A, int N){                                                                             
  int i;                                                                                                    
  for(i=0; i<N; i++){                                                                                       
    printf("%d", A[i]);                                                                                    
    if (i < N-1)
        printf(" ");
  }                                                                                                         
  printf("\n");                                                                                             
}                                                                                                           
                                                                                                            
                                                                                                            
void InsertionSort(int* A, int N)                                                                           
{                                                                                                           
  int i, j;                                                                                                 
  int key;
  PrintArray(A, N); 
  for(i=1; i<N; i++){                                                                                       
    key = A[i];                                                                                             
    j = i-1;                                                                                                
    while(j >= 0 && A[j] > key){                                                                            
      A[j+1] = A[j];                                                                                        
      j--;                                                                                                  
    }                                                                                                       
    A[j+1] = key;                                                                                           
    PrintArray(A, N);                                                                                       
  }                                                                                                         
}  

int main(void){
    int N;
    scanf("%d", &N);
    int* A = ReadArray(N);
    
    InsertionSort(A, N);

    free(A);
    return 0;
}
