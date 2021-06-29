#include<iostream>
using namespace std;

int BubbleSort(int *A,int N)
{
	//ソートカウント
	int count = 0;

	for (int j = N - 1; j > 0; j--) {
		for (int i = 0; i < j; i++) {
			if (A[i] > A[i + 1]) {
				std::swap(A[i], A[i + 1]);
				count++;
			}
		}
	}
	
	return count;
}


int main()
{
	int N, A[100];
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	int count = BubbleSort(A,N);

	for (int i = 0; i < N; i++) {
		cout << A[i];
		if (i == N - 1) {
			cout << endl;
		}
		else {
			cout << " ";
		}
	}
	cout << count << endl;
	return 0;
}
