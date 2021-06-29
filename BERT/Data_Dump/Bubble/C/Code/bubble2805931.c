#include<stdio.h>

int main(){
    int i,N,j,t,cnt=0;
    int array[100]={};
    //入力表示
    scanf("%d", &N);
    for(i=0; i <= N-1; i++) scanf("%d", &array[i]);

    //大小比較交換
    for(i=0; i<N-1; i++){
        for(j=N-1; j>i; j--){
            if(array[j]<array[j-1]){
                t=array[j];
                array[j]=array[j-1];
                array[j-1]=t;
                cnt++;
            }
        }
    }

    //結果出力
    for(i=0; i<N; i++){
        if(i!=0)printf(" ");
        printf("%d",array[i]);
    }
    printf("\n%d\n",cnt);
    return 0;
}
