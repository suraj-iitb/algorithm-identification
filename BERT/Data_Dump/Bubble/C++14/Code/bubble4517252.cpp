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
    int index = 0;
    bool flag = true;
    int count = 0;
    while (flag) {
        flag = false;
        for (int i = N - 1; i >= index + 1; --i) {
            if (A[i] < A[i - 1]) {
                swap(A[i], A[i - 1]);
                flag = true;
                count++;
            }
        }
        index++;
    }
    Rep(i, N - 1) {
        cout << A[i] << " ";
    }
    cout << A[N - 1] << endl;
    cout << count << endl;
    return 0;
}
