#include <stdio.h>


#define N 10000
int A[N],B[N],C[N];
void linear(int*,int*);
int a=0,b=0,cout=0;

int main(){
 
  scanf("%d",&a);
  
  for(int i=0;i<a;i++){
     scanf("%d",&A[i]);
  }
  
  scanf("%d",&b);
  
  for(int i=0;i<b;i++){
     scanf("%d",&B[i]);
  }

  linear(A,B);
  
  //for(int i=0;i<k;i++){
     printf("%d\n",cout);
  // }  
  
   
return 0;
}

void linear(int *A ,int *B){
   int j;
   
   for(int i=0;i<b;i++){
      A[a] = B[i];
      j=0;
      while(A[j]!=A[a]){
         j++;
      }
      
      if(j!=a){
        cout++;
      }
      
   }
   

}
