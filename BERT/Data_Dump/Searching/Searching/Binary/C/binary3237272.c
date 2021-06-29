#include <stdio.h>
int binarySearch(int key, int numa, int a[]) {
	int left = 0;
	int right = numa;
	int mid;

	while (left < right) {
		mid = (left + right) / 2;
		if (a[mid] == key) {
			return 1;
		}
		if (key > a[mid]) {
			left = mid + 1;
		}
		else if (key < a[mid]) {
			right = mid;
		}
	}

	return 0;

}

int main(void)
{
	int num = 0, numa, numb, key, i, left, right;
	int a[100000];

	scanf("%d", &numa);

	for (i = 0; i < numa; i++) {
		scanf("%d", &a[i]);
	}

	scanf("%d", &numb);
	
	for (i = 0; i < numb; i++) {
		scanf("%d", &key);
		if (binarySearch(key, numa, a)) {
			num++;
		}
		
	}
	printf("%d\n", num);
	
	return 0;
}
