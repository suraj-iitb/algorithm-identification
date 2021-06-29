#include<stdio.h>

void marge(int *,int,int,int);
void margesort(int *,int,int);

int cnt=0;

int main()
{
  int n,i;

  scanf("%d",&n);

  int a[n];

  for(i = 0 ; i < n ; i++)
    {
      scanf("%d",&a[i]);
    }
  margesort(&a[0],0,n);

  
  for(i = 0 ; i < n ; i++)
    {
      printf("%d",a[i]);
      if(i != n-1 ) printf(" ");
    }
  printf("\n%d\n",cnt);
  
  return 0;
}

void marge(int *a,int left,int mid,int right)
{
  int n1 = mid -left;
  int n2 = right - mid;
  int k;
  int i;

  int L[n1],R[n2];

  for(i = 0 ; i < n1 ; i++)
    {
      L[i] = a[left + i];
    }
   for(i = 0 ; i < n2 ; i++)
    {
      R[i] = a[mid + i];
    }

   L[n1] = 1000000001;
   R[n2] = 1000000001;

   int j = 0;
   i = 0;

   for(k = left ; k < right ; k++)
     {
       cnt += 1;
       if(L[i] <= R[j])
	 {
	   a[k] = L[i];
	   i += 1;
	 }
       else
	 {
	   a[k] = R[j];
	   j += 1;
	 } 
     }
}

void margesort(int *a,int left,int right)
{
  if(left+1 < right)
    {
      int mid = (left + right) / 2;
      margesort(&a[0],left,mid);
      margesort(&a[0],mid,right);
      marge(&a[0],left,mid,right);
    }

}

