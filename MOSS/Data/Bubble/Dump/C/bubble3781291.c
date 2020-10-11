
#include <stdio.h>

int bubbleSort(int *a, int n);

int main(void)
{
	int n;
	scanf("%d", &n);

	int i;
	int a[n], cnt = 0;
	for(i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	cnt = bubbleSort(a, n);
	for(i = 0; i < n - 1; i++){
		printf("%d ", a[i]);
	}
	printf("%d\n", a[n - 1]);
	printf("%d\n", cnt);
	return 0;
}

int bubbleSort(int *a, int n)
{
	int flg = 1;
	int cnt = 0;
	int j, buf;
	while(flg){
		flg = 0;
		for(j = n - 1; j > 0; j--){
			if(a[j] < a[j - 1]){
				buf = a[j];
				a[j] = a[j - 1];
				a[j - 1] = buf;
				flg = 1;
				cnt++;
			}
		}
	}
	return cnt;
}


