#include <stdio.h>

int main(void)
{
	int n,i,j,k,s,count = 0;
	scanf("%d",&n);
	int array1[n],array2[n];
	for (i = 0;i < n;i++) {
		scanf("%d",&array1[i]);
		array2[i] = array1[i];
	}

	for (j = 0;j < n - 1 ;j++) {

		for (i = j + 1;i < n -1;i++)
			if(array1[i+1] > array1[i])
				array1[i+1] = array1[i];

		if (array2[j] > array1[n-1]) {
			for (i = j + 1;i < n;i++)
				if (array2[i] == array1[n-1])
					break;
			s = array2[j];
			array2[j] = array1[n-1];
			array2[i] = s;
			count++;
			for (i = j;i < n ;i++) 
				array1[i] = array2[i];
		} else {
			for (i = j + 1;i < n ;i++) 
				array1[i] = array2[i];
		}

	}
	
	for (i = 0;i < n;i++) {
		if (i == n -1)
			printf("%d\n",array2[i]);
		else printf("%d ",array2[i]);
	}
	printf("%d\n",count);
	return 0;
}
