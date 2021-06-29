#include<stdio.h>
#include<stdlib.h>

#define MAX 100001

typedef struct{
    char mark;
    int num;
    int sta;
} card;

int partition(card *A, int p, int r){
    int x, i, j;
    card tmp1, tmp2;

    x = A[r].num;
    i = p-1;

    for(j=p; j<=r-1; j++){
        if(A[j].num <= x){
            i = i+1;
            tmp1 = A[i];
            A[i] = A[j];
            A[j] = tmp1;
        }
    }

    tmp2 = A[i+1];
    A[i+1] = A[r];
    A[r] = tmp2;

    return i+1;
}

void quicksort(card *A, int p, int r){
    int q;

    if(p < r){
        q = partition(A, p, r);
        quicksort(A, p, q-1);
        quicksort(A, q+1, r);
    }
}


int main(){
    int n, i, flag = 0;
    card A[MAX];

    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf(" %c%d", &A[i].mark, &A[i].num);
        A[i].sta = i;
    }

    quicksort(A, 0, n-1);

    for(i=0; i<n; i++){
        if(A[i].num == A[i+1].num){
            if(A[i].sta > A[i+1].sta){
                flag = 1;
            }
        }
    }

    if(flag == 0){
        printf("Stable\n");
    }else{ 
        printf("Not stable\n");
    }

    for(i=0; i<n; i++){
        printf("%c %d\n", A[i].mark, A[i].num);
    }

    return 0;
}

