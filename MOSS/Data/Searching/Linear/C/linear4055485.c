#include<stdio.h>
#define N 10000
int main(){
  int a,b,i,j,key,A[N],B[N],count=0;

  scanf("%d",&a);
  for(i=0;i<a;i++)
    scanf("%d",&A[i]);

  
  scanf("%d",&b);
  for(i=0;i<b;i++){
    scanf("%d",&B[i]);
  
    j=0;
    A[a]=B[i];
    while(A[j]!=B[i]){
      
      j++;
      
      if(j==a) break;

    }
    if(j!=a) count++;
  }
  printf("%d\n",count);
 
  return 0;
}
  

