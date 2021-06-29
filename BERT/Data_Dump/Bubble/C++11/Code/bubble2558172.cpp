#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int N;
    cin >> N;
    int A[N];
    for (auto& a : A) cin >> a;
    int cnt = 0;
    for (int i = N - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (A[j] > A[j+1]) {
                swap(A[j], A[j+1]);
                cnt++;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        cout << A[i] << (i < N - 1 ? " " : "\n");
    }
    cout << cnt << endl;
    return 0;
}
