#include<stdio.h>

typedef struct Card{
    int num;
    char suit;
} Card;

int partition(Card *A, int p, int r){
    Card x = A[r];
    int i = p-1;
    Card temp;
    for(int j = p; j < r; j++){
        if(A[j].num <= x.num){
            i++;
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    temp = A[i+1];
    A[i+1] = A[r];
    A[r] = temp;
    return i+1;
}

void quicksort(Card *A, int p, int r){
    if(p < r){
        int q = partition(A, p, r);
        quicksort(A, p, q-1);
        quicksort(A, q+1, r);
    }
}

void merge(Card *A, int left, int mid, int right){
    int n1 = mid -left;
    int n2 = right - mid;
    Card L[n1+1], R[n2+1];
    for(int i = 0; i < n1; i++){
        L[i] = A[left+i];
    }
    for(int i = 0; i < n2; i++){
        R[i] = A[mid+i];
    }
    int i = 0;
    int j = 0;
    L[n1].num = 2000000000;
    R[n2].num = 2000000000;
    for(int k = left; k < right; k++){
        if(L[i].num <= R[j].num){
            A[k] = L[i];
            i++;
        }
        else{
            A[k] = R[j];
            j++;
        }
    }
}

void mergeSort(Card *A, int left, int right){
    if(left+1 < right){
        int mid = (left+right)/2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int main(void){
    int n;
    scanf("%d",&n);
    Card A[n], B[n];
    char S[10];
    for(int i = 0; i < n; i++){
        scanf("%s %d",S, &A[i].num);
        A[i].suit = S[0];
        B[i] = A[i];
    }
    quicksort(A, 0, n-1);
    mergeSort(B, 0, n);
    int flag = 0;
    for(int i = 0; i < n; i++){
        if(A[i].suit != B[i].suit){
            flag++;
        }
    }
    if(flag){
        printf("Not stable\n");
    }
    else{
        printf("Stable\n");
    }
    for(int i = 0; i < n; i++){
        printf("%c %d\n", A[i].suit, A[i].num);
    }
    return 0;
}
