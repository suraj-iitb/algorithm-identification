#include <stdio.h>
#include <string.h>

typedef struct{
    char name;
    int num, id;
}card;

void swap(card* A, card* B){
    card tmp = *A;
    *A = *B;
    *B = tmp;

}

int partition(card* A, int p, int r){
    int x = A[r].num, i = p-1;
    for(int j=p ; j<r ; j++){
        if(A[j].num <= x){
            i++;
            swap(&A[i], &A[j]);
        }
    }
    swap(&A[i+1], &A[r]);
    return i+1;
}

void quicksort(card* A, int p, int r){
    if(p<r){
        int q = partition(A, p, r);
        quicksort(A, p, q-1);
        quicksort(A, q+1, r);
    }
}

int checkstable(card* A, int n){
    for(int i=0 ; i<n-1 ; i++)
        if(A[i].num == A[i+1].num && A[i].id > A[i+1].id)
            return 1;
    
    return 0;
}

int main(void){
    int n;
    scanf("%d", &n);
    card A[n];
    for(int i=0 ; i<n ; i++){
        scanf("%s %d", &A[i].name, &A[i].num);
        A[i].id = i;
    }

    quicksort(A, 0, n-1);
    checkstable(A, n) == 1 ? printf("Not stable\n") : printf("Stable\n");

    for(int i=0 ; i<n ; i++)
        printf("%c %d\n", A[i].name, A[i].num);

    return 0;
}


