#include <stdio.h>

int main(void)
{
	int n,i,j,s,count = 0;
	scanf("%d",&n);
	int array[n];
	for (i = 0;i < n;i++)
		scanf("%d",&array[i]);

	for (j = 0;j < n ;j++) {
		for (i = 0;i < n -1;i++) {
			if (array[i+1] < array[i]) {
				s = array[i+1];
				array[i+1] = array[i];
				array[i] = s;
				count++;
			}
		}

	}
	
	for (i = 0;i < n;i++) {
		if (i == n -1)
			printf("%d\n",array[i]);
		else printf("%d ",array[i]);
	}
	printf("%d\n",count);
	return 0;
}

