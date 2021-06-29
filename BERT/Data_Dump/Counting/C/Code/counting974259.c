#include<stdio.h>
#define N 2000000

void inNumber(int[]);
int desideK(int[]);
void countingSort(int[],int[],int);

int n=0;
int B[N];

int main(){

  int k=0,i;
  int A[N];
  A[0]=0; 
  
  scanf("%d",&n);
  inNumber(A);
  k = desideK(A); 
  countingSort(A,B,k);
  
  return 0;
}

void inNumber(int A[]){

  int i;

  for(i=1;i<=n;i++){
    scanf("%d",&A[i]);
  }  
}
int desideK(int A[]){
  int i,k=0;
  for(i=1;i<=n;i++){
    if(k<A[i]){
      k=A[i];
    }
  } 
  return k;
}
void countingSort(int A[],int B[],int k){

   int i,j;
   int C[k+1];
 
   for(i=0;i<=k;i++){
     C[i]=0;
   } 
 
   for(j=1;j<=n;j++){
     C[A[j]]++;
   }
 
   for(i=1;i<=k;i++){
     C[i]+= C[i-1];
   }

   for(j = n; j > 0; j--){
     B[C[A[j]]]=A[j];
     C[A[j]]--; 
   }

   for(i=1;i<=n;i++){
     
     if(i > 1){
       printf(" ");
     }
     printf("%d",B[i]);
   }
   
   printf("\n");
}
