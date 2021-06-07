#include<stdio.h>
#define Maxn 10000
#define Maxq 500

int search(int);
int A[Maxn],n;

int main()
{
  int q=0,i=0,k=0;
  int B[Maxq];

  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      scanf("%d",&A[i]);
    }
    scanf("%d",&q);
  for(i=0;i<q;i++)
    {
      scanf("%d",&B[i]);
    }

  
  for(i=0;i<q;i++)
    {
      if(search(B[i])==1)
	k++;
    }

  printf("%d\n",k);

  return 0;
}

int search(int key)
{
  int i;
  for(i=0;i<n;i++)
    {
      if(A[i]==key) return 1;
    }
  return 0;
}
