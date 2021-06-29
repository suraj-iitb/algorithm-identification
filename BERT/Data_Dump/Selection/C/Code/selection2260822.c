#include<stdio.h>
int selectionSort(int *,int);

int main() {
  int i,j,k,sum,num;
  scanf("%d",&sum);

  int sei[sum];
  for(i=0;i<sum;i++)
    {
      scanf("%d",&sei[i]);
    }

  num = selectionSort(sei,sum);

  for(i=0;;i++)
    {
      printf("%d",sei[i]);
      if(i>=sum-1)break;
      printf(" ");
    }

  printf("\n%d\n",num);

  return 0;
}

int selectionSort(int *A,int N)
{
  int i,j,k,minj,num=0,tmp;

  for(i=0;i<N;i++)
    {
      minj = i;
      for(j=i;j<N;j++)
	{
	  if(A[j] < A[minj])
	    {
	      minj = j;
	    }
	}
      if(minj!=i)
	{
	  tmp = A[i];
	  A[i] = A[minj];
	  A[minj] = tmp;
	  num++;
	}
    }

  return num;
}
