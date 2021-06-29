#include<iostream>
#include<algorithm>
using namespace std;

int bubble_sort(int A[], int N) {
    int cnt = 0;
    bool flag = true;

    for (int i = 0; flag; i++) {
        flag = false;
        for (int j = N - 1; j >= i + 1; j--) {
            if (A[j] < A[j - 1]) {
                swap(A[j], A[j - 1]);
                flag = true;
                cnt++;
            }
        }
    }

    return cnt;
}

int main() {
    int N, cnt, A[100];

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    cnt = bubble_sort(A, N);

    cout << A[0];
    for (int i = 1; i < N; i++) {
        if (i) cout << ' ';
        cout << A[i];
    }
    cout << endl;
    cout << cnt << endl;
    
    return 0;
}
