#include <iostream>
#include <string>
#include <vector>
#include <cassert>

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REPEAT(i, n) FOR(i, 0, n)
#define DECFOR(i, a, b) for (int i = (a); (b) < i; --i)

using namespace std;

void c_3_4() {
	int n;
	int minj;
	int count;

	cin >> n;
	vector<int> a(n);
	REPEAT(i, n) {
		cin >> a[i];
	}

	count = 0;
	FOR(i, 0, n) {
		minj = i;
		FOR(j, i + 1, n) {
			if (a[j] >= a[minj]) {
				continue;
			}
			minj = j;
		}
		if (minj == i) {
			continue;
		}
		swap(a[i], a[minj]);
		++count;
	}

	REPEAT(k, a.size())
	{
		cout << (k ? " " : "") << a[k];
	}
	cout << endl;
	cout << count << endl;
}

int main() {
	ios::sync_with_stdio(false);
	c_3_4();
	return 0;
}

