#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
//using ll = long long;
//using P = pair<int,int>;

void selectionSort(vector<int>& A, int N, int& change_cnt){ // N個の要素を含む0-オリジンの配列A
    for (int i=0;i<N;i++){
        int minj = i;
        for (int j=i;j<N;j++){
            if (A[j] < A[minj]){
                minj = j;
            }
        }
        if (A[i]!=A[minj]){ 
            int tmp_Ai = A[i];
            A[i] = A[minj];
            A[minj] = tmp_Ai;
            change_cnt++;
        }
    }
}

int main(){
    int N, change_cnt=0;
    cin >> N;
    vector<int> A(N);
    for (int i=0;i<N;i++) cin >> A.at(i);
    selectionSort(A, N, change_cnt);
    for (int i=0;i<N;i++) {
        cout << A.at(i);
        if (i == N-1) break;
        cout << ' ';
    } 
    cout << endl;
    cout << change_cnt << endl;
}
