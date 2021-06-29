// ALDS1_1_A Insertion Sort

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n)        for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n)    for (int i = (s); i < (int)(n); i++)
#define rep3(n)          for (int i = 0; i < (int)(n); i++)
typedef vector<int> VI;



void insertion_sort(int A[], int N) {
    rep2(i, 1, N) {
        int v = A[i];
        int j = i-1;
        while (j >= 0 && A[j] > v) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        rep(i, N-1) {
            cout << A[i] << " ";
        }
        cout << A[N-1] << endl;
    }
}

int main() {
    int N;
    cin >> N;
    int A[N];
    rep(i, N) cin >> A[i];
    rep(i, N-1) {
            cout << A[i] << " ";
        }
        cout << A[N-1] << endl;
    insertion_sort(A, N);

    return 0;
}
