#include <iostream>
#include <vector>
#define INPUT_FROM_FILE (0)

#if INPUT_FROM_FILE
#include <fstream>
#endif

int main(int argc, char **argv) {
#if INPUT_FROM_FILE
	std::ifstream ifs("test.txt");
#endif
	int n = 0;
	std::vector<int> v;

#if INPUT_FROM_FILE
	ifs >> n;
#else
	std::cin >> n;
#endif

	v.resize(n, 0);
	for(int i = 0; i < n; i++){
#if INPUT_FROM_FILE
		ifs >> v[i];
#else
		std::cin >> v[i];
#endif
	}

	for(unsigned int j = 0; j < v.size(); j++){
		std::cout << v[j];
		if(j < v.size() - 1){
			std::cout << " ";
		}
	}
	std::cout << std::endl;
	for(unsigned int i = 1; i < v.size(); i++){
		int key = v[i];
		int j = i - 1;
		while(j >= 0 && v[j] > key){
			v[j + 1] = v[j];
			j--;
		}
		v[j + 1] = key;

		for(unsigned int j = 0; j < v.size(); j++){
			std::cout << v[j];
			if(j < v.size() - 1){
				std::cout << " ";
			}
		}
		std::cout << std::endl;
	}
	return 0;
}
