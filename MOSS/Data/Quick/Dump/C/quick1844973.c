#include <stdio.h>
#include <stdlib.h>

struct card
{
  int n;
  int p;
  char c;
} typedef card;

card A[100000];
int stableFlag = 0;

int Partition(int p, int r)
{
  int i, j;
  card tmp;

  i = p - 1;
  for(j = p; j < r; j++)
    {
      if(A[j].n <= A[r].n)
	{
	  i = i + 1;
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

void QuickSort(int p, int r)
{
  int q;

  if(p < r)
    {
      q = Partition(p, r);
      QuickSort(p, q - 1);
      QuickSort(q + 1, r);
    }
}

int StableOrNot(int n)
{
    int i;
    
    for(i = 0; i < n; i++)
    {
        if(A[i].n == A[i + 1].n &&
           A[i].p >= A[i + 1].p) return 0;
    }
    return 1;
}

int main()
{
  int i;
  int n;

  scanf("%d", &n);
  for(i = 0; i < n; i++)
    {
      while(1)
        {
        A[i].c = getchar();
        if(A[i].c != ' ' && A[i].c != '\n') break;
        }
      A[i].p = i + 1;
      scanf("%d", &A[i].n);
    }

  QuickSort(0, n - 1);

  if(StableOrNot(n) == 1) printf("Stable\n");
  else printf("Not stable\n");
  for(i = 0; i < n; i++)
    {
      printf("%c %d\n", A[i].c, A[i].n);
    }

  return 0;
}
