#include <iostream>
#include <stdio.h>

using namespace std;

#define INFTY 2000000000
#define MAX 500000

int count = 0, L[MAX/2 + 2], R[MAX/2 + 2];

void merge(int A[], int left, int mid, int right){
    int n1 = mid - left, n2 = right - mid;
    
    for(int i = 0; i < n1; i++){
        L[i] = A[left + i];
    }
    for(int i = 0; i < n2; i++){
        R[i] = A[mid + i];
    }
    L[n1] = INFTY;
    R[n2] = INFTY;
    int i = 0;
    int j = 0;
    for(int K = left; K < right; K++){
        if(L[i] <= R[j]){
            A[K] = L[i];
            i++;
            count++;
        }
        else{
            A[K] = R[j];
            j++;
            count++;
        }
    }
}
void mergeSort(int A[], int left, int right){
    if(left + 1 < right){
        int mid = (left + right)/2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}
int main(void){
    // Your code her
    int n, A[MAX];
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++)scanf("%d", &A[i]);
    
    mergeSort(A, 0, n);
    
    for(int i = 0; i < n; i++){
        if(i > 0) printf(" ");
        printf("%d", A[i]);
    }
    
    printf("\n%d",count);
    printf("\n");
}
