#include <bits/stdc++.h>
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
const double PI = 3.141592653589793;
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

void printArr(int A[], int N) {
    for (int i = 0; i < N; i++) {
        if (i) cout << " ";
        cout << A[i];
    }
    cout << endl;
}

int bubbleSort (int A[], int N) {
    int cnt = 0;
    bool flag = true;
    while (flag) {
        flag = false;
        for (int j = N - 1; j >= 1; j--) {
            if (A[j] < A[j - 1]) {
                swap(A[j], A[j - 1]);
                cnt++;
                flag = true;
            }
        }
    }
    return cnt;
}

int main() {
    int N, A[110], cnt;
    cin >> N;
    rep(i, N) cin >> A[i];
    cnt = bubbleSort(A, N);
    printArr(A, N);
    cout << cnt << endl;
}

