#include <stdio.h>

int main(){
  int n,A[100],i,j,x,temp,c=0;

  scanf("%d",&n);

  for(i=0 ; i<n ; i++){
    scanf("%d",&A[i]);
  }

  for(i=0 ; i<n-1 ; i++){
     x=i;
    for(j=i ; j<n ; j++){
      if(A[j] < A[x])x=j;
    }
    if(x!=i){
      temp=A[i];
      A[i]=A[x];
      A[x]=temp;
      c++;
    }
  }

  for(i=0 ; i<n ; i++){
    printf("%d",A[i]);
    if(i!=n-1) printf(" ");
  }

  printf("\n");
  printf("%d\n",c);
  
  return 0;
}

  

