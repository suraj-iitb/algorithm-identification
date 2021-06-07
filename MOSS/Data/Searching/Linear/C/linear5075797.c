#include <stdio.h>

int serch(int,int,int *);

int main () {

  int n,q,i,S[10000],T[10000];
  int sum = 0;

  scanf("%d",&n);
  for (i=0; i<n; i++) scanf("%d",&S[i]);
  scanf("%d",&q);
  for (i=0; i<q; i++) scanf("%d",&T[i]);

  for(i=0; i<q; i++){
    if(serch(T[i],n,S) == 1) sum++;
  
  }
  printf("%d\n",sum);

  return 0;
}

int serch(int a,int n,int *S){

  int i;
  for(i=0; i<n; i++){
    if(a == S[i]) return 1;
  }
  return 0;
  

}

