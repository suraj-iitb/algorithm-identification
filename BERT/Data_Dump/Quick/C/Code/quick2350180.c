#include<stdio.h>

#define N 100000

typedef struct
{
  char suit;
  int num;
  int order;
}card;

int partition(card *, int, int);
void quicksort(card *, int, int);

int main()
{
  int n, i, j, min, flg=0;
  char str[2];
  card A[N];

  scanf("%d", &n);
  for(i=0; i<n; i++)
    {
      //printf("%d\n",i);
      scanf("%s%d", str, &A[i].num);
      A[i].suit = str[0];
      A[i].order = i;
    }

  quicksort(A, 0, n-1);
  
  for(i=0; i<n; i++)
    {
      if(i < n-1 && A[i].num == A[i+1].num)
	{
	  if(A[i+1].order < A[i].order) flg=1;
	}
    }
  
  if(flg == 0) printf("Stable\n");
  else printf("Not stable\n");
  for(i=0; i<n; i++)
    {
      printf("%c %d\n", A[i].suit, A[i].num);
    }


  return 0;
}
int partition(card *A, int p, int r)
{
  int x, i, j;
  card t;

  x = A[r].num;
  i = p-1;

  for(j=p; j<r; j++)
    {
      if(A[j].num <= x)
	{
	  i++;
	  t = A[i];
	  A[i] = A[j];
	  A[j] = t;
	}
    }
  t = A[i+1];
  A[i+1] = A[r];
  A[r] = t;

  return i+1;
}
void quicksort(card *A, int p, int r)
{
  int q;
  
  if(p<r)
    {
      q = partition(A, p, r);
      quicksort(A, p, q-1);
      quicksort(A, q+1, r);
    }
}
