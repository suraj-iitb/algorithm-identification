#include<stdio.h>
const int MAX = 100; //配列の最大サイズ

void output(int array_data[], int count){
    int i;

    for(i = 0; i < count; i++){
        if( i > 0){
            printf(" ");
        }
        printf("%d", array_data[i]);
    }
    printf("\n");
}

void insert_sort(int array_data[], int count){
    int i,j;
    int v;

    for(i = 1; i < count ; i++){
        v = array_data[i];
        j = i - 1;
        while(j >= 0 && array_data[j] > v){
            array_data[j + 1] = array_data[j];
            j--;
        }
        array_data[j + 1] = v;
        output(array_data, count);
    }
}

int main(){
    int i;
    int count;
    int array_input[MAX];

    scanf("%d", &count); // 配列のサイズを入力

    for(i = 0; i < count; i++){
        scanf("%d", &array_input[i]); // 配列データの受け取り
    }

    // 入力値を出力
    output(array_input, count);

    // ソートの実行
    insert_sort(array_input, count);

    // 並び変え後の出力
    // output(array_input, count);

    return 0;
}

