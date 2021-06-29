#include<iostream>
using namespace std;

void output(int M[], int N) {
	for (int i = 0; i < N-1; i++) {
		cout << M[i] << " ";
	}
	cout << M[N - 1] << endl;
}

void Sort(int M[], int N) {
	for (int i = 1; i < N; i++) {
		int v = M[i];
		int j = i - 1;
		while (j >= 0 && M[j] > v) {
			M[j + 1] = M[j];
			j -= 1;
		}
		M[j + 1] = v;
		output(M, N);
	}
}

int main() {
	int N, M[100];
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> M[i];
	}
	output(M, N);
	Sort(M, N);
	return 0;

}
