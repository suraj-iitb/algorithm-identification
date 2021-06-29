#include <stdio.h>
#define N 100000
struct Card
{
  char suit;
  int value;
  int key;
};

struct Card A[N];

int Partition(int p, int r)
{
  int x, i, j;
  struct Card tmp;
  x = A[r].value;
  i = p - 1;

  for(j = p;j <= r - 1;j++)
    {
      if(A[j].value <= x)
	{
	  i++;
	  tmp = A[i];
	  A[i] = A[j];
	  A[j] = tmp;
	}
    }

  tmp = A[i + 1];
  A[i + 1] = A[r];
  A[r] = tmp;

  return i + 1;
}


void Quicksort(int p, int r)
{
  int q;

  if(p < r)
    {
      q = Partition(p, r);
      Quicksort(p, q - 1);
      Quicksort(q + 1, r);
    }
}


int main()
{
  int n, i;
  char ch;

  scanf("%d%c",&n,&ch);

  for(i = 1;i <= n;i++)
    {
      scanf("%c%c%d%c",&A[i].suit,&ch,&A[i].value,&ch);
      A[i].key = i;
    }

  Partition(1, n);
  Quicksort(1, n);

  for(i = 1;i <= n;i++)
    {
      if(A[i].value == A[i + 1].value && A[i].key > A[i + 1].key)
	{
	  printf("Not stable\n");
	  break;
	}
    }

      if(i == n + 1)
	{
	  printf("Stable\n");
	}

      for(i = 1;i <= n;i++)
	{
	  printf("%c %d\n",A[i].suit,A[i].value);
	}

      return 0;
}
