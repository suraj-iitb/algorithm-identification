#include "stdio.h"
#include "stdlib.h"

int a[100];
int N;
int count;

void printResult(){
    for(int i=0; i<N; i++){
        if(i != N-1){
            printf("%d ", a[i]);
        }
        else{
            printf("%d\n", a[i]);
        }
    }
}

int main(){
    //freopen("D:\\zhouyu\\study\\codes\\BubbleSort.txt", "r", stdin);
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d", &a[i]);
    }
    int flag = 1;
    int i=0;
    int j;
    count = 0;
    while(flag == 1){
        //printResult();
        flag = 0;
        for(j=N-1; j>i; j--){
            if(a[j] < a[j-1]){
                count++;
                flag = 1;
                a[j] = a[j] ^ a[j-1];
                a[j-1] = a[j] ^ a[j-1];
                a[j] = a[j] ^ a[j-1];
            }
        }
    }
    printResult();
    printf("%d\n", count);
    return 0;
}


