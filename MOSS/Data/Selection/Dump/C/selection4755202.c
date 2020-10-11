#include <stdio.h>

void Swap(int *x,int *y);

int main(){
    //初期入力
    int N;
    scanf("%d",&N);
    int A[N];
    for(int i=0;i<N;i++)
        scanf("%d",&A[i]);
    //変数定義
    int cp;
    int min;
    int min_n;
    int change=0;
    //処理
    for(int i=0;i<N-1;i++){
        min=A[i];
        min_n=i;
        for(int j=i+1;j<N;j++){
            if(min>A[j]){
                min=A[j];
                min_n=j;
            }
        }
        if(min_n!=i){
            Swap(&A[min_n],&A[i]);
            change++;
        }
    }
    //最終出力
    printf("%d",A[0]);
    for(int i=1;i<N;i++){
        printf(" %d",A[i]);
    }
    printf("\n");
    printf("%d\n",change);
}

void Swap(int *x,int *y){
    int cp;

    cp=*x;
    *x=*y;
    *y=cp;
    
}
