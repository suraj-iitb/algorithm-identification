#include <iostream>
#include <stdio.h>

using namespace std;

#define INFTY 2000000000
#define MAX 100000

struct Card {
    char suit;
    int value;
};

Card L[MAX/2 + 2], R[MAX/2 + 2];

int partition(Card A[], int p, int r){
    int j, i;
    Card x, t;
    x = A[r];
    i = p - 1;
    for(j = p; j < r; j++){
        if(A[j].value <= x.value){
            i++;
            t = A[i];
            A[i] = A[j];
            A[j] = t;
        }
    }
    t = A[i+1];
    A[i+1] = A[r];
    A[r] = t;
    return i + 1;
}
void merge(Card A[], int left, int mid, int right){
    int n1 = mid - left, n2 = right - mid;
    
    for(int i = 0; i < n1; i++){
        L[i] = A[left + i];
    }
    for(int i = 0; i < n2; i++){
        R[i] = A[mid + i];
    }
    L[n1].value = INFTY;
    R[n2].value = INFTY;
    int i = 0;
    int j = 0;
    for(int K = left; K < right; K++){
        if(L[i].value <= R[j].value){
            A[K] = L[i];
            i++;
        }
        else{
            A[K] = R[j];
            j++;
        }
    }
}
void mergeSort(Card A[], int left, int right){
    int mid;
    if(left + 1 < right){
        mid = (left + right)/2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}
void quicksort(Card A[], int p, int r){
    int q;
    if(p < r){
        q = partition(A, p, r);
        quicksort(A, p, q-1);
        quicksort(A, q+1, r);
    }
}

int main(void){
    // Your code her
    int n, v;
    Card A[MAX], B[MAX];
    char S[10];
    int stable = 1;
    
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++){
        scanf("%s %d", S, &v);
        A[i].suit = S[0];
        B[i].suit = S[0];
        A[i].value = v;
        B[i].value = v;
    }
    mergeSort(A, 0, n);
    quicksort(B, 0, n - 1);
    
    for(int i = 0; i < n; i++){
        if(A[i].suit != B[i].suit)stable = 0;
    }
    if(stable == 1)printf("Stable\n");
    else printf("Not stable\n");
    for(int i = 0; i < n; i++){
        printf("%c %d\n", B[i].suit, B[i].value);
    }
    
    return 0;
}
