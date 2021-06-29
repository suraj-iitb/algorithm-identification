#include<stdio.h>
#include<stdlib.h>

#define M 100001

struct Node
{
  char mark;
  int num;
  int s;
};

int partition(struct Node *A, int n, int m)
{
  int i, j, a;
  struct Node tmp;
  a = A[m].num;
  i = n - 1;
  for(j = n; j <= m - 1;j++)
    {
      if(A[j].num <= a)
	{
	  i = i + 1;
	  tmp = A[i];
	  A[i] = A[j];
	  A[j] = tmp;
	}
    }
  tmp = A[i+1];
  A[i+1] = A[m];
  A[m] = tmp;
  return i+1;
}

void quicksort(struct Node *A, int n, int m)
{
  int a;
  if(n < m)
    {
      a = partition(A, n, m);
      quicksort(A, n, a-1);
      quicksort(A, a+1, m);
    }
}

int main()
{
  int n, i, f = 0;
  struct Node A[M];
  scanf("%d", &n);
  for(i = 0; i < n; i++)
    {
      scanf(" %c%d", &A[i].mark, &A[i].num);
      A[i].s = i;
    }
  quicksort(A, 0, n-1);

  for(i = 0; i < n; i++)
    {
      if(A[i].num == A[i+1].num)
	{
	  if(A[i].s > A[i+1].s)
	    {
	      f = 1;
	    }
	}
    }
  if(f == 0)
    {
      printf("Stable\n");
    }
  else
    {
      printf("Not stable\n");
    }
  for(i = 0; i < n; i++)
    {
      printf("%c %d\n", A[i].mark, A[i].num);
    }
  return 0;
}

