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
	
	count = selection_sort(lst, n);
	
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

int selection_sort(int lst[], int n) {
	int i, j, tmp, count, index;
	for(i=0,count=0;i<n-1;i++) {
		index = i;
		for(j=i+1;j<n;j++) {
			if(lst[j] < lst[index]) {
				index = j;
			}
		}
		
		if(index != i) {
			tmp = lst[i];
			lst[i] = lst[index];
			lst[index] = tmp;
			count++;
		}
	}
	
	return count;
}
