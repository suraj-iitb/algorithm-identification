#include <stdio.h>


typedef struct
{
  char ch;
  int num;
  int sta;
}Trump;


int Stable(Trump *Qui, int n)
{
  int i;

  for(i = 0; i < n; i++)
  {
    if(Qui[i].num == Qui[i+1].num && Qui[i].sta > Qui[i+1].sta)
    {
      return 1;
    }
  }
  return 0;
}


int partition(int p, int r, Trump *A)
{
  int x, i, j;
  Trump temp;

  x = A[r].num;

  for(i = p-1, j = p; j < r; j++)
  {
    if(A[j].num <= x)
    {
      i++;

      temp = A[i];
      A[i] = A[j];
      A[j] = temp;
    }
  }
  temp = A[i+1];
  A[i+1] = A[r];
  A[r] = temp;

  return i + 1;
}


void Quicksort(Trump *A, int p, int r)
{
  int q;

  if(p < r)
  {
    q = partition(p, r, A);
    Quicksort(A, p, q-1);
    Quicksort(A, q+1, r);
  }
}


int main()
{
  int n, i;
  Trump Qui[100000];
  int f=0;
  scanf("%d", &n);
  for(i = 0; i < n; i++)
  {
    scanf(" %c %d", &Qui[i].ch, &Qui[i].num);

    Qui[i].sta = i;
  }

  Quicksort(Qui, 0, n-1);

  if(Stable(Qui, n-2) == 0)
  {
    printf("Stable\n");
  }

  else
  {
    printf("Not stable\n");
  }

  for(i = 0; i < n; i++)
  {
    printf("%c %d\n", Qui[i].ch, Qui[i].num);
  }

  return 0;
}

