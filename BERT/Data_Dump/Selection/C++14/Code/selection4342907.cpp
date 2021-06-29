/*
1 selectionSort(A, N) // N個の要素を含む0-オリジンの配列A
2   for i が 0 から N-1 まで
3     minj = i
4     for j が i から N-1 まで
5       if A[j] < A[minj]
6         minj = j
7     A[i] と A[minj] を交換
*/
#include "bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

void print_vec(vector<int> &A){
    for(int i=0;i<A.size();i++){
        cout << A.at(i);
        if(i == A.size()-1){
            cout << endl;
        }else{
            cout << ' ';
        }
    }
}

void selectionSort(vector<int> &A,int &cnt){
    for(int i=0; i<A.size();i++){
        int minj = i;
        for(int j=i;j<A.size();j++){
            if(A.at(j) < A.at(minj)){
                minj = j;
            }
        }
        if(i != minj){
            cnt++;
            swap(A.at(i),A.at(minj));
        }
    }
}
int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i,N) cin >> A.at(i);
    int cnt =0;
    selectionSort(A,cnt);
    print_vec(A);
    cout << cnt << endl;
}   
