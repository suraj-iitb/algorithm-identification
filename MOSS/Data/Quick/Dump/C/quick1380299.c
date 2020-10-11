#include<stdio.h>
#include<stdlib.h>
#define MAX 100001

typedef struct{
  char mark;
  int num;
  int order;
}card;

int partition(card *, int, int);
void quicksort(card *, int, int);

int main()
{
  card *A;
  int i, j, n, judge=0;
  char a, b;

  scanf("%d%c", &n, &a);
  A = (card *)malloc(sizeof(card)*n*2 + 1);

  for(i=0; i<n; i++)
    {
      scanf("%c%c%d%c", &A[i].mark, &a, &A[i].num, &b); 
      A[i].order = i;
    }

  quicksort(A, 0, i-1);
  
  for(i=0; i<n; i++)
    {      
      if(A[i].num == A[i+1].num)
	{
	  if(A[i].order > A[i+1].order)
	    {
	      judge = 1;
	      break;
	    }
	}
    }

  if(judge ==0) printf("Stable\n");
  else printf("Not stable\n");

  for(i=0; i<n; i++)
    {
      printf("%c %d\n", A[i].mark, A[i].num);
    }
  
  free(A);
  return 0;
}

void quicksort(card *A, int p, int r)
{
  int q;

  if(p < r)
    {
      q = partition(A, p, r);
      quicksort(A, p, q-1);
      quicksort(A, q+1, r);
    }
}

int partition(card *A, int p, int r)
{
  card change;
  int i = p-1, j;
  int x = A[r].num;

  for(j=p; j<r; j++)
    {
      if(A[j].num <= x)
	{
	  i = i + 1;
	  change = A[j];
	  A[j] = A[i];
	  A[i] = change;
	}
    }
  change = A[r];
  A[r] = A[i+1];
  A[i+1] = change;

  return i+1;
}
