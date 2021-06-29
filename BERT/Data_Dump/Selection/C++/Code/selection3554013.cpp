#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    int A[N];
    for(int i = 0; i < N; i++) cin >> A[i];
    int cnt = 0;
    for(int i = 0; i < N; i++) {
        int minj = i;
        for(int j = i; j < N; j++) {
            if (A[j] < A[minj]) {
                minj = j;
            }
        }
        if (i != minj) {
            swap(A[i], A[minj]);
            cnt++;
        }
    }

    for (int i = 0; i < N; i++) (i != N-1) ? cout << A[i] << ' ' : cout << A[i] << endl;
    cout << cnt << endl;

    return 0;
}
