#include<stdio.h>
void print_array(int[], int);
void swap(int*, int*);
int main(void){
    int i, j, N, count = 0, flag = 1;
    int data[100];

    scanf("%d", &N);
    for(i = 0; i < N; i++){
        scanf("%d", &data[i]);
    }
    while(flag){
        flag = 0;
        for(j = N - 1; j > 0; j--){
            if(data[j] < data[j - 1]){
                swap(&data[j] , &data[j - 1]);
                count++;
                flag = 1;
            }
        }
    }
    print_array(data, N);
    printf("%d\n", count);
    return 0;
}
void swap(int *a, int *b){
    int t;
    t = *a;
    *a = *b;
    *b = t;
    return;
}
void print_array(int a[], int n){
    int i = 1;
    printf("%d", a[0]);
    while(i < n){
        printf(" %d", a[i]);
        i++;
    }
    printf("\n");
    return;
}
