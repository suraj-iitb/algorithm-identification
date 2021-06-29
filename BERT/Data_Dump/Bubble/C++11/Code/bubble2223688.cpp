#include<iostream>
using namespace std;

static const int MAX = 100;

int bubbleSort(int A[MAX], int N){
	
	bool flag = true;
	int cnt = 0;
	while (flag){
		flag = false;
		for (int j = N - 1; j >= 1; j--){
			if (A[j] < A[j - 1]){
				int tmp = A[j];
				A[j] = A[j - 1];
				A[j - 1] = tmp;
				flag = true;
				cnt++;
			}
		}
	}
	return cnt;	
}

int main()
{
	int N;
	int A[MAX];
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> A[i];
	}
	int cnt = bubbleSort(A,N);
	for (int i = 0; i < N; i++){
		cout  << A[i];
		if (i + 1 < N){
			cout << " ";
		}
	}
	cout << endl;
	cout << cnt;
	cout << endl;


	return 0;
}
