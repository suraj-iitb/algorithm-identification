// 挿入ソート
#include <stdio.h>
#include <stdlib.h>
//int main(int argc, char *argv[]){
int main(){
    int n;
    // &nはnに対するポインタ
    scanf("%d",&n);
    int *list;
    list = (int *)malloc(n);
    for (int i = 0; i < n; i++){
        scanf("%d",&list[i]);
        //list[i] = atoi(argv[i+2]);
    }
    for (int i = 1; i < n; i++){
        //表示
        for (int j = 0; j < n-1; j++){
            printf("%d ",list[j]);
        }
        printf("%d\n",list[n-1]);

        //入り込む位置を見つける
        for (int j = 0; j < i; j++){
            //printf("%d %d\n",list[i],list[j]);
            if (list[i] < list[j]){
                // list[j]にlist[i]を入れてjからi-1までの配列を一個ずつずらす
                int tmp = list[i];
                for (int k = i; k > j; k--){
                    list[k] = list[k-1];
                }
                list[j] = tmp;
                break;
            }
        }
    }
    //表示
    for (int j = 0; j < n-1; j++){
            printf("%d ",list[j]);
        }
    printf("%d\n",list[n-1]);
    return 0;
}

