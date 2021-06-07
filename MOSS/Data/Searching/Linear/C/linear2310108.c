#include<stdio.h>
#define MATCH 1
#define NOT -1
int serch(int,int ,int);
int search(int *A,int n,int key)
{
  int i=0;
  A[n]=key;
  for(i=0;i<n;i++)
    {
      if(A[i]==key) return MATCH;
    }
    return NOT;
}

int main()
{
  int A[10001];
  int i,j,n,q,cnt=0;
  int key;

  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      scanf("%d",&A[i]);
    }

  scanf("%d",&q);
  for(i=0;i<q;i++)
    {
      scanf("%d",&key);
      if(search(A,n,key)==MATCH)cnt++;
    }
  printf("%d\n",cnt);
  return 0;
}
  
