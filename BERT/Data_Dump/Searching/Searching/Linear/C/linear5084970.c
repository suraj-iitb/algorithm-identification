#include <stdio.h>
int binarySerch(int, int);
void sort(int);
int S[100000];
int main()
{
  int n, q, i, C, T[50000];

  scanf("%d", &n);
  for (i = 0; i <= n - 1; i++)
  {
    scanf("%d", &S[i]);
  }
  sort(n);
  scanf("%d", &q);
  for (i = 0; i <= q - 1; i++)
  {
    scanf("%d", &T[i]);
  }
  for (i = 0; i <= q - 1; i++)
  {
    /* code */
    C = binarySerch(n, T[i]);
  }
  printf("%d\n", C);
}

void sort(int n)
{
  int i, j, minj, v;
  for (i = 1; i <= n - 1; i++)
  {
    v = S[i];
    j = i - 1;
    while (j >= 0 && S[j] > v)
    {
      /* code */
      S[j + 1] = S[j];
      j--;
    }
    S[j + 1] = v;
  }
}

int binarySerch(int n, int key)
{
  int left = 0, right, mid;
  static int count = 0;
  right = n;
  while (left < right)
  {
    mid = (left + right) / 2;
    if (S[mid] == key)
    {
      count++;
      break;
    }
    if (key < S[mid])
    {
      right = mid;
    }
    else if (key > S[mid])
    {
      left = mid + 1;
    }
  }
  return count;
}
