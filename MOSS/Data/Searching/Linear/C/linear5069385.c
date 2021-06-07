#include<stdio.h>

int S[10000];
int n;
int T[500];
int q;
int C = 0;
int i,j;
int key;

linearSearch(){
    i = 0;
    S[n] = key;
    while(S[i] != key)i++; //目的のキーが見つかるまでi++
    if(i == n)return 0; //見つからずに最後尾まで到達
    return 1; //見つかったら1を返す
}

int main(){

    scanf("%d",&n); //S[]のデータの数
    for(i=0;i<n;i++){
        scanf("%d",&S[i]); //データ入力
       // printf("loop1\n");
    }

    scanf("%d",&q); //T[]のデータの数
    for(i=0;i<q;i++){
        scanf("%d",&T[i]); //データ入力
        //printf("loop2\n");
    }
    for(j=0;j<q;j++){
        key = T[j];
        if(linearSearch() == 1){
            C++;
           // printf("found\n");
        }
        //printf("loop\n");
    }
    printf("%d\n",C);

    return 0;
}
