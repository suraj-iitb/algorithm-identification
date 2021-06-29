
#include <iostream>
#include <algorithm>



using namespace std;
int C=0;

void bubbleSort(int A[],int N) {
	int flag = 1;
	while (flag) {
		flag = 0;
		for (int j = N-1;j>=1;j--) {
			if (A[j] < A[j - 1]) {
				swap(A[j], A[j - 1]);
				C++;
				flag = 1;
			}
		}
		
	}
}




int main()
{
	int N;
	int S[100];

	cin >> N;
	for (int i = 0;i < N;i++) {
		cin >> S[i];
	}

	bubbleSort(S, N);

	for (int i = 0;i < N-1;i++) {
		cout << S[i]<<" ";
	}

	cout << S[N-1] << endl;
	cout << C<< endl;

    return 0;
}
