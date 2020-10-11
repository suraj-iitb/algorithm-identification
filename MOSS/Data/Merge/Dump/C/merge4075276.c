#include<stdio.h>

#define MAX 500000
#define SIZE 1000000001

int cnt = 0;
int array [MAX];
int LEFT [MAX], RIGHT [MAX];

int main() {
	int number;
	scanf("%d", &number);
	for (int i = 0; i < number; i++) {
		scanf("%d", &array[i]);
	}
	mergeSort(array, 0, number);

	for (int i = 0; i < number; i++) {
		printf("%d", array[i]);
		if (i != number - 1)printf(" ");
	}
	printf("\n%d\n", cnt);
	return 0;
}

void merge(int array[], int left, int mid, int right) {
	int num1 = mid - left;
	int num2 = right - mid;
	int I, J;
	for (int i = 0; i < num1; i++) {
		LEFT[i] = array[left + i];
	}
	for (int i = 0; i < num2; i++) {
		RIGHT[i] = array[mid + i];
	}
	LEFT[num1] = SIZE; RIGHT[num2] = SIZE;
	I = 0; J = 0;
	for (int k = left; k < right; k++) {
		if (LEFT[I] <= RIGHT[J]) {
			array[k] = LEFT[I];
			I++;
			cnt++;
		}
		else {
			array[k] = RIGHT[J];
			J++;
			cnt++;
		}
	}
}

void mergeSort(int array[], int left, int right) {
	if (left + 1 == right)return;
	int mid = (left + right) / 2;
	mergeSort(array, left, mid);
	mergeSort(array, mid, right);
	merge(array, left, mid, right);
}


