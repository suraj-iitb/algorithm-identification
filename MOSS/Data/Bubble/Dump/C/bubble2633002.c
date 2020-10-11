#include <stdio.h> 
int i,j; 
int count=0; 

 
void Process(int A[ ], int n){ 
 for(i=0;i<n-1;i++) 
  printf("%d ",A[i]); 
 printf("%d\n",A[i]); 
} 

 
void BubbleSort(int A[ ], int n){ 
 int j,temp; 
  for(i = 0; i < n-1; i++){ 
   for(j = n-1; j > i; j--) 
   if(A[j-1] > A[j]){ 
    temp = A[j-1]; 
    A[j-1] = A[j]; 
    A[j] = temp; 
    count++; 
   }   
 } 
} 

 
int main(void){ 
 int N; 
 scanf("%d",&N); 
 int A[100]; 
 for(i=0;i<N;i++) 
  scanf("%d",&A[i]); 
  
 BubbleSort(A, N); 
 Process(A, N); 

 printf("%d\n",count); 
  
 return 0; 
}
