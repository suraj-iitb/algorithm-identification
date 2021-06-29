#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> A, int N) {
    int count = 0;
    for (int i = 0; i < N; i++) {
        int minj = i;
        for (int j = i; j < N; j++) {
            if (A[j] < A[minj]) {
                minj = j;
            }
        }
        if(i != minj){
            swap(A[i], A[minj]);
            count++;
        }
    }
    for (int i = 0; i < N; i++) {
        cout << A[i];
        if (i != N - 1){
            cout << " ";
        }
    }
    cout << endl;
    cout << count << endl;
}

int main() {

    int n;
    cin >> n;

    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    selectionSort(A, n);

    return 0;

}
