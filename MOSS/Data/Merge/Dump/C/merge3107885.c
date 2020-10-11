#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
int cnt = 0;
void merge(int a[], int left, int mid, int right){
    int i = left;
    int j = mid+1;
    int t[n];
    int k = 0;
    while(i <= mid && j <= right){
        if(a[i] <= a[j]) t[k++] = a[i++];
        else t[k++] = a[j++];
    }
    while(i <= mid) t[k++] = a[i++];
    while(j <= right) t[k++] = a[j++];

    for(int p = 0; p < k; p++){
        *(a+left+p) = t[p];
        cnt++;
    }
}
void mergeSort(int a[], int left, int right){
    if(left < right){
        int mid = (left + right) / 2;
        mergeSort(a, left, mid);
        mergeSort(a, mid+1, right);
        merge(a, left, mid, right);
    }
}
int main(){
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    int left = 0;
    int right = n-1;
    mergeSort(a, left, right);
    for(int i = 0; i < n; i++) {
        printf("%d", a[i]);
        if(i == n-1) printf("\n");
        else printf(" ");
    }
    printf("%d\n", cnt);
    return 0;
}
