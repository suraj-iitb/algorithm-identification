#include <iostream>
using namespace std;

void bubbleSort(int *A,int N);

int main()
{
	int N;
	cin >> N;
	int A[N];
	for (int i = 0; i < N; i++)
		cin >> A[i];

	bubbleSort(A,N);

	return 0;
}

void bubbleSort(int *A,int N)
{
	bool flag = true;
	int count = 0;

	while(flag) {
		flag = false;
		for (int i = N-1; i >= 1; i--) {
			if (A[i] < A[i-1]) {
				swap(A[i],A[i-1]);
				flag = true;
				count++;
			}
		}
	}
	
	for(int i = 0; i < N; i++) {
		cout << A[i];
		if (i == N-1)
			cout << '\n';
		else
			cout << ' ';
	}

	cout << count << '\n';
	return;
}
