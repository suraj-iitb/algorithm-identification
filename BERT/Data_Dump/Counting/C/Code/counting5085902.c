#include <stdio.h>

int S[10001],Q[10001];

int main(){
  int i,q,n,m=0;

  scanf("%d",&n);

  int M[n],N[n],maxA=0;

  for(i=0;i<n;i++){
    scanf("%d",&M[i]);
    Q[M[i]]++;
  }  

  while(1){
    if(i==n) break;
  }  
  
  for(i=0;i<10001;i++){
    m+=Q[i];
    S[i]=m-1;
  }

  for(i=0;i<n;i++){
    N[S[M[i]]]=M[i];
    S[M[i]]--;
  }

  for(i=0;i<n-1;i++){
    printf("%d ",N[i]);
  }

  printf("%d\n",N[n-1]);
  
  return 0;
}
