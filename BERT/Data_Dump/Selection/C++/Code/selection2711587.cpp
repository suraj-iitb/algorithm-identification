#include <iostream>
#include <vector>

int main(int argc, char const *argv[]){
	
	int N;
	int num = 0;
	std::cin >> N;
	std::vector<int> fig(N);

	for (int i = 0; i < N; ++i){
		std::cin >> fig[i];
	}

	for (int i = 0; i < N; ++i){
		int minj = i;
		for (int j = i; j < N; ++j){
			if(fig[j]<fig[minj]){
				minj = j;
			}
		}
		if(i!=minj){
			int buff = fig[i];
			fig[i] = fig[minj];
			fig[minj] = buff;
			num += 1;
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
