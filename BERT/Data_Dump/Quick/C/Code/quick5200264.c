#include<stdio.h>
#define INFTY 1000000001
#define MIN 1

typedef struct{
    char suit;
    int value;
}Card;

void Swap(int* x, int* y){
    int tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}

void merge(Card A[], int left, int mid, int right){
    int n1, n2, i, j, p;
    n1 = mid - left;
    n2 = right - mid;
    Card L[n1 + 1], R[n2 + 1];
    for(i = 0; i < n1; i++){
        L[i] = A[left + i];
    }
    for(i = 0; i < n2; i++){
        R[i] = A[mid + i];
    }
    L[n1].value = INFTY;
    R[n2].value = INFTY;
    i = 0; j = 0;
    for(int k = left; k < right; k++){
        if(L[i].value <= R[j].value){
            p++;
            A[k] = L[i];
            i++;
        }else{
            A[k] = R[j];
            j++;
        }
    }
}

void mergeSort(Card A[], int left, int right){
    int times;
    if(left + 1 < right){
        int mid = (left + right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int partition(Card A[], int p, int r){
    int x = A[r].value;
    int i = p - 1;
    char c;
    for(int j = p; j < r; j++){
        if(A[j].value <= x){
            i++;
            Swap(&A[i].value, &A[j].value);
            c = A[i].suit; A[i].suit = A[j].suit; A[j].suit = c;
        }
    }
    Swap(&A[i+1].value, &A[r].value);
    c = A[i+1].suit; A[i+1].suit = A[r].suit; A[r].suit = c;
    return i+1;
}

void quickSort(Card A[], int p, int r){
    if(p < r){
        int q = partition(A, p, r);
        quickSort(A, p, q-1);
        quickSort(A, q+1, r);
    }
}

int judge(Card card[], Card scard[], int n){
    int i;
    for(i = 0; i < n; i++){
        if(card[i].suit != scard[i].suit) return 0;
    }
    return 1;
}

void print(Card card[], int n){
    int i;
    for(i = 0; i < n; i++){
        printf("%c %d\n", card[i].suit, card[i].value);
    }
}

int main(){
    int n, i;
    scanf("%d", &n);
    Card card[n], scard[n];
    char S[10];
    for(i = 0; i < n; i++){
        scanf("%s %d", S, &card[i].value);
        scard[i].suit = card[i].suit = S[0];
        scard[i].value = card[i].value;
    }
    quickSort(card, 0, n-1);
    mergeSort(scard, 0, n);
    if(judge(card, scard, n)) printf("Stable\n");
    else printf("Not stable\n");

    print(card, n);

    return 0;
}

