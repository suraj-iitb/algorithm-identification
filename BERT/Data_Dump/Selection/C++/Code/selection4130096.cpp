#include<iostream>
using namespace std;

#define N 100

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin>>n;//データの数に入力
    int a[N], min = 0, count = 0;
    for(int i = 0; i < n; i++) cin>>a[i];//データの入力

    //選択ソート
    for(int i = 0; i < n-1; i++) {
        min = i;
        for(int j = i+1; j < n; j++) {
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
    for(int i = 0; i < n-1; i++) cout<<a[i]<<' ';
    cout<<a[n-1]<<endl;
    cout<<count<<endl;

    return 0;
}


