#include<iostream>
using namespace std;

int bubbleSort(int A[], int N) {

	int count=0, flag,j,i=0;
	flag = 1;
	while (flag) {
		flag = 0;
		for (j = N - 1; j >= i + 1; j--) {
			if (A[j] < A[j - 1]) {
				swap(A[j], A[j - 1]);
				flag = 1;
				count++;
				
			}
		}
		i++;
	}
	return count;
}
int main() {

	int A[100];
	int N, i, count;

	cin >> N;
	for (i = 0; i < N; i++)
		cin >> A[i];
	count = bubbleSort(A, N);

	cout << A[0];
	for (i = 1; i < N; i++) cout <<" "<< A[i];
	cout << endl;
	cout << count << endl;


}
