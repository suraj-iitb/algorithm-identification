#include<stdio.h>

int main()
{
  int i, j, m, n, a;
	int A[10001];

	scanf("%d", &n);

	for (i=0; i<n; i++)
  {
		scanf("%d", &A[i]);
	}

	scanf("%d", &m);
	int e = 0;

	for (i=0; i<m; i++)
  {
		scanf("%d", &a);
		for (j=0; j<n; j++)
    {
			if (a == A[j])
      {
				e++;
				break;
			}
		}
	}

	printf("%d\n", e);

	return 0;
}

