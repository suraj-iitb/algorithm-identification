#include <iostream>
using namespace std;

void print(int A[], int N, int cnt) {
    for (int i = 0; i < N; i++) {
        if (i) cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << cnt << endl;
    return;
}

void selectionSort(int A[], int N) {
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        int min_id = i;
        for (int j = i; j < N; j++) {
            if (A[min_id] > A[j]) {
                min_id = j;
            }
        }
        if (i != min_id) {
            swap(A[i], A[min_id]);
            cnt++;
        }
    }
    print(A, N, cnt);
    return;
}

int main() {
    int N, A[110];
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    selectionSort(A, N);
    return 0;
}
