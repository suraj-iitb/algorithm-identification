#include <iostream>
using namespace std;
void print(int sequence[], int N); // 出力するための関数
int bubbleSort(int sequence[], int N); //バブルソートの関数

int main(void){
    
    // 定義：数列を「 sequence 」、数列の個数を「 N 」とソート回数を「 count 」と置く
    int sequence[100], N, count;

    cin >> N;
    
    // 反復：数列に値を入力する
    for(int i = 0; i < N; i++){
        cin >> sequence[i];
    }
    
    count = bubbleSort(sequence, N); //バブルソートの関数
    print(sequence, N); // 出力するための関数
    cout << count << endl;
    
    
}


/***********************  出力するための関数   ******************************/

void print(int sequence[], int N){
    for(int i = 0; i < N; i++){
        cout << sequence[i] << ((i != N-1) ? " " : "\n");
    }
}


/***********************  バブルソートの関数  ******************************/

int bubbleSort(int sequence[], int N){
    int count = 0;
    
    
    for(int i = 0; i < N; i++){
        //反復：バブルソートは末尾の数列から開始 変数 i はソート済の範囲を表す 初めは 0から始めり N-1 まで終わる
        for(int j = N-1; j > i; j--){
            
            //  比較：隣り合う数列を比べる
            if(sequence[j-1] > sequence[j]){
                swap(sequence[j-1], sequence[j]);   // 交換
                count++;
            }
        }
    }
    
    return count;
}




