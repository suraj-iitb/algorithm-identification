// ALDS_1_2_B: Selection Sort

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n)        for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n)    for (int i = (s); i < (int)(n); i++)
#define rep3(n)          for (int i = 0; i < (int)(n); i++)
typedef vector<int> VI;


int selection_sort(int A[], int N) {
    int cnt = 0;
    rep(i, N) {
        int minj = i;
        rep2(j, i, N) {
            if (A[j] < A[minj]) minj =j;
        }
        swap(A[i], A[minj]);
        if (i != minj) cnt++;
    }
    return cnt;
}


int main() {
    int N;
    cin >> N;
    int A[N];
    rep(i, N) cin >> A[i];

    int swp_cnt = selection_sort(A, N);
    rep(i, N) {
        if (i) cout << " ";
        cout << A[i];
    }

    cout << endl << swp_cnt << endl;
    return 0;
}
