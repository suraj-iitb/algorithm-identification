#include<stdio.h>

#define N 100

int main(){
  int A[N],a,i,j,v,k;

  scanf("%d",&a);

  for(i=0;i<a-1;i++){
    scanf("%d",&A[i]);
    printf("%d ",A[i]);
   
  }
  
  scanf("%d",&A[a-1]);
  printf("%d",A[a-1]);
  printf("\n");
  
  for (i=1;i<=a-1;i++){
    v = A[i];
    j = i - 1;
      
    while(j >= 0 && A[j] > v){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
    for(k=0;k<a-1;k++){
     
      printf("%d ",A[k]);
    }
    printf("%d",A[a-1]);
    printf("\n");
  }   
   
  return 0;
  

}

