#include<stdio.h>
#define NN 10000
#define NQ 500
int linearSearch(int *,int ,int);
int main(){
  int n, S[NN], q, T[NQ];
  int i=0,count=0;
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d", &S[i]);
  scanf("%d",&q);
  for(i=0;i<q;i++)scanf("%d", &T[i]);
  for(i=0;i<q;i++) if(linearSearch(S, T[i], n)) count++;
  printf("%d\n",count);
return 0;
}
int linearSearch(int *A, int key, int n)
{int  i = 0;
 A[n] = key;
 while(A[i]!=key) i++;
 if(i == n) return 0;
 return 1;
}
