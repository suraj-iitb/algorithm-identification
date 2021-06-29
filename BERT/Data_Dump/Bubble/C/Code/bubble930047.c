#include <stdio.h>
#include <memory.h>

int bubble_sort(int lst[], int n);

int main(void) {
	int i, n;
	int lst[100];
	int count;
	memset((char*)lst, 0x00, sizeof(lst));

	scanf("%d\n", &n);
	for(i=0;i<n;i++) {
		scanf("%d", &lst[i]);
	}
	
	count = bubble_sort(lst, n);
	
	for(i=0;i<n;i++) {
		printf("%d", lst[i]);
		if(i<n-1) {
			printf(" ");
		} else {
			printf("\n");
		}
	}
	printf("%d\n", count);
	
	return 0;
}

int bubble_sort(int lst[], int n) {
	int i, j, tmp, count;
	for(i=0,count=0;i<n-1;i++) {
		for(j=n-1;j>i;j--) {
			if(lst[j-1] > lst[j]) {
				tmp = lst[j];
				lst[j] = lst[j-1];
				lst[j-1] = tmp;
				count++;
			}
		}
	}
	
	return count;
}
