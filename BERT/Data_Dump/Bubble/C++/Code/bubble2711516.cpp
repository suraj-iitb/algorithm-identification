#include <iostream>
#include <vector>


int main(int argc, char const *argv[]){

	int N;
	std::cin >> N;
	std::vector<int> fig(N);
	for (int i = 0; i < N; ++i){
		std::cin >> fig[i];
	}

	int num = 0;

	for (int i = 0; i < N; ++i){
		for (int j = N-1; j > i ; --j){
			if(fig[j]<fig[j-1]){
				int buff = fig[j];
				fig[j] = fig[j-1];
				fig[j-1] = buff;
				num += 1;
			}
		}
	}

	for (int i = 0; i < N; ++i){
		std::cout << fig[i];
		if(i<N-1) std::cout << " ";
	}
	std::cout << std::endl;
	std::cout << num << std::endl;

	return 0;
}
