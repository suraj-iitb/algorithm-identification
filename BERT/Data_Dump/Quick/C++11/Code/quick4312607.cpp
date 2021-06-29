#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

struct Card {
    char suit;
    int value;
};
void deepCopy(Card A[] ,Card B[],int n){
    for(int i = 0; i < n ; i++){
        B[i].suit = A[i].suit;
        B[i].value = A[i].value;
    }
}
void swap(Card A[], int i, int j) {
    Card temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}
int partition(Card A[], int p, int r) {
    Card x = A[r];
    int i = p - 1;
    for(int j = p; j < r; j++) {
        if(A[j].value <= x.value) {
            i++;
            swap(A, i, j);
        }
    }
    i++;
    swap(A, i, r);
    return i;
}
void quicksort(Card A[],int p,int r){
    if(p<r){
        int q = partition(A,p,r);
        quicksort(A,p,q-1);
        quicksort(A,q+1,r);
    }else{
        return ;
    }
}
void merge(Card A[], int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;
    Card L[n1 + 1], R[n2 + 1];

    for(int i = 0; i < n1; i++) {
        L[i] = A[left + i];
    }
    for(int i = 0; i < n2; i++) {
        R[i] = A[mid + i];
    }
    L[n1].value = INT32_MAX;
    R[n2].value = INT32_MAX;
    int i = 0;
    int j = 0;
    for(int k = left; k < right; k++) {
        if(L[i].value <= R[j].value) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }
}
void mergesort(Card A[], int left, int right) {
    if(left + 1 < right) {
        int mid = (left + right) / 2;
        mergesort(A, left, mid);
        mergesort(A, mid, right);
        merge(A, left, mid, right);
    } else {
        return;
    }
}
int main() {
    int n;
    cin >> n;
    Card A[n];
    Card B[n];
    for(int i = 0; i < n; i++) {
        scanf("%s %d", &A[i].suit,&A[i].value);
    }
    deepCopy(A,B,n);
    quicksort(A,0,n-1);
    mergesort(B,0,n);
    
    bool isStable = true;
    for(int i = 0; i < n ; i++){
        if(A[i].suit != B[i].suit){
            isStable = false;
            break;
        }
    }
    if(isStable){
        cout << "Stable" << endl;
    }else{
        cout << "Not stable" << endl;
    }
    for(int i=0; i<n; i++){
        printf("%c %d\n",A[i].suit,A[i].value);
    }
}
