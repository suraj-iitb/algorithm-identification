#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)n; i++)
#define _GLIBCXX_DEBUG
using namespace std;

void exportVector(vector<int> A){
    // ソート前の配列の確認
    rep(i,A.size()){
        if(i == A.size() - 1){
            cout << A.at(i) << endl;            
        }
        else{
            cout << A.at(i) << " ";
        }
    }
}

// P.54
// N個の要素を含む0-オリジンの配列A
void insertionSort(vector<int> &A, int N){
    for(int i = 1; i < N; i++){
        int v = A.at(i);
        int j = i - 1;
        while(j >= 0 && A.at(j) > v){
            A.at(j+1) = A.at(j);
            j--;
        }
        A.at(j+1) = v;
        exportVector(A);
    }
} 

int main(){
    int n;
    cin >> n;
    vector<int> A(n);
    rep(i,n){
        cin >> A.at(i);
    }


    // ソート前の配列の確認
    exportVector(A);

    // 挿入ソート
    insertionSort(A, n);
    return 0;
}
