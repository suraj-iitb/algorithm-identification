#include <bits/stdc++.h>
using namespace std;

int A[101];
int swap_cnt = 0;

void bubbleSort(int A[], int N) {
    bool flag = 1;
    while(flag) {
        flag = 0;
        for(int j = N-1; j >= 1; j--) {
            if(A[j] < A[j-1]) {
                swap(A[j], A[j-1]);
                swap_cnt++;
                flag = 1;
            }
        }
    }
}

int main() {
    int N; cin >> N;
    for(int i = 0; i < N; i++) cin >> A[i];

    bubbleSort(A, N);

    for(int i = 0; i < N; i++) {
        if(i < N-1) {
            cout << A[i] << " ";
        } else {
            cout << A[i] << endl;
        }
    }

    cout << swap_cnt << endl;

}
