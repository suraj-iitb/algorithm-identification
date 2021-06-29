#include <stdio.h>

int main(){

  int N,i,j,k,minj,t,c=0;
  
  scanf("%d",&N);

  int A[N];

  for(k=0;k<N;k++){
    scanf("%d",&A[k]);
  }

   
  for(i=0;i<N;i++){
    minj=i;
    for(j=i;j<N;j++){
       
      if(A[j]<A[minj]){
	minj=j;
      }
    }
    t=A[i];
    A[i]=A[minj];
    A[minj]=t;
    if(A[i]!=A[minj]) c++;
}
   
  for(k=0;k<N;k++){
    if(k!=N-1)printf("%d ",A[k]);
    else printf("%d",A[k]);
  }
  printf("\n%d\n",c);
  
  return 0;
}

