#include <iostream>
#include <vector>

std::vector<int> insertionSort(std::vector<int>,int);

int main(int argc, char const *argv[]){

	int N;
	std::cin >> N;
	std::vector<int> fig(N);

	for (int i = 0; i < N; ++i){
		std::cin >> fig[i];
	}

	for (int i=0; i<N; ++i){
		std::cout << fig[i];
		if(i<N-1)std::cout << " ";
	}
	std::cout << std::endl;

	std::vector<int> ans = insertionSort(fig,N);
	return 0;
}

std::vector<int> insertionSort(std::vector<int> fig, int N){

	for (int i = 1; i < N; ++i){
		int buff = fig[i];
		int j=i-1;
		while( j>=0 && fig[j]>buff ){
			fig[j+1] = fig[j];
			j -= 1;
		}
		fig[j+1] = buff;

		for (int k=0; k<N; ++k){
			std::cout << fig[k];
			if(k<N-1)std::cout << " ";
		}
		std::cout << std::endl;
	}
	return fig;
}
