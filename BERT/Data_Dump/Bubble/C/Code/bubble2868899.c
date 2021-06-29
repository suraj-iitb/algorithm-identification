#include<stdio.h>

int bubbleSort(int n, int *a)
{
	int count = 0;
	int flag = 1;
	int i, temp;
	while(flag) {
		flag = 0;
		for(i=n-1;i>0;i--) {
			if(a[i] < a[i-1]) {
				temp = a[i];
				a[i] = a[i-1];
				a[i-1] = temp;
				flag = 1;
				count++;
			}
		}
	}
	return count;
}

void print_array(int n, int *a)
{
	int i;
	for(i=0;i<n;i++) {
		if(i > 0) printf(" ");
		printf("%d", a[i]);
	}
	printf("\n");
}

int main(void)
{
	int n, a[100], i, count;
	scanf("%d", &n);
	for(i=0;i<n;i++) {
		scanf("%d", &a[i]);
	}
    count = bubbleSort(n, a);
    print_array(n, a);
    printf("%d\n", count);
    return 0;
}
	
