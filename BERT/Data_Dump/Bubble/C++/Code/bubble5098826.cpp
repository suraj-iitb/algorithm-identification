// バブルソート : 最小のものをどんどん決めていく、隣り合った要素を交換しまくる

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, count = 0;
    scanf("%d",&n);
    int list[100];
    for (int i = 0; i < n; i++){
        scanf("%d", &list[i]);
    }

    for (int i = 0; i < n-1; i++){
        //交換
        for (int j = n-1; j > i; j--){
            if (list[j-1] > list[j]){
                int tmp = list[j];
                list[j] = list[j-1];
                list[j-1] = tmp;
                count++;
            }
        }
    }
    //出力
    for (int i = 0; i < n; i++){
        if (i == 0){
            printf("%d",list[i]);
        }
        else{
            printf(" %d",list[i]);
        }
    }
    printf("\n%d\n",count);    
}
