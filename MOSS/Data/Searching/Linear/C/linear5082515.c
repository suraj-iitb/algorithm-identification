#include<stdio.h>
#define X 1000000


int main(){
  int i,j,count=0;
  int n,q;
  int S[X],T[X];


  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(j=0;j<q;j++){
    scanf("%d",&T[j]);
  }
  for(j=0;j<q;j++){
    for(i=0;i<n;i++){
      if(S[i]==T[j]){
        count++;
        break;
      }
    }
  }

  printf("%d\n",count);

  return 0;
}

