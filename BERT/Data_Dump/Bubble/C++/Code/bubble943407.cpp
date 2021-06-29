#include<iostream>
#include<vector>

int main(){
	int n;
	std::cin >> n;
	std::vector<int> num(n);
	for (int i = 0; i < n; ++i)std::cin >> num[i];
	int cnt = 0;
	for (int i = 0; i < n; ++i){
		for (int j = n - 1; j >= i+1; --j){
			if (num[j] < num[j - 1]){
				std::swap(num[j], num[j - 1]);
				cnt++;
			}
		}
	}
	for (int i = 0; i < n; ++i){
		std::cout << num[i];
		if (i < n - 1)std::cout << ' ';
	}
	std::cout << std::endl;
	std::cout << cnt << std::endl;
	return 0;
}
