#include <stdio.h>

#define N 100

int main( )
{

  int i,j,A[N],v=0,a,k=0;

  scanf("%d",&a);
  for(i=0; i<a; i++){
    scanf("%d",&A[i]);
  }
  for(i=0 ; i<a ; i++){
    printf("%d",A[i]);
    if(i<a-1) printf(" ");
  }
  printf("\n");
  
  for(i=1 ; i<a ; i++){
    v = A[i];
    j = i-1;
    while(j >= 0 && A[j] > v){
      A[j+1] = A[j];
      j--;
    }
    A[j+1]=v;
    for(k=0 ; k<a ; k++){
      printf("%d",A[k]);
      if(k<a-1) printf(" ");
    }
    printf("\n");
  }
  return 0;
}

	    

