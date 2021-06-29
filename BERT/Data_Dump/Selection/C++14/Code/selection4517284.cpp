#include <bits/stdc++.h>
using namespace std;
#define Rep(i, n) for (int i = 0; i < (int)(n); i++)
#define BitRep(i, n) for (int i = 0; i < (int)(1 << n); i++)
#define Sum(vec) accumulate(vec.begin(), vec.end(), 0)
#define Sort(vec) sort(vec.begin(), vec.end())
#define Reverse(vec) reverse(vec.begin(), vec.end())
#define Next_permutation(vec) next_permutation(vec.begin(), vec.end())

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    Rep(i, N) {
        cin >> A[i];
    }
    int count = 0;
    for (int i = 0; i < N; ++i) {
        int minj = i;
        for (int j = i; j < N; ++j) {
            if (A[j] < A[minj]) {
                minj = j;
            }
        }
        if (i != minj) {
            swap(A[i], A[minj]);
            count++;
        }
    }
    Rep(i, N) {
        if (i) {
            cout << " ";
        }
        cout << A[i];
    }
    cout << endl;
    cout << count << endl;
    return 0;
}
