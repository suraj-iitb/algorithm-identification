#include<stdio.h>
#define N 10000

int main()
{
  int i,j,n,q;
  int S[N],key,c=0; // keyは数列T

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&key);
    S[n]=key;
    for(j=0;S[j]!=key;j++){
    }
    if(j==n) continue;
    c++;
  }
  printf("%d\n",c);

  return 0;
}
  

