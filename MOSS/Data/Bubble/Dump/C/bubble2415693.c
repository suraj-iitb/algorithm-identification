#include<stdio.h>
void bubble(int *ar, int len) {
	int i, j,temp,cou=0;
	for (i = len - 1; i > 0; i--)
	{
		for (j = 0; j < i;j++)
		{
			if (*(ar + j + 1) < *(ar + j))
			{
				temp = *(ar + j + 1);
				*(ar + j + 1) = *(ar + j);
				*(ar + j) = temp;
				cou++;
			}
		}
	}
	for (i = 0; i < len-1; i++)
	{
		printf("%d ", *(ar + i));
	}
	printf("%d\n%d\n", *(ar + i),cou);

}

int main() {
	int N;
	int ar[100];
	int i;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%d", &ar[i]);
	}
	bubble(ar, N);
	return 0;
}
