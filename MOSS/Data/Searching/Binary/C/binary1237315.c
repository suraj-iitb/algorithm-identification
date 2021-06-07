#include <stdio.h>

int main(void)
{
	int n, q, count;
	int S[100000], T[50000];
	int pl, pr, pc;
	int i;


	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &S[i]);
	
	scanf("%d", &q);
	for (i = 0; i < q; i++)
		scanf("%d", &T[i]);

	count = 0;
	for (i = 0; i < q; i++){
		pl = 0;
		pr = n - 1;
		do {
			pc = (pl + pr) / 2;
			if (S[pc] == T[i]){
				count++;
				break;
			}
			else if (S[pc] < T[i])
				pl = pc + 1;
			else
				pr = pc - 1;
		} while (pl <= pr);
	}

	printf("%d\n", count);

	return 0;
}
