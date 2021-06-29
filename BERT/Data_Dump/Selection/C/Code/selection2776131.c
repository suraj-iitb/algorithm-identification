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
    //freopen("D:\\zhouyu\\study\\codes\\SortSample.txt", "r", stdin);
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d", &a[i]);
    }
    count = 0;
    int minIndex;
    for(int i=0; i<N; i++){
        minIndex = i;
        for(int j=i+1; j<N; j++){
            if(a[j] < a[minIndex]){
                minIndex = j;
            }
        }
        if(minIndex != i){
            count++;
            a[i] = a[i] ^ a[minIndex];
            a[minIndex] = a[i] ^ a[minIndex];
            a[i] = a[i] ^ a[minIndex];
        }
    }
    printResult();
    printf("%d\n", count);
    return 0;
}


