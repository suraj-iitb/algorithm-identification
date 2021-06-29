#include<stdio.h>

int S[100000];
int n;
int T[50000];
int q;
int C = 0;
int i,j;
int key;

binarySearch(){
    int left = 0;
    int right = n;
    int mid;
    while(left < right){
        mid = (left + right) / 2;   //midを配置

        if(S[mid] == key)return 1;          //mid = keyなら見つけた
        else if(key < S[mid])right = mid;   //mid > keyなら上限をmidに設定
        else left = mid + 1;                //mid < keyなら下限をmid+1に設定
    }
    return 0;   
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
        if(binarySearch() == 1){
            C++;
           // printf("found\n");
        }
        //printf("loop\n");
    }
    printf("%d\n",C);

    return 0;
}
