#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, cnt = 0;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++){
        cin >> A[i];
    }
    for (int i = 0; i < N-1; i++){
        for (int j = N-1; j > i; j--){
            if (A[j] < A[j-1]){
                swap(A[j], A[j-1]);
                cnt++;
            }
        }
    }
    for (int i = 0; i < N-1; i++){
        cout << A[i] << " ";
    }
    cout << A[N-1] << endl << cnt << endl;
}

