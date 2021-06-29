#include<iostream>
using namespace std;

//数列Aを読み込み、バブルソートで昇順に並び変え出力するプログラム
int main(){
    int N, i, flag, prev, count, array[100] = {};
    cin >> N;

    //N子の整数を配列に入力
    i = 0;
    while(i < N){
        cin >> array[i];
        i++;
    }

    //バブルソート
    count = 0;
    flag = 1;
    while(flag){
        flag = 0;
        i = N - 1;
        while(i > 0){
            if (array[i] < array[i-1]){
                prev = array[i];
                array[i] = array[i-1];
                array[i-1] = prev;
                count++;
                flag = 1;
            }
            i--;
        }
    }
    
    i = 0;
    while(i < N){
        cout << array[i];
        if (i < N-1) cout << ' ';
        else cout << endl;
        i++;
    }
    cout << count << endl;

    return 0;
}

