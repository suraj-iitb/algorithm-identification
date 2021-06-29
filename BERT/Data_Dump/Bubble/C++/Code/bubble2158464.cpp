#include <iostream>
#include <vector>
#include <algorithm>
#define INPUT_FROM_FILE (0)

#if INPUT_FROM_FILE
#include <fstream>
#endif

#if INPUT_FROM_FILE
#define IS ifs
#else
#define IS std::cin
#endif

int main(int argc, char **argv) {
#if INPUT_FROM_FILE
	std::ifstream ifs("test.txt");
#endif
	int n = 0;
	std::vector<int> v;
	int num_operations = 0;

	IS >> n;

	v.resize(n, 0);
	for(int i = 0; i < n; i++){
		IS >> v[i];
	}

	for(int i = 0; i < n; i++){
		for(int j = n - 1; j >= i + 1; j--){
			if(v[j] < v[j - 1]){
				std::swap(v[j], v[j - 1]);
				num_operations++;
			}
		}
	}

	for(int i = 0; i < n; i++){
		std::cout << v[i];
		if(i < n - 1){
			std::cout << " ";
		}
	}
	std::cout << std::endl;
	std::cout << num_operations << std::endl;

	return 0;
}
