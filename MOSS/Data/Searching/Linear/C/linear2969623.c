#include<stdio.h>
#define N 100000

int linearSearch(int S[],int n, int key)
  {
    int i=0;
    S[n]=key;
    while(S[i]!=key)i++;
    return i!=n;
  }



int main()
{
  int n,m,i,S[N],key,count=0;

  scanf("%d",&n);

  for(i=0; i<n; i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&m);

  for(i=0; i<m; i++){
    scanf("%d",&key);
    if(linearSearch(S,n,key))count++;
  }

  printf("%d\n",count);
  return 0;
}

