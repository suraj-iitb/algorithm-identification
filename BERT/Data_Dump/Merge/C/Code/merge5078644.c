#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void merge(int,int,int);
void mergesort(int,int);

int n,count = 0;
int s[500000];

int main()
{
  int i;
  //int n;
  //int s[500000];

  //printf("%f\n", INFINITY);
  scanf("%d",&n);
  if(n > 500000)
    {
      printf("terminated because of the limitation\n");
      exit(1);
    }
  
  for(i = 0; i < n; i++)scanf("%d",&s[i]);

  mergesort(0,n);

  for(i = 0; i < n; i++)
    {
      printf("%d",s[i]);
      if(i == n-1)printf("\n");
      else printf(" ");
    }
  printf("%d\n",count);

  return 0;
}

void merge(int left,int mid,int right)
{
  int i,j,k;
  int n1 = mid - left;
  int n2 = right - mid;

 int L[n1+1],R[n2+1];
  for(i = 0; i < n1; i++)L[i] = s[left + i];
  for(i = 0; i < n2; i++)R[i] = s[mid + i];
  L[n1] = 2000000000;//INFINITY;
  R[n2] = 2000000000; //INFINITY;

  i = 0;
  j = 0;
  for(k = left; k < right; k++)
    {
      if(L[i] <= R[j])
	{
	  s[k] = L[i];
	  i++;
	  count++;
	}
      else
	{
	  s[k] = R[j];
	  j++;
	  count++;
	}
    }

}

void mergesort(int left,int right)
{
  int mid;
  if(left + 1 < right)
    {
      mid = (left + right)/2;
      mergesort(left,mid);
      mergesort(mid,right);
      merge(left,mid,right);
    }
}
		

  

