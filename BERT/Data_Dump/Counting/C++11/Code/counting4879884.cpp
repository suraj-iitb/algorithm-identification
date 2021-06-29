#include <bits/stdc++.h>
using namespace std;

void countingSort(vector<int> &A, vector<int> &B, int k){
    vector<int> C(k+1);
    for(int i=0; i<k; i++){
        C[i] = 0;
    }
    for(int j = 0; j < (int)A.size(); j++){
        C[A[j]]++; 
    }
    for(int i=0; i<k; i++){
        C[i] = C[i] + C[i-1]; //昇順に並べたときに各数値が最後に現れる要素番号を格納する。
    }
    int j = (int)A.size()-1;
    for(; j>-1; j--){
        B[C[A[j]]] = A[j];
        C[A[j]]--;//引いてくと次にC[A[j]]番目の要素を参照するときには、以前より一つ前の要素が参照されることになる。
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> A(n);
    int max1 = 0;
    for(int i=0; i < n; i++){
        cin >> A[i];
        if(A[i] > max1){
            max1 = A[i];
        }
    }
    //int max2 = max(max1,(int)A.size());
    vector<int> B(n+1);
    countingSort(A, B, max1+1);
    for(int i=1; i< n; i++){
        cout << B[i] << " ";
    }
    cout << B[A.size()] << endl;
}

