#include <iostream>

using namespace std;

int main()
{
	const int MAXN = 100;
	int N, A[MAXN];
	cin >> N;

	for(int i = 0; i < N; i++) cin >> A[i];

	for(int i = 1; i <= N; i++) {
		for(int k = 0; k < N; k++) {
			cout << A[k];
			if(k != N-1) cout << " ";
			else cout << endl;
		}
		if(i == N) break;
		
		int tmp = A[i], j = i - 1;

		while(j >= 0 && A[j] > tmp) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = tmp;
	}

	return 0;
}
