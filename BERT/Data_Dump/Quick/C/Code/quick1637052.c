#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>



typedef struct CARD{
    int num;
    char var;
}CARD;

#define NUM 100000

CARD A[NUM + 1];
CARD B[NUM + 1];

#define SENT 1000000000


void merge(CARD A[], int first, int mid, int last){
    
    int i,j,k, former, latter;
    CARD *L, *R, sent;
    
    sent.num = SENT;
    
    former = mid - first + 1;
    latter = last - mid;
    
    L = (CARD*)malloc(sizeof(CARD) * (former+1));
    R = (CARD*)malloc(sizeof(CARD) * (latter+1));
    
    for (i=0; i < former; i++) {
        L[i] = A[first + i];
    }
    L[former] = sent;
    
    for (i=0; i < latter; i++) {
        R[i] = A[i + mid + 1];
    }
    R[latter] = sent;
    
    j=k=0;
    for (i = first; i < last + 1; i++) {
        if (L[j].num <= R[k].num) {
            A[i] = L[j];
            j++;
        }
        else
        {
            A[i] = R[k];
            k++;
        }
    }
    return;
    
}

void MergeSort(CARD A[], int first, int last){
    
    int mid;
    
    if (first < last) {
        mid = (first + last)/2;
        MergeSort(A, first, mid);
        MergeSort(A, mid+1, last);
        merge(A, first, mid, last);
    }
    
    return;
}

int checkStable(CARD *A, CARD * B, int N){
    
    int  i = 0;
    int ans = 1;
    
    for (i = 0; i < N; i++) {
        if(A[i].num == B[i].num && A[i].var == B[i].var){
            continue;
        }
        else{
            ans = 0;
            break;
        }
    }
    return ans;
}

/*
 * *A int type array
 * left?????????A????????????????´??????????
 * right?????????A????????????????´??????????
 */
int partition(CARD *A, int left, int right){
    
    /*pivot??¨?????????????????????????´?????????¶*/
    CARD pivot = A[right];
    int i = left - 1;
    int j;
    CARD tmp;
    
    for (j=left; j<right; j++) {
        if (A[j].num <= pivot.num) {
            i = i+1;
            /* A[i] ??¨ A[j] ????????? */
            tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
        }
    }
    
    /* A[i+1] ??¨ A[r] ????????? */
    tmp = A[i+1];
    A[i+1] = A[right];
    A[right] = tmp;
    
    return i+1;   
}

/*
 * *A int type array
 * left?????????A????????????????´??????????
 * right?????????A????????????????´??????????
 */
void quicksort(CARD * A, int left, int right){
    
    int q;
    if (left < right) {
        q = partition(A, left, right);
        quicksort(A, left, q-1);
        quicksort(A, q+1, right);
    }
    
}


int main( ){
    
    int i, n, isStable;
    isStable = 1;
    
    scanf("%d", &n);
    
    for (i=0; i<n; i++) {
        while (!getchar());
        scanf("%c %d", &(A[i].var), &(A[i].num) );
    }
    
    memcpy(B, A, sizeof(CARD)*n);
    
    quicksort(A, 0, n-1);
    MergeSort(B, 0, n-1);
    
    isStable = checkStable(A, B, n);
    
    if (isStable) {
        printf("%s\n", "Stable");
    }
    else{
        printf("%s\n", "Not stable");
    }
    
    
    for (i=0; i<n; i++) {
        printf("%c %d\n", A[i].var, A[i].num);
    }
    
    return 0;
}
