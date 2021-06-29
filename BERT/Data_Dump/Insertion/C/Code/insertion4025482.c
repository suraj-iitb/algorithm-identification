#include <stdio.h>

void insertionSort(int *, int);

int main(){
  int A[100],i,N;

  scanf("%d",&N);
  if(N < 1 || N > 100)return 0;

  for(i = 0;i < N;i++){
     scanf("%d",&A[i]);
  if(A[i] < 0 || A[i] > 1000)break;
}
   
   insertionSort(A,N);

  return 0;
}

void insertionSort(int A[],int N){
int i,j,k,v;

for(k = 0;k < N;k++){
     printf("%d",A[k]);
   if(k == N-1)break;
     printf(" ");
   }
     printf("\n");

 for(i = 1;i < N;i++){
   v = A[i];
   j = i-1;
   
    

   while(j>=0 && A[j] > v){
    A[j+1] = A[j];
    j--;
     A[j+1] = v;
}
   
   for(k = 0;k < N;k++){
     printf("%d",A[k]);
      if(k == N-1)break;
     printf(" ");
   }
     printf("\n");
  }
}

