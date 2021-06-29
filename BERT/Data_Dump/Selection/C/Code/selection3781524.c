
#include <stdio.h>

int main(void)
{
	int n;
	scanf("%d", &n);

	int i;
	int a[n];
	for(i = 0; i < n; i++){
		scanf("%d^%c", &a[i]);
	}

	int minj, j, buf, cnt = 0;
	for(i = 0; i <= n - 1; i++){
		minj = i;
		for(j = i; j <= n - 1; j++){
			if(a[j] < a[minj]){
				minj = j;
			}
		}
		if(i != minj){
			buf = a[i];
			a[i] = a[minj];
			a[minj] = buf;
			cnt++;
		}
	}

	for(i = 0; i < n - 1; i++){
		printf("%d ", a[i]);
	}
	printf("%d\n", a[n - 1]);
	printf("%d\n", cnt);
	
	return 0;
}

