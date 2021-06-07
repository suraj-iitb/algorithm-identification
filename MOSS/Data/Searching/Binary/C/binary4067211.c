#include<stdio.h>
#define N 100005
int search(int ,int,int *);

int main()
{
int n,A[N],q,B,found = 0,i;

scanf("%d",&n);
for(i=0;i<n;i++)
  {
scanf("%d",&A[i]);
}
scanf("%d",&q);
for(i=0;i<q;i++)
  {
scanf("%d",&B);
if(search(B,n,A)) found++;
}
printf("%d\n",found);

return 0;
}

int search(int B,int n,int A[])
{
  int left = 0,right = n,mid;
  while(left < right )
    {
      mid = (left + right)/2;
      if(B == A[mid]) return 1;
      if(B > A[mid])
	{
	  left = mid + 1;
	}
      else if(B < A[mid])
	{
	  right = mid ;
	}
    }
  return 0;
}

