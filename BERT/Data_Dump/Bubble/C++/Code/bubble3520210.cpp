#include<iostream>

using namespace std;

int bubbleSort (int A[], int N) {

    int cnt = 0;

    bool flag = true;

    while (flag) {
        flag = false;
        for (int i = N - 1; i > 0; i--) {
            if (A[i] < A[i - 1]) {
                swap (A[i], A[i - 1]);
                flag = true;
                cnt++;
                // disp (A, N);
            }
        }
        // cout << endl;
    }

    return cnt;

}

void disp (int A[], int N) {

    for (int i = 0; i < N; i++) {
    
        if (i > 0) {
            cout << " ";
        }
        cout << A[i];
    
    }

    cout << endl;

}

int main () {

    int A[100], N;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int cnt = bubbleSort (A, N);

    disp (A, N);

    cout << cnt << endl;

    return 0;
}
