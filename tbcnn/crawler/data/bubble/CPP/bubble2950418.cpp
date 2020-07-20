#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
using namespace std;


int main() {

	int a[100];
	int size;
	int count = 0;

	cin >> size;

	for (int i = 0; i < size; i++) {
		cin >> a[i];
	}

	bool flg = true;
	int temp;
	do {
		flg = false;
		for (int i = size - 1; i >= 1; i--) {
			if (a[i] < a[i - 1]) {
				temp = a[i];
				a[i] = a[i - 1];
				a[i - 1] = temp;
				count++;
				flg = true;
			}
		}

	} while (flg);

	for (int i = 0; i < size; i++) {
		printf("%d", a[i]);
		if (i + 1 != size)printf(" ");
	}
	printf("\n%d\n", count);




//	system("pause");
	return 0;
}
