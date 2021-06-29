// ALDS1_2_A: Bubble Sort

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n)        for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n)    for (int i = (s); i < (int)(n); i++)
#define rep3(n)          for (int i = 0; i < (int)(n); i++)
typedef vector<int> VI;


int bubble_sort(int A[], int N) {
    int flag = 1;
    int cnt = 0;
    while (flag) {
        flag = 0;
        for (int j = N-1; j >= 1; j--) {
            if (A[j] < A[j-1]) {
                swap(A[j], A[j-1]);
                cnt++;
                flag = 1;
            }
        }
    }
    return cnt;
}

int main() {
    int N;
    cin >> N;
    int A[N];
    rep(i, N) cin >> A[i];

    int swap_cnt = bubble_sort(A, N);

    rep(i, N-1) cout << A[i] << " ";
    cout << A[N-1] << endl << swap_cnt << endl;
    
    return 0;
}
