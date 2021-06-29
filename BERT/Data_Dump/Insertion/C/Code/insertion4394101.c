#include<stdio.h>
void print_array(int[], int);
int main(void){
    int N, v, i = 0, j;
    int A[100];

    scanf("%d", &N);
    while(i < N){
        scanf("%d", &A[i]);
        i++;
    }
    print_array(A, N);
    for(i = 1; i < N; i++){
        v = A[i];
        j = i - 1;
        while(j >= 0 && A[j] > v){
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;
        print_array(A, N);
    }
    return 0;
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
