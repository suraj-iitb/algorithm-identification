#include <iostream>
using namespace std;

int main() {
    int N, A[110], cnt = 0;
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> A[i];

    int flag = 1;
    while (flag) {
        flag = 0;
        for (int i = N - 1; i > 0; --i) {
            if (A[i] < A[i - 1]) {
                int tmp = A[i];
                A[i] = A[i - 1];
                A[i - 1] = tmp;
                ++cnt;
                flag = 1;
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        if (i) cout << ' ';
        cout << A[i];
    }
    cout << endl;
    cout << cnt << endl;
    
    return 0;
}
