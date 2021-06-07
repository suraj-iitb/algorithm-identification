#include<stdio.h>
#define N 10000

int main(){

  int S[N],T[N];
  int n,q,a,i,j,count=0;
  
  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);

  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }
  
  for(j=0;j<=q-1;j++){

    i=0;
    S[n]=T[j];

    while(S[i]!=T[j]){
      i++;
    }

    if(i!=n) count++;

  }

  printf("%d\n",count);

  return 0;

}

