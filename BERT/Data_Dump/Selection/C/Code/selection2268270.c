#include <stdio.h>

void swap (int*,int*);

int main()
{
  int i,j,count=0,min=0,N;
  int a[100];

  scanf("%d",&N);
  for(i=0;i<N;i++)
    {
      scanf("%d",&a[i]);
    }

  for(i=0;i<N-1;i++)
    {
      min=i;
      for(j=i;j<N;j++)
	{
	  if(a[j]<a[min]) min=j;
	}
      swap(&a[i],&a[min]);
      if(i!=min) count++;
    }

  for(i=0;i<N;i++)
    {
      printf("%d",a[i]);
      if(i!=N-1) printf(" ");
    }
  printf("\n");
  printf("%d\n",count);

  return 0;
}
	  
void swap(int *x,int *y)
{
  int z;

  z=*x;
  *x=*y;
  *y=z;
}
