#include<stdio.h>

int Search(int A[], int n, int agari){
  int i = 0;
  A[n] = agari;
  while(A[i] != agari)i++;
  return i != n;
}

int main(){
  int i,n,A[10000 + 1],q,agari,sum = 0;

  scanf("%d", &n);
  for(i = 0; i < n; i++)scanf("%d",&A[i]);

  scanf("%d",&q);
  for(i = 0; i < q; i++){
    scanf("%d", &agari);
    if(Search(A, n, agari))sum++;
  }
  printf("%d\n",sum);

  return 0;
}

