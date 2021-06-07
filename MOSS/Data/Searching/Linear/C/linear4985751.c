#include <stdio.h>
#include <ctype.h>

int S[10000];
int T[500];

int cc;


int readInt(void)
{
  int n;
  
  while (isspace(cc))
    cc = getchar();
  if (isdigit(cc)) {
    n = 0;
    do {
      n = 10*n + cc-'0';
    } while (isdigit(cc = getchar()));
    return n;
  }
  return -1;
}

void fill(int a[], int n)
{
  int i;

  for (i = 0; i < n; i++)
    a[i] = readInt();
}

int main(void)
{
  int n, q;
  int i, j;
  int cnt;

  cc = getchar();
  
  n = readInt();
  fill(S, n);

  q = readInt();
  fill(T, q);

  cnt = 0;
  for (i = 0; i < q; i++)
    for (j = 0; j < n; j++)
      if (S[j] == T[i]) {
	cnt++;
	break;
      }

  printf("%d\n", cnt);
  
  return 0;
}

