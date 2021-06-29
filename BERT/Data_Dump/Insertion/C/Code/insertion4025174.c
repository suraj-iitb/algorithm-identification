#include <stdio.h>
#define N 100


int main(){
  int A[N],v,i,j,n,a=0;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  
for(a=0;a<n;a++){
      printf("%d",A[a]);
      if(a!=n-1)
      printf(" ");
     }
    printf("\n");
    
  for(i=1;i<n;i++){
    
    v=A[i];
    j=i-1;
    while(j>=0&&A[j]>v){
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=v;
     for(a=0;a<n;a++){
      printf("%d",A[a]);
      if(a!=n-1)
      printf(" ");
     }
    printf("\n");
   
  }

  
  return 0;
}

