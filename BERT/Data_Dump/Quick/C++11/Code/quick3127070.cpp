#include <iostream>
#include <vector>
#include <algorithm>

#define INPUT_FROM_FILE (0)
#if INPUT_FROM_FILE
#include <fstream>
#endif

class Card{
public:
	char suit;
	int number;
	int input_order;
};

int partition(std::vector<Card> &A, int p, int r){
	int x = A[r].number;
	int i = p - 1;
	
	for(int j = p; j < r; j++){
		if(A[j].number <= x){
			i++;
			std::swap(A[i], A[j]);
		}
	}
	std::swap(A[i + 1], A[r]);
	return i + 1;
}

void quick_sort(std::vector<Card> &A, int p, int r){
	if(p < r){
		int q = partition(A, p, r);
		quick_sort(A, p, q - 1);
		quick_sort(A, q + 1, r);
	}
	return;
}

int main(int argc, char **argv){
#if INPUT_FROM_FILE
	std::ifstream ifs("test.txt");
#endif
	int n = 0;
	std::vector<Card> A;
	char suit = 0;
	int m = 0;

#if INPUT_FROM_FILE
	ifs >> n;
#else
	std::cin >> n;
#endif

	A.resize(n);
	for(int i = 0; i < n; i++){
#if INPUT_FROM_FILE
		ifs >> suit >> m;
#else
		std::cin >> suit >> m;
#endif
		A[i].suit = suit;
		A[i].number = m;
		A[i].input_order = i;
	}


	quick_sort(A, 0, n - 1);



	bool is_stable = true;

	for(int i = 1; i < A.size(); i++){
		if(A[i - 1].number == A[i].number && A[i - 1].input_order > A[i].input_order){
			is_stable = false;
			break;
		}
	}

	if(is_stable){
		std::cout << "Stable" << std::endl;
	}
	else{
		std::cout << "Not stable" << std::endl;
	}
	for(unsigned int i = 0; i < A.size(); i++){
		std::cout << A[i].suit << " " << A[i].number << std::endl;
	}
	return 0;
}
