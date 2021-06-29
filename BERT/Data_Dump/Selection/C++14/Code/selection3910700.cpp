#include <bits/stdc++.h>
#include <cstdlib>  // abs() for integer 絶対値求めやつ
#include <cmath>    // abs() for float, and fabs()
#include <algorithm>
#include <vector>
#include <string>
#include<iomanip>//浮動小数点数を出力する制度の指定
//使い方　数値をnumとして　cout<<setprecision(n)<<num ;nは桁数
#define rep(i,n) for(int i = 0; i < (n);i++)
#define SORT(a) sort((a).begin(),(a).end())
#define REV(a) reverse((a).begin(),(a).end())
using namespace std;
using ll =long long;
#define INF 2000000000
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
#define che(a,string) cout<<"//"<<string <<"=="<<(a)<<"//" <<endl;
bool IsInt(double a){int b = a/1;if(a==b){return true;}else {return false;}}
/*覚えてないことメaモ
数値型から文字列に変換　to_string(number);これは簡単
文字列から数値型に変換　stoi(number)
文字列からllに変換　stoll(number)*/

//ここから書き始める

int main(){
    int n ;
    cin >> n; 
    vector<int> A(n);
    rep(i,n){
        cin>>A[i];
    }
    int count = 0;
    rep(i,n){
        int minj = i;
        for(int j = i ; j  < n ; j ++ ){
            //minjに最初の要素の位置を入れておく
            if(A[j]<A[minj]){
                minj = j;
            }
        }
        if (minj != i){
            swap(A[i], A[minj]);
            count++;
        }
    }
    rep(i,n){
        if(i!=n-1)cout<<A[i]<<" ";
        else cout<<A[i]<<endl;
    }
    cout<<count<<endl;
}
