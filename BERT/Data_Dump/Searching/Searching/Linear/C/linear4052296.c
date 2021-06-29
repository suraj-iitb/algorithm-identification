#include<stdio.h>
int linear(int *,int,int);
int main(){
  int n,i;
  int q,j;
  int S[10000],T[500];
  int sum = 0;
  scanf("%d",&n);
  for(i = 0;i < n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(j = 0;j < q;j++){
    scanf("%d",&T[j]);
    if(linear(S,T[j],n) == 1){
      sum++;
    }
  }
  printf("%d\n",sum);
  return 0;
}

int linear(int *S,int T,int n){
  int i;
  for(i = 0;i < n;i++){
    if(T == S[i]){
      return 1;
    }
  }
  return 0;
}



