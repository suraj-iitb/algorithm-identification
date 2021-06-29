#include<stdio.h>
#define MAX 100000

typedef struct{
  int count;
  char pict;
  int number;
}num;

int partition(num *, int, int);
void quicksort(num *,int ,int);

 main()
{
  int flag=0,n,i,r,p;/*q??????????????¢??°??§??????????????????*/
  num A[MAX];
  char dd;
  scanf("%d%c",&n,&dd);
  for(i=0;i<n;i++)
    {
      scanf("%c%d%c",&A[i].pict,&A[i].number,&dd);
      A[i].count = i;  /*???????????\????????????*/
 
    }
  r = n-1;
  p = 0;

  quicksort(A,p,r);

  for(i=0;i<n-1;i++)
    {
      if(A[i].number == A[i+1].number && A[i].count > A[i+1].count && flag==0)
	{
	  printf("Not stable\n");
	  flag = 1;
	}
      if(flag == 0 && i== n-2){
	printf("Stable\n");
      }
    }

  for(i=0;i<n;i++)
    {
      printf("%c %d\n",A[i].pict,A[i].number);
    }

  return 0;
}

int partition(num *a,int p, int r)/*partition????????????????????????????????????*/
{
  int i,j; /*??????????§??????????????????¨exchange*/
  int x;
  num ex;
  x = a[r].number;
  i = p-1;

  for(j=p;j<r;j++)
    {
      if(a[j].number<=x)
	{

	  i = i+1;
	  ex = a[i];
	  a[i] = a[j];
	  a[j] =  ex;
	}
    }
  ex = a[i+1];
  a[i+1] = a[r];
  a[r] = ex;

  return i+1;
}

void quicksort(num *a,int p, int r)
{
  int q;

  if(p<r)
    {
      q = partition(a,p,r);
      quicksort(a,p,q-1);
      quicksort(a,q+1,r);

    }

  return ;
}
