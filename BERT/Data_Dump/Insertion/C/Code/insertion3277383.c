#include<stdio.h>



int main(){
  int i,v,j,N,k,l;
  int A[1000];
 

  scanf("%d",&N);
  for(i=0 ; i<N ; i++) scanf("%d",&A[i]);


  

  /*hairetu*/
  for(k=0;k<N;k++){
    if(k>0)printf(" ");
    printf("%d",A[k]);
  }
  printf("\n");
  
  /*sort*/
  for(l=1;l<N;l++){
    v=A[l];
    j=l-1;

    while(j>=0 && A[j]>v){
      A[j+1] = A[j];
      j--;
    }
    
    A[j+1] = v;
    for(k=0;k<N;k++){
    if(k>0)printf(" ");
    printf("%d",A[k]);
    
  }

    printf("\n");

  }

  

  return 0;

}

