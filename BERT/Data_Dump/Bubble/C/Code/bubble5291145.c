#include<stdio.h>

//N回分引数*A内を出力する関数
void print(int* A, int N) {
    int i;
    for (i = 0; i < N; i++) 
    {   if (i) printf(" ");
        printf("%d", A[i]);
    }
    printf("\n");
}

//バブルソートを行う関数
int bubble_sort(int* A, int N) {
    int i, j,tmp, cnt = 0;
    //N回分ループするforループ
    for (i = 0; i < N; i++) 
    { //jを--していき、N回分ループするforループ
        for (j = N - 1; j >= i + 1; j--)
        {
            //A内の[j]番目の値が、jのひとつ前の値より小さい場合
            if (A[j] < A[j - 1]) 
            {
                //tmpにjの値を代入
                tmp = A[j];
                //jにjのひとつ前の値を代入
                A[j] = A[j - 1];
                //jのひとつ前にtmp(元のj)を代入
                A[j - 1] = tmp;
                cnt++;
            }
        }
    }
    print(A, N);
    //バブルソートの操作数　cntを返す
    return cnt;
}

int main() {
    int i, N, data[100];
    //データ入力数を受け付ける
    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        //入力された値をdata[i]番目に格納
        scanf("%d", &data[i]);
    }
        //cnt数をバブルソート関数より受け取り、出力　＝交換回数を出力
        printf("%d\n", bubble_sort(data, N));
        return 0;

}
