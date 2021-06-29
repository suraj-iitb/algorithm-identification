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
		int mini = i;
		for(int j = i; j < n; j++){
			if(a[j] < a[mini])
				mini = j;
		}
		if(mini != i){
			int temp = a[mini];
			a[mini] = a[i];
			a[i] = temp;
			count++;
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
