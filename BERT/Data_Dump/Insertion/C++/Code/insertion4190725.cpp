#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i,N) cin >> A[i]; 

    for(int SortedNum = 0; SortedNum < N; ++SortedNum){ // Sorted is the # of sorted cards.
        int MovingVal = A[SortedNum];
        int CompNum = SortedNum - 1;
        while( (CompNum >= 0) && (A[CompNum] > MovingVal) ){
            A[CompNum + 1] = A[CompNum]; // 一つ上の箱に上書き
            --CompNum;
        }
        A[CompNum + 1] = MovingVal;
        
        rep(i,N-1) cout << A[i] << " ";
        cout << A[N-1] << endl;
    }
    
    return 0;
}
