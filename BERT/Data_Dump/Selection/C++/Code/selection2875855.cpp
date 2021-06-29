#include <iostream>
using namespace std;

int main() {
    int N, A[110], cnt = 0;
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> A[i];

    for (int i = 0; i < N; ++i) {
        int minj = i;
        for (int j = i; j < N; ++j) {
            if (A[j] < A[minj]) {
                minj = j;
            }
        }
        int tmp = A[i];
        A[i] = A[minj];
        A[minj] = tmp;
        if (i != minj) ++cnt;
    }

    for (int i = 0; i < N; ++i) {
        if (i) cout << ' ';
        cout << A[i];
    }
    cout << endl << cnt << endl;
    
    return 0;
}
