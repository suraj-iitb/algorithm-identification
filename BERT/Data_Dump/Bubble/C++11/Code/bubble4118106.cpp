#include<iostream>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, count = 0;
    cin>>N;  //データの数の入力
    int a[N];
    for(int i = 0; i < N; i++) cin>>a[i];  //データの入力

    //バブルソート
    for(int i = 0; i < N; i++) {
        for(int j = N-1; j > i; j--) {
            if(a[j] < a[j-1]) {
                int s = a[j-1]; //入れ替えのための値保持
                a[j-1] = a[j];
                a[j] = s;
                count++;  //カウント
            }
        }
    }

    //出力
    for(int i = 0; i < N-1; i++) cout<<a[i]<<' ';
    cout<<a[N-1]<<endl;
    cout<<count<<endl;
    return 0 ;
}

