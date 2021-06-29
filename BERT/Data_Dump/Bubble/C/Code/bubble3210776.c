#include <stdio.h>

#define MAX 100

int n, a[MAX], cnt;

void bubbleSort()
{
	int i, tmp, flag;
	 
	flag = 1;
	cnt = 0;
	while (flag) {
		flag = 0;
		for (i = n - 1; i >= 1; i--) {
			if (a[i] < a[i - 1]) {
				tmp = a[i];
				a[i] = a[i - 1];
				a[i - 1] = tmp;
				flag = 1;
				cnt++;
			}
		}
	}
}

int main()
{
	int i;
	
	scanf("%d",&n);
	
	for (i = 0; i < n; i++) {
		 scanf ("%d",&a[i]);
	}
	bubbleSort();
	
	
	
	for (i = 0; i < n; i++) {
		if (i > 0) {
			printf(" ");
			}
		printf("%d",a[i]);
	}
	printf("\n");
	
	printf("%d\n",cnt);
return 0;
}
