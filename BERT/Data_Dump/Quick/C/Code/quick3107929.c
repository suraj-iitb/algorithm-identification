#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    char a;
    int b;
}re;
int n;
void merge(re a[], int left, int mid, int right){
    int i = left;
    int j = mid+1;
    re t[n];
    int k = 0;
    while(i <= mid && j <= right){
        if(a[i].b <= a[j].b) t[k++] = a[i++];
        else t[k++] = a[j++];
    }
    while(i <= mid) t[k++] = a[i++];
    while(j <= right) t[k++] = a[j++];

    for(int p = 0; p < k; p++){
        a[left + p] = t[p];
    }
}
void mergeSort(re a[], int left, int right){
    if(left < right){
        int mid = (left + right) / 2;
        mergeSort(a, left, mid);
        mergeSort(a, mid+1, right);
        merge(a, left, mid, right);
    }
}

int partition(re a[], int p, int r){
    int i = p-1;
    int x = a[r].b;
    for(int j = p; j < r; j++){
        if(a[j].b <= x){
            i++;
            re t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }
    re temp = a[i+1];
    a[i+1] = a[r];
    a[r] = temp;
    return i+1;
}
void quickSort(re a[], int p, int r){
    if(p < r){
        int q = partition(a, p, r);
        quickSort(a, p, q-1);
        quickSort(a, q+1, r);
    }
}
int main(){
    scanf("%d", &n);
    re a[n];
    re b[n];
    re c[n];
    for(int i = 0; i < n; i++){
        char ch; int d;
        getchar();
        scanf("%c %d", &ch, &d);
        a[i].a = ch, b[i].a = ch, c[i].a = ch;
        a[i].b = b[i].b = c[i].b = d;
    }

    mergeSort(b, 0, n-1);
    quickSort(c, 0, n-1);
    int flag = 1;
    for(int i = 0; i < n; i++){
        if(b[i].a != c[i].a || b[i].b != c[i].b ){
            flag = 0;break;
        }
    }
    if(flag) printf("Stable\n");
    else printf("Not stable\n");
    for(int i = 0; i < n; i++){
        printf("%c %d\n", c[i].a, c[i].b);
    }
    return 0;
}
