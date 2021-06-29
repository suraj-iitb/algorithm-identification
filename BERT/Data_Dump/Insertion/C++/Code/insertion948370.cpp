#include<iostream>
#include<vector>

int main(){

	int n;
	std::cin >> n;
	std::vector<int>v(n);

	for (int i = 0; i < n; i++)std::cin >> v[i];

	for (int k = 0; k < n; k++){
		if (k == 0)std::cout << v[k];
		else std::cout << " " << v[k];
	}
	std::cout << std::endl;

	for (int i = 1; i < n; i++){
		int key = v[i];
		int j = i - 1;

		while (j >= 0 && v[j]>key){
			v[j + 1] = v[j];
			j--;
		}
		v[j + 1] = key;

		for (int k = 0; k < n; k++){
			if (k == 0)std::cout << v[k];
			else std::cout << " " << v[k];
		}
		std::cout << std::endl;
	}
	return 0;
}
