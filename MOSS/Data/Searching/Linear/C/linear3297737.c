#include<stdio.h>
#include<stdlib.h>

int linearSearch(int*,int,int);

int main(){
  int i,j,n,q,*S,*T;

  scanf("%d",&n);
  if(n > 10000)exit(1);
  S = malloc((n+1) * sizeof(int));
  for(i=0;i < n;i++){
    scanf("%d",&S[i]);
    if(S[i] < 0)exit(2);
  }
  scanf("%d",&q);
  if(q > 500)exit(3);
  T = malloc(q * sizeof(int));
  for(i=0;i < q;i++){
    scanf("%d",&T[i]);
    if(T[i] < 0)exit(4);
    for(j=0;j < i;j++){
      if(T[j] == T[i])exit(5);
    }
  }
  j = 0;
  for(i=0;i < q;i++){
    if(linearSearch(S,T[i],n))j++;
  }
  printf("%d\n",j);
  return 0;  
}

int linearSearch(int *S,int t,int n){
  int i = 0;
  S[n] = t;
  while(S[i] != t){
    i++;
  }
  if(i == n)return 0;
  return 1;
}

