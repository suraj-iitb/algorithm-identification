#include <stdio.h>
#include <stdlib.h>


int *WORK;
int compare_count = 0;

int n;

void Merge_sort(int *S, int low, int high)
{
	int mid;
	int i, j, k;


	if(high <= low)
		return;

	mid = (low + high) / 2;

	// 左側の処理
	Merge_sort(S, low, mid);

	// 右側の処理
	Merge_sort(S, mid + 1, high);

	for(i = low; i <= mid; i++)
		WORK[i] = S[i];

	for(i = high, j = mid + 1; i > mid; i--, j++)
		WORK[i] = S[j];

	// マージ
	i = low;
	j = high;
	for(k = low; k <= high; k++){
		if(WORK[i] <= WORK[j])
			S[k] = WORK[i++];
		else
			S[k] = WORK[j--];
		compare_count++;
	}
}


int main()
{
	int *S;
	int i;


	scanf("%d", &n);

	S = (int *)malloc(sizeof(int) * n);
	WORK = (int *)malloc(sizeof(int) * n);

	for(i = 0; i < n; i++)
		scanf("%d", &S[i]);


	Merge_sort(S, 0, n - 1);


	for(i = 0; i < n; i++){
		printf("%d", S[i]);
		if(i != n - 1)
			printf(" ");
		else
			printf("\n");
	}
	printf("%d\n", compare_count);


	return 0;
}
