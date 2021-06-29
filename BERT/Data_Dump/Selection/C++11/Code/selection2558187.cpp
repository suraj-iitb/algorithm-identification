#include<iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    int A[N];
    for (auto& a : A) cin >> a;
    int cnt = 0;
    for (int i = 0; i < N - 1; i++) {
        int minj = i;
        for (int j = i + 1; j < N; j++) {
            if (A[j] < A[minj]) minj = j;
        }
        if (i != minj) {
            swap(A[i], A[minj]);
            cnt++;
        }
    }
    for (int i = 0; i < N; i++) {
        cout << A[i] << (i < N - 1 ? " " : "\n");
    }
    cout << cnt << endl;
    return 0;
}
