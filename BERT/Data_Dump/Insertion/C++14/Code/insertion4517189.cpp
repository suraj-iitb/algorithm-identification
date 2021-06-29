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
    for (int i = 1; i < N; ++i) {
        Rep(i, N - 1) {
            cout << A[i] << " ";
        }
        cout << A[N - 1] << endl;
        int v = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > v) {
            A[j + 1] = A[j];
            j--;
        } 
        A[j + 1] = v;
    }
    Rep(i, N - 1) {
        cout << A[i] << " ";
    }
    cout << A[N - 1] << endl;
    return 0;
}
