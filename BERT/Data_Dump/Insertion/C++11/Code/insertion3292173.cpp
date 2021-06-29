#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, A; cin >> N;
	vector<int> array;

	for (int i = 0; i < N; ++i) {
		cin >> A;
		array.push_back(A);
	}

	for (int i = 0; i < N; ++i)
		cout << array[i] << ((i == N - 1) ? "\n" : " ");

	for (int i = 1; i < N; ++i) {
		int v = array[i];
		int j = i - 1;
		while (j >= 0 and array[j] > v)
		{
			array[j + 1] = array[j];
			--j;
		}
		array[j + 1] = v;
		for (int i = 0; i < N; ++i)
			cout << array[i] << ((i == N - 1) ? "\n" : " ");
	}
}
