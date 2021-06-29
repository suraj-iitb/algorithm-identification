#include<stdio.h>
void swap(int[], int);
void trace(int[], int);
int main(void){
    int N, i;
    int a[100];
    scanf("%d", &N);
    for(i = 0; i < N; i++){
        scanf("%d", &a[i]);
    }
    trace(a, N);
    swap(a, N);
}
void swap(int a[],int N){
    int i, j, v;
    for(i  = 1; i < N; i++){
        v = a[i];
        for(j = i -1; j >= 0 && a[j] > v; j--){
            a[j + 1] = a[j];
        }
        a[j + 1] = v;
        trace(a, N);
    }
    return;
}
void trace(int a[], int N){
    int i;
    for(i = 0; i < N - 1; i++){
        printf("%d ", a[i]);
    }
    printf("%d\n", a[i++]);
    return;
}

