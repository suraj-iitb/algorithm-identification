#include<stdio.h>
int selectionSort(int[], int);
int main(void){
    int a[100], i, n, sw;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &a[i]);
    } 
    sw = selectionSort(a, n);
    for(i=0;i<n;i++) {
        if(i){
            printf(" ");
        }
        printf("%d",a[i]);
    }
    printf("\n%d\n",sw);
    return 0;
}
int selectionSort(int a[], int N){
    int i, j, sw = 0, minj, t;
    for(i = 0; i < N-1; i++){
        minj = i;
        for(j=i;j<N;j++){
            if(a[j]<a[minj]){
                minj=j;
            }
        }
        t = a[i];
        a[i] = a[minj];
        a[minj] = t;
        if(i != minj){
            sw++;
        }
    }
    return sw;
}
