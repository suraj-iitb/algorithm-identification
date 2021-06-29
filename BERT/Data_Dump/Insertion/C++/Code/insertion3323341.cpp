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
	int N,v,a;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	output(A, N);
	for (int i = 1; i < N; i++) {
		v = A[i];
		a = i - 1;
		while (a >= 0 && A[a] > v) {
			A[a+1] = A[a];
			a--;
		}
		A[a + 1] = v;
		output(A, N);
	}
	
}
