#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, cnt = 0;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++){
        cin >> A[i];
    }
    int minj;
    for (int i = 0; i < N; i++) {
        minj = i;
        for (int j = i; j < N; j++){
            if (A[j] < A[minj]){
                minj = j;
            }
        }
        swap(A[i], A[minj]);
      	if (i != minj)
        	cnt++;
    }
    for (int i = 0; i < N-1; i++){
        cout << A[i] << " ";
    }
    cout << A[N-1] << endl << cnt << endl;
}
