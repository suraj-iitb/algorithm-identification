#include <iostream>
#include <vector>
#include <string>
using namespace std;

void selection(int , int[]);

int main() {
	
	int N;
	cin >> N;
	int *A = new int[N];
	for (int i = 0; i < N; i++) cin >> A[i];
	
	selection(N,A);

	return 0;
}

void selection(int N,int A[]) {
	int ans = 0;
	for (int i = 0; i < N; i++) {
		int mini = i;
		for (int j = i; j < N; j++) {
			if (A[j] < A[mini])
				mini = j;
		}
		if(A[i] != A[mini]) ans++;
		int t = A[i];
		A[i] = A[mini];
		A[mini] = t;
	}
	for (int i = 0; i < N - 1; i++) cout << A[i] << ' ';
	cout << A[N - 1] << '\n';
	cout << ans << '\n';
}

//made by myself
