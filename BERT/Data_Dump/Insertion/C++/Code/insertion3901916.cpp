#include <iostream>
#include <vector>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep1(i, s, n) for (int i = (s); i <= (n); i++)

int main()
{
	int N, v, j;
	cin >> N;
	vector<int> A(N);
	rep(i, N) cin >> A[i];

	rep(i, N - 1) cout << A[i] << " ";
	cout << A[N - 1] << endl;

	rep1(i, 1, N - 1) {
		v = A[i];
		j = i - 1;
		while (j >= 0 && A[j] > v) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = v;

		rep(i, N - 1) cout << A[i] << " ";
		cout << A[N - 1] << endl;
	}

	return 0;
}

