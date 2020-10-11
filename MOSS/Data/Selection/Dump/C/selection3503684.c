#include<stdio.h>
//選択ソート
int selectionSort(int A[],int N){
    int i,j,t,sw=0,minj; //tはswapのための変数
    for(i=0;i<N-1;i++){
        minj=i;
        for(j=i;j<N;j++){
            if(A[j] < A[minj]) minj = j; //ここで最小値を探している
        }
        t = A[i]; A[i] = A[minj]; A[minj] = t; //swap処理,A[i]は未ソート部分の先頭要素
        if(i != minj) sw++;
    }
    return sw;
}

int main(){
    int A[100];
    int N,i,sw;
    scanf("%d",&N);
    for(i=0;i<N;i++) scanf("%d",&A[i]);

    sw = selectionSort(A,N);
    //ソートした結果
    for(i=0;i<N;i++){
        if(i>0)printf(" "); //この定型文なるほど！って感じ
        printf("%d",A[i]);
    }
    putchar('\n');
    printf("%d\n",sw);

    return 0;
}
