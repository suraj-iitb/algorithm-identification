#include <algorithm>
#include <cmath>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#define ll long long
#define INF 1e9 + 1
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define REP(i, n) for (int i = 0; i < n; i++)
using namespace std;

int n, A[110], cnt = 0;

void print(int n, int A[]) {
    REP(i, n) {
        if (i) cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << cnt << endl;
}

void bubbleSort(int n, int A[]) {
    int flag = 1;
    while (flag) {
        flag = 0;
        for (int j = n - 1; j > 0; j--) {
            if (A[j] < A[j - 1]) {
                swap(A[j], A[j - 1]);
                flag = 1;
                cnt++;
            }
        }
    }
    print(n, A);
}

int main() {
    cin >> n;
    REP(i, n) cin >> A[i];
    bubbleSort(n, A);
}
