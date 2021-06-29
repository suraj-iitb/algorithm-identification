#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
using namespace std;


int main() {

	int size;
	int a[100];
	int count = 0;

	cin >> size;

	for (int i = 0; i < size; i++) {
		cin >> a[i];
	}


	int min;
	int index;
	int temp;
	for (int i = 0; i < size - 1; i++) {
		min = a[i];
		index = i;
		for (int j = i; j < size; j++) {
			if (min > a[j]) {
				index = j;
				min = a[j];
			}
		}
		if (i != index) {
			count++;
			temp = a[i];
			a[i] = a[index];
			a[index] = temp;
		}
	}

	for (int i = 0; i < size; i++) {
		printf("%d", a[i]);
		if (i + 1 != size)printf(" ");
	}
	printf("\n%d\n", count);


//	system("pause");
	return 0;
}
