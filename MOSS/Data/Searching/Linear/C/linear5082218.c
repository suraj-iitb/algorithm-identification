#include <stdio.h>
#include <stdlib.h>
#define N 10000

int search(int *,int,int);

int main(){
  int n,s[N],q,t,i,cnt=0;
  
  scanf("%d",&n);
  if(n>N)exit(0);

  for(i=0;i<n;i++)
    {
      scanf("%d",&s[i]);
    }
  scanf("%d",&q);
  if(q>500)exit(1);

  for(i=0;i<q;i++)
    {
      scanf("%d",&t);
      if(search(s,n,t))cnt++;
    }
  printf("%d\n",cnt);
  return 0;
}

int search(int A[],int n,int t){
  int i=0;
  A[n]=t;
  while(A[i]!=t)i++;
  return n!=i;
}

