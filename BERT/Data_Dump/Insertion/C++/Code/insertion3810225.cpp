#include <iostream>
using namespace std;
void print(int sequence[], int N); // 出力するための関数
void insertionSort(int sequence[], int N); //挿入ソートの関数

int main(void){
    
    // 定義：数列を「 sequence 」、数列の個数を「 N 」と置く
    int sequence[100], N;

    cin >> N;
    
    // 反復：数列に値を入力する
    for(int i = 0; i < N; i++){
        cin >> sequence[i];
    }
    
    print(sequence, N); // 出力するための関数
    insertionSort(sequence, N); //挿入ソートの関数
    
    
}


/***********************  出力するための関数   ******************************/

void print(int sequence[], int N){
    for(int i = 0; i < N; i++){
        cout << sequence[i] << ((i != N-1) ? " " : "\n");
    }
}


/***********************  挿入ソートの関数  ******************************/

void insertionSort(int sequence[], int N){
    
    // 定義：一時保存の箱「 saveBox 」と置く
    int saveBox;
    
    // 反復：未ソートの範囲
    for(int i = 1; i < N; i++){
        saveBox = sequence[i];
        // 定義：ソート済の範囲を「 j 」と置く
        int j = i - 1;
        
        // 反復：一つ横の配列に移動ができるまで繰り返す（比較：配列「０」以上 かつ 配列「j」が saveBox より小さい  とき移動させたい）
        while(j >= 0 && sequence[j] > saveBox){
            sequence[j+1] = sequence[j];
            j--;
        }
        // 上の反復が出来ない ➡  移動が終了でその所が交換したい所
        sequence[j+1] = saveBox;
        
        print(sequence, N); // 出力するための関数
    }
}
