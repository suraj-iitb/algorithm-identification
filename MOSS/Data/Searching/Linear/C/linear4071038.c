#include <stdio.h>
#include <stdlib.h>


int main()
{
	int *S, n;
	int *T, q;
	int count;
	int i, j;


	scanf("%d", &n);
	S = (int *)malloc(sizeof(int) * n);
	for(i = 0; i < n; i++)
		scanf("%d", &S[i]);

	scanf("%d", &q);
	T = (int *)malloc(sizeof(int) * q);
	for(i = 0; i < q; i++)
		scanf("%d", &T[i]);


	count = 0;
	for(i = 0; i < q; i++){
		for(j = 0; j < n; j++){
			if(T[i] == S[j]){
				count++;
				break;
			}
		}
	}


	printf("%d\n", count);

	return 0;
}
