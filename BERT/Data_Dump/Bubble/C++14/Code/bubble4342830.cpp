/*
1 bubbleSort(A, N) // N 個の要素を含む 0-オリジンの配列 A
2   flag = 1 // 逆の隣接要素が存在する
3   while flag
4     flag = 0
5     for j が N-1 から 1 まで
6       if A[j] < A[j-1]
7         A[j] と A[j-1] を交換
8         flag = 1
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

void bubbleSort(vector<int> &A,int &cnt){
    bool flag = 1;
    for(int i=0; flag; i++){
        flag = 0;
        for(int j = A.size()-1; j>= i+1; j--){
            if(A.at(j) < A.at(j-1)){
                swap(A.at(j),A.at(j-1));
                cnt++;
                flag = 1;
            }
        }
    }
}

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i,N) cin >> A.at(i);
    int cnt = 0;
    bubbleSort(A,cnt);
    print_vec(A);
    cout << cnt << endl;
}   
