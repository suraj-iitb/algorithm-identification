#include <iostream>
using namespace std;

int selectionSort(int A[], int N) {
    int minj;
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        minj = i;
        for (int j = i; j < N; j++) {
            if (A[j] < A[minj]) minj = j;   
        }
        if (i != minj) {
            swap(A[i], A[minj]);
            cnt++;
        }
    }
    return cnt;
}

void trace(int A[], int N) {
    for (int k = 0; k < N; k++) {
        if (k > 0) cout << ' ';
        cout << A[k];
    }
    cout << endl;
}

int main() {
    int N, A[100], count = 0;
    cin >> N;

    for (int i = 0; i < N; i++) cin >> A[i];

    count += selectionSort(A, N);
    trace(A, N);
    cout << count << endl;

    return 0;


}
