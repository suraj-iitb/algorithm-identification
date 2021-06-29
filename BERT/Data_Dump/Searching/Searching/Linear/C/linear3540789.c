#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int a[10005];
    int q[505];
    int data_num;
    scanf("%d", &data_num);
    for(int i=0; i<data_num; i++){
        scanf("%d", &a[i]);
    }
    int query_num;
    scanf("%d", &query_num);
    for(int i=0; i<query_num; i++){
        scanf("%d", &q[i]);
    }
    
    int find = 0;
    for(int i=0; i<query_num; i++){
        for(int j=0; j<data_num; j++){
            if(q[i]==a[j]){
                find++;
                break;
            }
        }
    }
    printf("%d\n", find);
}

