#include<stdio.h>

int linearSearch(int,int *,int);

int main(){
  int S[10000],T[500],n,q;
  int i;
  int res=0;

  scanf("%d",&n);
  if (n<=10000){
    for(i=0; i<n; i++)scanf("%d",&S[i]);
  }

  scanf("%d",&q);
  if (q<=500){
    for(i=0; i<q; i++){
      scanf("%d",&T[i]);
      res += linearSearch(n,S,T[i]);
    }
  }

  printf("%d\n",res);

  return 0;
}

int linearSearch(int n,int *S,int key)
{
  int i=0;
  S[n] = key;
  while(S[i] != key)i++;
  if(i != n)return 1;
  else return 0;
}

