#include <iostream>
#include <vector>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n) - 1; i >= 0; i--)
#define rep1(i, s, n) for (int i = (s); i <= (n); i++)
#define rrep1(i, s, n) for (int i = (s); i >= (n); i--)

int main()
{
	int N, mini, swap = 0, tmp;

	cin >> N;
	vector<int> A(N);
	rep(i, N) cin >> A[i];

	rep(i, N) {
		mini = i;
		rep1(j, i, N - 1) {
			if (A[j] < A[mini]) mini = j;
		}
		if (i != mini) swap++;
		tmp = A[i];
		A[i] = A[mini];
		A[mini] = tmp;
	}

	rep(i, N - 1) cout << A[i] << " ";
	cout << A[N - 1] << endl;
	cout << swap << endl;

	return 0;
}

