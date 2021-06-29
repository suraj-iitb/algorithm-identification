#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
#define MAX 500000
#define SENTINEL 2000000000

int L[MAX/2+2], R[MAX/2+2];
int cnt = 0;
void merge(int a[], int left, int mid, int right){
    int n1 = mid - left;
    int n2 = right - mid;
    for(int i=0; i<n1; i++)
        L[i] = a[left+i];
    for(int i=0; i<n2; i++)
        R[i] = a[mid+i];
    L[n1] = R[n2] = SENTINEL;

    int i=0, j=0;
    for(int k=left; k<right; k++){
        cnt++;
        if(L[i] <= R[j])
            a[k] = L[i++];
        else
            a[k] = R[j++];
    }
}

void mergeSort(int a[], int left, int right){
    if(left+1 < right){
        int mid = (left+right) / 2;
        mergeSort(a, left, mid);
        mergeSort(a, mid, right);
        merge(a, left, mid, right);
    }
}

int main(int argc, char *argv[]){
    int n, a[MAX];
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d", &a[i]);
    mergeSort(a, 0, n);
    int i;
    for(i=0; i<n-1; i++)
        printf("%d ",a[i]);
    printf("%d\n%d\n", a[i], cnt);

    return 0;
}
