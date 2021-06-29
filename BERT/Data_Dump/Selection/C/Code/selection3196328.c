#include <stdio.h>

int main(void)
{
    int n ,m;
    int A[1000];
    
        scanf("%d" , &n);

    
    for (m = 0 ; m < n ; m++) {
            scanf("%d" , &A[m]);
    }
    
    /*Selection Sort*/
    int minj;
    int i ,j;
    int temp ,count;
    
    for (i = 0 ; i < n ; i++) {
        /*未ソート部分の先頭の要素をとりあえずminjにしてループjを開始し、要素内の最小要素を取り出す*/
        minj = i;
        for (j = i ; j < n ; j++) {
            /*minjに要素の中で一番小さいものを代入*/
            if ( A[minj] > A[j] )
                minj = j;
        }
        /*で先頭要素A[i]と要素中の最小要素minjをswap(ただし選択した先頭要素が最小値minjだった場合、ソートはされない)*/
        if (i != minj) {
            temp = A[i];
            A[i] = A[minj];
            A[minj] = temp;
            /*数える用*/
            count++;
        }
    }

    /*結果の表示*/
    for (int s = 0 ; s < n - 1 ; s++)
        printf("%d " , A[s]);
        
    printf("%d\n" , A[n - 1]);
    printf("%d\n" , count);
    
    return 0;
}

