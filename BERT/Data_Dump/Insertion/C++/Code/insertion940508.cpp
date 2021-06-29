#include<iostream>
#include<vector>

int main(){
	int n;
	std::cin >> n;
	std::vector<int> A(n);
	for (int i = 0; i < n; ++i) std::cin >> A[i];
	for (int i = 1; i < n; ++i){
		for (int k = 0; k < n; ++k){
			if (k != n - 1)std::cout << A[k] << ' ';
			else std::cout << A[k] << std::endl;
		}
		int key = A[i];
		int j = i - 1;
		while (j >= 0 && A[j]>key){
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = key;
	}
	for (int k = 0; k < n; ++k){
		if (k != n - 1)std::cout << A[k] << ' ';
		else std::cout << A[k] << std::endl;
	}
	return 0;
}
