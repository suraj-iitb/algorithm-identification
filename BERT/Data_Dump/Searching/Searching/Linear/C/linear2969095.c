#include<stdio.h>
#include<stdlib.h>

int main(){
  int n, *S, q;
  int i, j, in, count=0;

  // input data
  scanf("%d",&n);
  S = (int *)malloc(sizeof(int) * n);
  for(i=0; i<n; i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(i=0; i<q; i++){
    scanf("%d",&in);
    for(j=0; j<n; j++){
      if(in == S[j]){
        count ++;
        break;
      }
    }
  }

  printf("%d\n",count);

  return 0;
}

