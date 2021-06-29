#include <stdio.h>
int main(){
  int i,j,N,k,p;
  int v[1000];
  scanf("%d",&N);
  for(i=0; i < N;i++){
    scanf("%d",&v[i]);
  }
  for(i=0;i< N;i++){
    k=v[i];
    j=i-1;
    while(j>= 0 && v[j] > k){
      v[j+1]=v[j];
      j--;
      v[j+1]=k;
    }
    for(p=0;p < N ;p++){
        if (p<N-1) {
      printf("%d ",v[p]);
        } else {
            printf("%d",v[p]);
        }
    }
    printf("\n");
  }
  return 0;
}

