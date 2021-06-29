#include<stdio.h>
#define MAX 100000
#define SENTINEL 2000000000

typedef struct {
    char suit;
    int value;
} Card;

Card L[MAX/2+2], R[MAX/2+2];

void merge(Card A[], int left, int mid, int right){
    int n1 = mid - left;
    int n2 = right - mid;
    int i, j, k;

    for(i = 0; i < n1; i++) L[i] = A[left+i];
    for(i = 0; i < n2; i++) R[i] = A[mid+i];

    L[n1].value = SENTINEL;
    R[n2].value = SENTINEL;

    i = 0;
    j = 0;

    for(k = left; k < right; k++){
        if(L[i].value <= R[j].value){
            A[k] = L[i];
            i++;
        }
        else{
            A[k] = R[j];
            j++;
        }
    }
}
void mergeSort(Card A[], int left, int right){
    if(left + 1 < right){
        int mid = (left + right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}
int partition(Card A[], int p, int r){
    Card t, x;
    x = A[r];
    int i = p - 1;
    int j;
    for(j = p; j < r; j++){
        if(A[j].value <= x.value){
            i++;
            t = A[i]; A[i] = A[j]; A[j] = t;
        }
    }
    i++;
    A[r] = A[i]; A[i] = x;
    return i;
}
void quickSort(Card A[], int left, int right){
    int mid;
    if(left < right){
        mid = partition(A, left, right);
        quickSort(A, left, mid-1);
        quickSort(A, mid+1, right);
    }
}
int main(void){
    int i, n, v;
    Card quick[MAX], merge[MAX];
    char S[4];
    int isStable = 1;

    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%s %d", S, &v);
        quick[i].suit = merge[i].suit = S[0];
        quick[i].value = merge[i].value = v;
    }

    mergeSort(merge, 0, n);
    quickSort(quick, 0, n-1);

    for(i = 0; i < n; i++){
        if(merge[i].suit != quick[i].suit) isStable = 0;
    }

    if(isStable) printf("Stable\n");
    else printf("Not stable\n");
    for(i=0;i<n;i++) {
        printf("%c %d\n",quick[i].suit,quick[i].value);
    }

    return 0;
}
