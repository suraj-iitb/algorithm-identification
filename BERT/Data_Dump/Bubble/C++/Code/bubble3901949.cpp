#include <iostream>
#include <vector>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n) - 1; i >= 0; i--)
#define rep1(i, s, n) for (int i = (s); i <= (n); i++)
#define rrep1(i, s, n) for (int i = (s); i >= (n); i--)

int main()
{
	int N, tmp, swap = 0;


	cin >> N;
	vector<int> A(N);
	rep(i, N) cin >> A[i];

	rep(i, N) {
		rrep1(j, N - 1, i + 1) {
			if (A[j] < A[j - 1]) {
				swap++;
				tmp = A[j];
				A[j] = A[j - 1];
				A[j - 1] = tmp;
			}
		}
	}

	rep(i, N - 1) cout << A[i] << " ";
	cout << A[N - 1] << endl;
	cout << swap << endl;

	return 0;
}

