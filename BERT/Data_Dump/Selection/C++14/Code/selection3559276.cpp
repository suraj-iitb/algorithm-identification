#include <bits/stdc++.h>

using namespace std;

int selectionSort(vector<int> &x, int n){
    int cnt = 0;
    for(int i = 0; i < n; i++){
        int minj = i;
        for(int j = i; j < n; j++){
            if(x[j] < x[minj]){
                minj = j;
            }
        }
        swap(x[i], x[minj]);
        if(i != minj) cnt++;
    }
    return cnt;
}

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }

    int ans = selectionSort(A, N);
    for(int i = 0; i < N; i++) cout << A[i] << (i < N-1 ? " " : "");
    cout << "\n";
    cout << ans << "\n";

    return 0;
}
