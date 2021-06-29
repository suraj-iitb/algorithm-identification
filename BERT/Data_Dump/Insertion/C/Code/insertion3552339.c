#include <stdio.h>
#include <stdlib.h>

void insertionSort(int a[], int n);
int main(void){
    int n, i;

    scanf("%d", &n);
    int a[n]; // a を宣言
    for(i=0; i<n;i++)
        scanf("%d", &a[i]);
    insertionSort(a,n);
    return 0;
}

void insertionSort(int a[], int n){
    int i, j, v;

    for(i=0; i<n; i++){
        v = a[i];
        j = i-1;
        while(j>=0 && a[j]>v){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
        // 数列表示
        printf("%d", a[0]);
        for(j=1; j<n; j++)
            printf(" %d", a[j]);
        printf("\n");
    }
}
