
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define ll long long
using namespace std;
#define MAX 2000001

int main(){
    int n;
    cin>>n;
    int A[MAX],B[MAX];
    int CNT[MAX];
    rep(i,MAX) CNT[i]=0;
    
    //入力の受け取りと入力要素をカウント
   
    rep(i,n){
        cin>>A[i+1];
        CNT[A[i+1]]++;
    }
    /*
    cout<<"A ";
    rep(i,n){
        cout<<A[i];
    }
    cout<<endl;
    
    cout<<"CNT 初期状態　";
    rep(i,n+1){
        cout<<CNT[i];
    }
    cout<<endl;
    */

    //累積和の計算
    rep(i,MAX) CNT[i]+=CNT[i-1];

    /*
    cout<<"CNT 累積和　";
    rep(i,n+1){
        cout<<CNT[i];
    }
    cout<<endl;
    */

    for(int i=1;i<=n;i++){
        B[CNT[A[i]]]=A[i];
        CNT[A[i]]--;
    }
    /*
    cout<<"CNT 操作後　";
    rep(i,n+1){
        cout<<CNT[i];
    }
    cout<<endl;
    */

    for(int i=1;i<=n;i++){
        if(i-1) cout<<" ";
        cout<<B[i];
    }
    cout<<endl;

    return 0;
}
