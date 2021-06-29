#include <iostream>
using namespace std;
#include <cstdio>
#include <cmath>

const int MaxFact = pow(10, 9);

struct Card{
    char suit;
    int value;
};
int partition(Card A[], int p, int r){
    int x = A[r].value;
    Card t;
    int i = p-1;
    for(int j=p; j<r; j++){
        if(A[j].value <= x){
            i++;
            t = A[i]; A[i] = A[j]; A[j] = t;
        }
    }
    t = A[i+1]; A[i+1] = A[r]; A[r] = t;
    return i+1;
}
void quicksort(Card A[], int p, int n){
    if(p < n){
        int keyindex = partition(A, p, n-1);
        quicksort(A, p, keyindex);
        quicksort(A, keyindex+1, n);
    }
}
void merge(Card A[], int left, int mid, int right){
    int n1 = mid - left;
    int n2 = right - mid;
    Card L[n1 + 1], R[n2 + 1];
    for(int i=0; i<n1; i++){
        L[i] = A[left + i];
    }
    for(int i=0; i<n2; i++){
        R[i] = A[mid + i];
    }
    L[n1].value = MaxFact;
    R[n2].value = MaxFact;
    int l=0, r=0;
    for(int i=left; i<right; i++){
        if(L[l].value <= R[r].value){
            A[i] = L[l];
            l++;
        } else {
            A[i] = R[r];
            r++;
        }
    }
}
void mergesort(Card A[], int left, int right){
    if(left + 1 < right){
        int mid = (left + right) / 2;
        mergesort(A, left, mid);
        mergesort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int main(){
    int n, v;
    char str[2];
    scanf("%d", &n);
    Card A[n], B[n];
    for(int i=0; i<n; i++){
        scanf("%s %d", str, &v);
        A[i].suit = B[i].suit = str[0];
        A[i].value = B[i].value = v;
    }
    mergesort(B, 0, n);
    quicksort(A, 0, n);

    int stable = 1;
    for(int i=0; i<n; i++){
        if(A[i].suit != B[i].suit){
            stable = 0;
        }
    }
    if(stable){printf("Stable\n");}
    else {printf("Not stable\n");}

    for(int i=0; i<n; i++){
        printf("%c %d\n", A[i].suit, A[i].value);
    }

    
    return 0;
}
