#include<iostream>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin>>N;//データの数に入力
    int a[N], min = 0, count = 0;
    for(int i = 0; i < N; i++) cin>>a[i];//データの入力

    //選択ソート
    for(int i = 0; i < N-1; i++) {
        min = i;
        for(int j = i+1; j < N; j++) {
            if(a[min] > a[j]) min = j;
        }
        if(min != i) {
            int s = a[min]; //入れ替えのための値保持
            a[min] = a[i];
            a[i] = s;
            count++; //カウント
        }
    }

    //出力
    for(int i = 0; i < N-1; i++) cout<<a[i]<<' ';
    cout<<a[N-1]<<endl;
    cout<<count<<endl;

    return 0;
}


