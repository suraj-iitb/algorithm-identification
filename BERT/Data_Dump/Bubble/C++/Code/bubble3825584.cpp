#include <iostream>
#include <algorithm>
using namespace std;

int bubblesort(int A[], int N) {
    int step = 0;
    bool flag = true;
    while(flag) {
        flag = false;
        for(int j = 0; j < N-1; j++) {
            if(A[j+1] < A[j]) {
                step++;
                swap(A[j], A[j+1]);
                flag = true;
            }
        }
    }
    return step;
}

int main() {
    int A[100], step, N;

    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    step = bubblesort(A, N);
    for(int i = 0; i < N; i++) {
        if(i > 0) {
            cout << " ";
        }
        cout << A[i];
    }
    cout << endl;
    cout << step << endl;
    return 0;
}
