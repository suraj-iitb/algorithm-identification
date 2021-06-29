#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep1(i, s, n) for (int i = (s); i <= (n); i++)
#define rrep(i, n) for (int i = (n) - 1; i >= 0; i--)
#define print_array(ary, size) cout << ary[0]; rep1(i, 1, size - 1) cout << ' ' << ary[i]; cout << endl;
typedef long long ll;
typedef unsigned long long ull;

int n;
int A[2000000];
int B[2000000];
int C[10001] = { 0 };

void CountingSort(int* A, int* B, int k)
{
	rep(i, k) C[i] = 0;
	rep(i, n) C[A[i]]++;
	rep(i, k - 1) C[i + 1] += C[i];
	rrep(i, n) {
		B[C[A[i]] - 1] = A[i];
		C[A[i]]--;
	}
}

int main()
{
	cin >> n;
	rep(i, n) cin >> A[i];
	CountingSort(A, B, 10001);
	print_array(B, n);

	return 0;
}
