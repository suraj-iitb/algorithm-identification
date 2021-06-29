#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i,N) cin >> A[i]; 

    int SwapNum = 0; //交換数

    for(int SortedNum = 0; SortedNum < N; ++SortedNum){    //Aの最初からSortedNum個目まではソート済
        bool Swapped = false; //このループで交換が行われたか
        int MinPos = SortedNum;    //未ソート部分での最小要素の位置
        for(int CurPos = SortedNum; CurPos < N; ++CurPos){
            if (A[CurPos] < A[MinPos]){
                Swapped = true;
                MinPos = CurPos;
            }
        }
        swap(A[SortedNum], A[MinPos]);
        if(Swapped) ++SwapNum;
    }


    rep(i,N-1) cout << A[i] << " ";
    cout << A[N-1] << endl;
    cout << SwapNum << endl;
    
    return 0;
}
