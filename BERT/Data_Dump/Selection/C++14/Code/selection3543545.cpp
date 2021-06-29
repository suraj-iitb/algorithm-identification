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

void selectionSort(int n, int A[]) {
    for (int i = 0; i < n; i++) {
        int minj = i;
        for (int j = i; j < n; j++) {
            if (A[j] < A[minj]) {
                minj = j;
            }
        }
        if (i != minj) {
            swap(A[i], A[minj]);
            cnt++;
        }
    }
    print(n, A);
}

int main() {
    cin >> n;
    REP(i, n) cin >> A[i];
    selectionSort(n, A);
}
