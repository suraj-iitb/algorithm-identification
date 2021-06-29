#define _USE_MATH_DEFINES
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <numeric>
#include <functional>
#include <cctype>
#include <list>
#include <limits>
#include <cassert>
#include <random>
#include <time.h>
#include <unordered_set>

using namespace std;
using Int = long long;

constexpr double EPS = 1e-10;
constexpr long long MOD = 1000000007;

long long mod_pow(long long x, long long n) {
    long long res = 1;
    for (int i = 0;i < 60; i++) {
        if (n >> i & 1) res = res * x % MOD;
        x = x * x % MOD;
    }
    return res;
}

long long my_mod_pow(long long x, long long n) {
	long long ret = 1;
	for (; n > 0; n >>= 1, x = x * x % MOD) {
		if (n & 1) {
			ret = ret * x % MOD;
		}
	}
	return ret;
}

template<typename T>
T gcd(T a, T b) {
    return b != 0 ? gcd(b, a % b) : a;
}

template<typename T>
T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

void fastInput() {
    cin.tie(0);
    ios::sync_with_stdio(false);
}

void insertionSort(vector<int> &A, int l, int r) {

    for (int i = l+1; i < r; i++) {
        for (int k = l; k < r; k++) {
            if (k != r-1) cout << A[k] << " ";
            else cout << A[k];
        }
        cout << endl;

        int j;
        int v = A[i];
        for (j = i-1; j >= l && A[j] > v; j--) {
            A[j+1] = A[j];
        }
        A[j+1] = v;
    }
}

int select(vector<int> &A, int k) {

}

int main(void) {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    insertionSort(A, 0, N);

    for (int i = 0; i < N; i++) {
        if (i != N-1) cout << A[i] << " ";
        else cout << A[i];
    }
    cout << endl;
}

