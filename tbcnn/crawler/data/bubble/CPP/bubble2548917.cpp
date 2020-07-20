#include <iostream>
#include <algorithm>
using namespace std;

 int counter = 0;   //count???????´???????????????¨???

void bubbleSort(int A[], int N) {

	int flag = 1;
	int tmp;
	while (flag) {
		flag = 0;
		for(int j=N-1;j>=1;j--)
			if (A[j] < A[j - 1]) {
				tmp = A[j - 1];
				A[j - 1] = A[j];
				A[j] = tmp;
		     	flag = 1;
		     	counter++;
			}
	}
}

int main() {
	int A[100];
	int N;
	cin >> N;
	for (int i = 0;i < N;i++) cin >> A[i];

	bubbleSort(A, N);

	for (int i = 0;i < N;i++) {
		cout << A[i];
		if(i<N-1) cout<<' ';
	}
	cout<<'\n';
	cout<<counter<<endl;
	return 0;
}
