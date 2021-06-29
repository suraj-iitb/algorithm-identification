/*
1 insertionSort(A, N) // N個の要素を含む0-オリジンの配列A
2   for i が 1 から N-1 まで
3     v = A[i]
4     j = i - 1
5     while j >= 0 かつ A[j] > v
6       A[j+1] = A[j]
7       j--
8     A[j+1] = v
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

void insertionSort(vector<int> &A){
    print_vec(A);
    for(int i=1;i<A.size();i++){
        int v = A.at(i);
        int j = i-1;
        while(j >= 0 && A.at(j) > v){
            A.at(j+1) = A.at(j);
            j--;
        }
        A.at(j+1) = v;
        print_vec(A);
    }
}

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i,N) cin >> A.at(i);
    insertionSort(A);
}   
