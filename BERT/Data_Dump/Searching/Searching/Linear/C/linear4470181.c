#include<stdio.h>
int i,j,c=0;
int search(int t,int n, int S[])
{
  int i=0;
  S[n] = t;
  while(S[i] != t){
    i++;
    if(i==n)
      return 0;
  }
  c++;
  //  printf("%d\n",c);
}
int main()
{
  int n,q;
  scanf("%d",&n);
  int S[n];
  for(i=0; i<n; i++)
    scanf("%d",&S[i]);
  scanf("%d",&q);
  int T[q];
  for(i=0; i<q; i++){
    scanf("%d",&T[i]);
    search(T[i],n,S);
  }
  printf("%d\n",c);
  return 0;
}

