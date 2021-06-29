// AOL insersion sort

#include<iostream>

int main() {
	int n;
	int a[100],i,v,j,k;

	std::cin >> n;	//データ数入力

	//データ列の入力
	for (i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	for (i = 0; i < n; i++) {

		// sort
		v = a[i];
		j = i - 1;
		while ((j >= 0) && (a[j] > v)) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = v;
		// print
		for (k = 0; k < n-1; k++) {
			std::cout << a[k] << " ";
		}
		std::cout << a[k] << std::endl;

	}


}
