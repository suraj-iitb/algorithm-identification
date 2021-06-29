#include<stdio.h>
#define N 10000
#define Q 500
int linearSearch(int,int,int*);

int main(){
  int n,q,c = 0,i;
  int S[N],T[Q];

  scanf("%d",&n);
  for(i = 0; i < n; i++)
  scanf("%d",&S[i]);
  scanf("%d",&q);
  for(i = 0; i < q; i++){
  scanf("%d",&T[i]);
  c += linearSearch(n,T[i],S);
  }
  printf("%d\n",c);

  return 0;
}

int linearSearch(int n,int key,int a[]){

  int i;

  for(i = 0; i < n; i++)
    if (a[i] == key) return 1;
    return 0;
}
