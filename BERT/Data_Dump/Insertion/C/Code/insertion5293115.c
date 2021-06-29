#include<stdio.h>

int N, data[100];

//N回分数字の入力を受け入れ、dataに格納する関数
void input() {
    //一回目の入力で、何回dataに格納するかを受け付ける
    scanf("%d", &N);
    int i;
    //N回分数値の入力を受付け、dataに格納
    for (i = 0; i < N; i++) scanf("%d", &data[i]);
}

//N回分dataの中身をprintfする関数
void print() {
    int i;
    //forループでdataの中身をN回分＋して参照していく
    for (i = 0; i < N; i++) {
        if (i) printf(" ");
        printf("%d", data[i]);
    }
    printf("\n");
}

//N回分、数字を小さい順にソートし、printを呼ぶ関数
void insertion_sort() {
    print();
    int i, j,key;
    //jがNより小さい限りループするfor
    for (j = 1; j < N; j++) {
        //j番目のdataの値をkeyに代入
        key = data[j];
        //jより一つ前の値をiに代入
        i = j - 1;
        //iが0以上かつiがkey(=j番目の値)以上の場合whileループ
        //つまり、jより値が小さい値がひとつ前にある場合繰り返す
        while (i >= 0 && data[i] > key) {
            //i+1番目の値にi番目の値を代入
            data[i + 1] = data[i];
            i--;
        }
        //keyに保存しておいたjの値をi+1番目に代入
        data[i + 1] = key;
        print();
    }
}

int main() {
    input();
    insertion_sort();
    return 0;
}
