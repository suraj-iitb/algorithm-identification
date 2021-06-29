#include <iostream>
#include <vector>

int main(){
	int n;
	std::vector<int> a;
	std::cin >> n;
	for(int i = 0; i < n; i++){
		int t;
		std::cin >> t;
		a.push_back(t);
		std::cout << t;
		if(i == n - 1){
			std::cout << std::endl;
		} else {
			std::cout << ' ';
		}
	}
	for(int j = 1; j < n; j++){
		int key = a[j], i = j - 1;
		for(; i >= 0 && a[i] > key; i--){
			a[i+1] = a[i];
		}
		a[i+1] = key;
		for(int k = 0; k < n; k++){
			std::cout << a[k];
			if(k == n - 1){
				std::cout << std::endl;
			} else {
				std::cout << ' ';
			}
		}
	}
	return 0;
}
