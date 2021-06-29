#include<stdio.h>
#include<stdlib.h>

int serch(int *, int, int);

int main(){
  int n, q, i, key, cnt = 0;
  int *S, *T;

  scanf("%d",&n);
  S = malloc(sizeof(int) * n);

  for(i=0; i < n; i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);
  T = malloc(sizeof(int) * q);

   for(i=0; i < q; i++){
    scanf("%d",&T[i]);
  }

   for(i = 0; i < q; i++){
     key = T[i];
     if(serch(S, n, key) == 1) cnt++;
   }
   
   printf("%d\n",cnt);

   return 0;
}

int serch(int *x, int n, int key)
{
  int i, a = 0;
  for(i = 0; i < n; i++){
    if(x[i] == key)a++;;
  }
  if(a != 0)return 1;
  else return 0;
}

