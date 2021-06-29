#include <cstdio>
#include <cstdlib>
#define MAX 2000001
#define VMAX 10000
using namespace std;

int main()
{
	unsigned short *A, *B;
	int C[VMAX + 1], n, i, j;
	scanf("%d", &n);

	A = (unsigned short*)malloc(sizeof(unsigned int) * n + 1);
	B = (unsigned short*)malloc(sizeof(unsigned int) * n + 1);

	for (i = 0; i <= VMAX; i++)
		C[i] = 0;
	for (i = 0; i < n; i++) {
		scanf("%u", &A[i + 1]);
		C[A[i + 1]]++;
	}
	for (i = 1; i <= VMAX; i++)
		C[i] += C[i - 1];
	for (j = 1; j <= n; j++) {
		B[C[A[j]]] = A[j];
		C[A[j]]--;
	}
	for (i = 1; i <= n; i++) {
		if (i > 1)
			printf(" ");
		printf("%d", B[i]);
	}
	printf("\n");
	return 0;
}
