#include<iostream> 
#include<string>
#include<algorithm>
using namespace std;
int A[100];
void output(int a[],int N) {
	cout << a[0];
	for (int i = 1; i < N; i++) {
		cout << " " << a[i];
	}
	cout << endl;
}
int main()
{
	int N,v;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	v = 0;
	for (int i = 0; i < N; i++) {
		for (int j = N-1; j >0; j--) {
			if (A[j] < A[j - 1]) {
				int temp = A[j];
				A[j] = A[j - 1];
				A[j - 1] = temp;
				v++;
			}
		}
	}
	cout << A[0];
	for (int i = 1; i < N; i++) {
		cout<<" "<< A[i];
	}
	cout << endl;
	cout << v << endl;
}
