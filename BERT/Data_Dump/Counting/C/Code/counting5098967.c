#include <stdio.h>


#define N 2000100
#define MAX 10000

int A[N],B[N],C[MAX];
void Counting(int*,int*);


int a=0,b=0,n;

int main(){
 
  scanf("%d",&n);
  
  for(int i=1;i<=n;i++){
     scanf("%d",&A[i]);
  }
  
  
  for(int i=0;i<MAX;i++){
     B[i] = 0;
     C[i] = 0;
  }

  Counting(A,B);
  

  for(int i=1;i<=n;i++){
     printf("%d",B[i]);
     if(i<n)printf(" ");
  }
  printf("\n");

   
return 0;
}

void Counting(int *A ,int *B){

    for(int i=0;i<n;i++){
       C[A[i+1]]++;
    }   
    
    
    for(int i=1;i<MAX;i++){
       C[i] = C[i] +C[i-1];
    }
    
    
    for(int i=n;0<i;i--){
        B[C[A[i]]] = A[i];
        C[A[i]]--;
       
    }
    



}
