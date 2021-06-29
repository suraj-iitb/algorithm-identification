#include <cstdio>
#include <cstdlib>
using namespace std;

int main() {
	int A[100];
	int n;
	int minj;
	int ch;
	
	scanf("%d", &n);
	for (int i = 0;i < n;i++) {
		scanf("%d", &A[i]);
	}

	ch = 0;
	for (int i = 0;i < n;i++) {
		minj = i;
		for (int j = i;j < n;j++) {
			if (A[j] < A[minj]) {
				minj = j;
			}
		}
		if (i != minj)ch++;
		int sub = A[i];
		A[i] = A[minj];
		A[minj] = sub;
	}

	for (int i = 0;i < n;i++) {
		printf("%d", A[i]);
		if (i + 1 < n)printf(" ");
		else printf("\n");
	}
	printf("%d\n", ch);

	return 0;
}
