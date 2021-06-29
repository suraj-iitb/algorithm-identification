#include<bits/stdc++.h>
using namespace std;
const int k = 10001,N = 2000001;

int main(){
    int n;
    cin >> n;
    vector < int > A(N),B(N),C(k,0);
    //ソートしたい配列の読み込み
    for(int i = 1 ; i <= n ; i++ ) cin >> A[i];

    //上で読み込んだ配列の各々の整数値の個数を数え上げる    
    for(int j = 1 ; j <= n ; j++ ){
        C[A[j]]++;
    }

    //それぞれの整数値が配列のどこまで入るかを記録する配列
    for(int i = 1 ; i <= k ; i++ ){
        C[i] = C[i] + C[i-1];
    }

    //ソートした配列を格納する配列を作成
    for(int j = n ; j >= 1 ; j-- ){
        B[C[A[j]]] = A[j];
        C[A[j]] = C[A[j]] - 1;
    }

    for(int i = 1 ; i <= n ; i++ ){
        cout << ( i == 1 ? "" : " " ) << B[i];
    }

    cout << endl;
}
