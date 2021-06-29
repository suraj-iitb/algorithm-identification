#include<iostream>
using namespace std;

#define N 100

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, count = 0;
    cin>>n;  //データの数の入力
    int a[N];
    for(int i = 0; i < n; i++) cin>>a[i];  //データの入力

    //バブルソート
    for(int i = 0; i < n; i++) {
        for(int j = n-1; j > i; j--) {
            if(a[j] < a[j-1]) {
                int s = a[j-1]; //入れ替えのための値保持
                a[j-1] = a[j];
                a[j] = s;
                count++;  //カウント
            }
        }
    }

    //出力
    for(int i = 0; i < n-1; i++) cout<<a[i]<<' ';
    cout<<a[n-1]<<endl;
    cout<<count<<endl;
    return 0 ;
}

