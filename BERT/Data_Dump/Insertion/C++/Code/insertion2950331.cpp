#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>



int main() {

	int size;

	std::cin >> size;

	int a[100];

	for (int i = 0; i < size; i++) {
		std::cin >> a[i];
	}

	//初期書き出し
	for (int i = 0; i < size; i++) {
		printf("%d", a[i]);
		if (i + 1 != size)printf(" ");
	}
	printf("\n");
	//初期書き出し終わり

	int temp;
	for (int i = 1; i < size; i++) {
		for (int j = i; j > 0; j--) {
			if (a[j] < a[j - 1]) {
				temp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp;
			}else {
				break;
			}
		}

		//書き出し
		for (int i = 0; i < size; i++) {
			printf("%d", a[i]);
			if (i + 1 != size)printf(" ");
		}
		printf("\n");
		//書き出し終わり
	}


	//system("pause");
	return 0;
}
