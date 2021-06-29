// BubbleSort
// 入力：
//	数列の要素数 n　と　数列
// 出力：
//  昇順でソート後の数列と試行回数

#include<iostream>

int main() {
	int i, j, n, v,a[100],c=0,tmp;

	std::cin >> n;

	// Input
	for (i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	// Sorting
	for (j = 0; j < n-1; j++) {
		for (i = n-1; i > j; i--) {
			if (a[i] < a[i - 1]) {
				tmp = a[i];
				a[i] = a[i - 1];
				a[i - 1] = tmp;
				c++;
			}
		}
	}

	for (i = 0; i < n; i++) {
		std::cout << a[i];
		if (i != n - 1) {
			std::cout << " ";
		}
	}

	std::cout << std::endl;

	std::cout << c << std::endl;

	return 0;
	}


