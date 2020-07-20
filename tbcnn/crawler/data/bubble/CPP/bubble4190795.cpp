#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i,N) cin >> A[i]; 

    bool Unsorted = true;
    int SortedNum = 0; //Aの最初からSortedNum個目まではソート済
    int SwapNum = 0; //交換数

    while(Unsorted){
        Unsorted = false;
        for(int CurPos = N-1; CurPos >= SortedNum + 1; --CurPos){
            if(A[CurPos] < A[CurPos-1]){
                swap(A[CurPos], A[CurPos-1]);
                ++SwapNum;
                Unsorted = true;
            }
        }
        ++SortedNum;
    }

    rep(i,N-1) cout << A[i] << " ";
    cout << A[N-1] << endl;
    cout << SwapNum << endl;
    
    return 0;
}
