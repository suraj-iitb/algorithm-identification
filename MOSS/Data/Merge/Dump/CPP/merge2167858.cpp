#include <iostream>
#include <cstdio>
using namespace std;
 
int A[500000], S = 0;
 
int merge(int l, int m, int r){
    int n1 = m - l, n2 = r - m, i, j;
    int L[n1 + 1], R[n2 + 1];
    for(i = 0;i < n1;i++)L[i] = A[i + l];
    for(i = 0;i < n2;i++)R[i] = A[i + m];
    i = j = 0;
    for(int k = 0;k < r - l;k++, S++){
        if(j == n2 || (i < n1 && L[i] <= R[j]))A[k + l] = L[i++];
        else A[k + l] = R[j++];
    }
}

int mergeSort(int l, int r){
    if(l + 1 < r){
        int m = (l + r) / 2;
        mergeSort(l, m);
        mergeSort(m, r);
        merge(l, m, r);
    }
}
 
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0;i < n;i++)scanf("%d", &A[i]);
    mergeSort(0, n);
    for(int i = 0;i < n;i++){
        if(i)printf(" ");
        printf("%d", A[i]);
    }
    printf("\n%d\n", S);
     
    return 0;
}
