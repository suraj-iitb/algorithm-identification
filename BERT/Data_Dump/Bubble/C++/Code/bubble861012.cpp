#include <iostream>
#include <vector>

int main(){
	int n;
	std::vector<int> a;
	std::cin >> n;
	for(int i = 0; i < n; i++){
		int temp;
		std::cin >> temp;
		a.push_back(temp);
	}
	
	int count = 0;
	for(int i = 0; i < n; i++){
		for(int j = n - 1; j > i; j--){
			if(a[j] < a[j-1]){
				int temp = a[j];
				a[j] = a[j-1];
				a[j-1] = temp;
				count++;
			}
		}
	}
	
	for(int i = 0; i < n; i++){
		std::cout << a[i];
		if(i == n - 1)
			std::cout << std::endl;
		else
			std::cout << ' ';
	}
	std::cout << count << std::endl;
	return 0;
}
