#include<iostream>
using namespace std;

//挿入ソートで数列を昇順に並び替えるプログラム
int main(){
    int N, i, j, prev, array[100] = {};
    cin >> N;

    //N個の整数を配列に格納
    i = 0;
    while(i < N){
        cin >> array[i];
        cout << array[i];
        if (i < N-1) cout << ' ';
        i++;
    }
    cout << endl;

    //挿入ソート
    i = 1;
    while(i < N){
        prev = array[i];
        j = i - 1;
        while(j >= 0 && array[j] > prev){
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = prev;
        
        j = 0;
        while(j < N){
            cout << array[j];
            if (j < N-1) cout << ' ';
            j++;
        }
        cout << endl;
        i++;
    }

    return 0;
}


