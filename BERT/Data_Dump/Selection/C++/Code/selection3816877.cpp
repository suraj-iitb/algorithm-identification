#include <iostream>
using namespace std;
void print(int sequence[], int N); // 出力するための関数
int selectionSort(int sequence[], int N); //挿入ソートの関数

int main(void){
    
    // 定義：数列を「 sequence 」、数列の個数を「 N 」とソート回数を「 count 」と置く
    int sequence[100], N, count;

    cin >> N;
    
    // 反復：数列に値を入力する
    for(int i = 0; i < N; i++){
        cin >> sequence[i];
    }

    count = selectionSort(sequence, N); //選択ソートの関数
    print(sequence, N); // 出力するための関数
    cout << count << endl;
    
    return 0;
    
}


/***********************  出力するための関数   ******************************/

void print(int sequence[], int N){
    for(int i = 0; i < N; i++){
        cout << sequence[i] << ((i != N-1) ? " " : "\n");
    }
}


/***********************  選択ソートの関数  ******************************/

int selectionSort(int sequence[], int N){
    int count = 0;
    for(int i = 0; i < N; i++){
        
        // 定義：最小の値の場所「 minPosition 」を定義 ➡  初めを i と置く 
        int minPosition = i;
            for(int j = i+1; j < N; j++){
                
                // 比較：最小の場所を比較して探している
                if(sequence[j] < sequence[minPosition]) minPosition = j;
            }
            // 比較：交換があるか確認
            if(i != minPosition){
                swap(sequence[i], sequence[minPosition]);
                count++;
        }
    }
    
    return count;
}




