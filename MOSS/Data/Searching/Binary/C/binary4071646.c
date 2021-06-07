#include <stdio.h>
#include <stdlib.h>


int main()
{
	int *S, n;
	int *T, q;
	int left, right, center, num;
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
		left = 0;
		right = n - 1;
		while(left <= right){
			center = (left + right) / 2;
			num = S[center];
			if(T[i] == num){
				count++;
				break;
			}else if(T[i] < num)
				right = center - 1;
			else if(num < T[i])
				left = center + 1;
		}
	}

	printf("%d\n", count);

	return 0;
}
