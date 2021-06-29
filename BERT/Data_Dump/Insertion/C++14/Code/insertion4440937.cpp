#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int> A);
void printVector(vector<int> A);

int main() {
	size_t N;
	cin >> N;

	vector<int> A(N);
	for(auto&& e : A) {
		cin >> e;
	}

	printVector(A);
	insertionSort(A);

	return 0;
}

void insertionSort(vector<int> A) {
	int i, j, v;

	for(i = 1; i < A.size(); ++i) {
		v = A[i];
		j = i - 1;

		while((0 <= j) && (v < A[j])) {
			A[j + 1] = A[j];
			--j;
		}

		A[j + 1] = v;

		printVector(A);
	}
}

void printVector(vector<int> A) {
	for(int i = 0; i < A.size(); ++i) {
		cout << A[i];
		if(A.size() - 1 > i) { cout << " "; }
		else{ cout << endl; }
	}
}
