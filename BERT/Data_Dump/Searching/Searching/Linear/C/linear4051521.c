#include<stdio.h>

#define SIZEN 10000

int main(){
  int n,q,i,j,x,count = 0,A[SIZEN];

  scanf("%d",&n);

  for(i = 0;i < n;i++){
    scanf("%d",&A[i]);
  }

  scanf("%d",&q);

  for(i = 0;i < q;i++){
    scanf("%d",&x);
    for(j = 0;j < n;j++){
      if(x == A[j]){
        count++;
        break;
      }
    }
  }
  printf("%d\n",count);
  return 0;
}

