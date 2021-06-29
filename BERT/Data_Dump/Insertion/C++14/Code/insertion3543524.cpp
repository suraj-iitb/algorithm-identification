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

int n, A[110];
int i, j, v;

void print(int n, int A[]) {
    REP(i, n) {
        if (i) cout << " ";
        cout << A[i];
    }
    cout << endl;
}

void insertionSort(int n, int A[]) {
    for (i = 1; i < n; i++) {
        v = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > v) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;
        print(n, A);
    }
}

int main() {
    cin >> n;
    REP(i, n) cin >> A[i];
    print(n, A);
    insertionSort(n, A);
}
