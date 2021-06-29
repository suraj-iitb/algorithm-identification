// 選択ソート(selection sort)
// 最小のものをどんどん決めていく
#include <stdio.h>
#include <stdlib.h>
int main(){
    int n, count = 0;
    scanf("%d", &n);
    int *list;
    list = (int *)malloc(n);
    for (int i = 0; i < n; i++){
        scanf("%d",&list[i]);
    }
    for (int i = 0; i < n; i++){
        // iは最小値を入れたい位置
        int minindex = i;
        for (int j = i; j < n; j++){
            // minindexは最小値がある位置
            if (list[j] < list[minindex]){
                minindex = j;
            }
        }
        // minindexとiを交換
        int tmp = list[i];
        list[i] = list[minindex];
        list[minindex] = tmp;
        if (i != minindex){
            count++;
        }
    }
    for (int i = 0; i < n; i++){
        if (i == 0){
            printf("%d",list[i]);
        }else{
            printf(" %d", list[i]);
        }
    }
    printf("\n%d\n",count);
}
