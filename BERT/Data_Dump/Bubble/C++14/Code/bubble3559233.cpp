#include <bits/stdc++.h>

using namespace std;

int bubbleSort(vector<int> &x, int n){
    int cnt = 0;
    bool flag = true;
    while(flag){
        flag = false;
        for(int j = n-1; 0 < j; j--){
            if(x[j] < x[j-1]){
                swap(x[j], x[j-1]);
                flag = true;
                cnt++;
            }
        }
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

    int ans = bubbleSort(A, N);
    for(int i = 0; i < N; i++) cout << A[i] << (i < N-1 ? " " : "");
    cout << "\n";
    cout << ans << "\n";
    
    return 0;
}
