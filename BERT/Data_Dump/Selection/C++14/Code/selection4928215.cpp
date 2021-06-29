#include<iostream>
using namespace std;

//N個の整数を読み込み、選択ソートのアルゴリズムで昇順に並び替え出力するプログラムを作成してください。
int main(){
    int N, i, min, prev, count = 0, array[100] = {};
    cin >> N;

    //N個の整数を配列に格納
    i = 0;
    while(i < N){
        cin >> array[i];
        i++;
    }

    //選択ソート
    for(int i=0; i <= N-1; i++){
        min = i;
        for(int j = i; j <= N-1; j++){
            if (array[j] < array[min]) min = j;
        }
        prev = array[i]; array[i] = array[min]; array[min] = prev;
        if (min != i) count++;

    }

    i = 0;
    while(i < N){
        cout << array[i];
        if (i < N-1) cout << ' ';
        i++;
    }
    cout << endl;
    cout << count << endl;

    return 0;
}

