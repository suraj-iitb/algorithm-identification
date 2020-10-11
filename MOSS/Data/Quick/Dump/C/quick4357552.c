#include <stdio.h>
#define MAX 100000
#define sentinel 1000000001

typedef struct{
    char suit;
    int value;
}CARD;

CARD LEFT[MAX / 2 + 2], RIGHT[MAX / 2 + 2];


int partetion(CARD *A, int p, int r);
void quickSort(CARD *A, int p, int r);
void merge(CARD *A, int left, int mid, int right);
void mergeSort(CARD *A, int left, int right);
void check_stable(CARD *A, CARD *B, int n);


int partetion(CARD *A, int p, int r){
    int x = A[r].value;
    int i = p - 1;
    CARD tmp;
    int j;

    for(j = p; j < r; j++){
        if(A[j].value <= x){
            i++;
            tmp = A[i];
            //printf("tmp %c %d \n", tmp.suit, tmp.value);
            A[i] = A[j];
            A[j] = tmp;
            //printf("%d  A[j] %c %d \n", i, A[j].suit, A[j].value);
        }
    }

    // for(int k = 0; k < 6; k++){
    //     printf("%c %d  ", A[k].suit, A[k].value);
    // }
    // putchar('\n');

    i++;
    
    tmp = A[i];
    A[i] = A[r];
    A[r] = tmp;

    // for(int k = 0; k < 6; k++){
    //     printf("%c %d  ", A[k].suit, A[k].value);
    // }
    // putchar('\n');
    //printf("i = %d\n", i);
    return i;
}

void quickSort(CARD *A, int p, int r){
    if (p >= r){
        return;
    }
    int q = partetion(A, p, r);
    //printf("%d\n", q);
    quickSort(A, p, q - 1);
    quickSort(A, q + 1, r);
    
}

void merge(CARD *A, int left, int mid, int right){

    int n1 = mid - left;
    int n2 = right - mid;
    int k, i, j;


    // printf("LEFT: ");
    for(i = 0; i < n1; i++){
        LEFT[i] = A[left + i];
        // printf("%d  ", LEFT[i].value);
    }
    // printf("LEFT index  %d ", i);
    // printf("last i : %d\n", i);
    // i++;
    LEFT[i].value = sentinel;
    // printf("%d  ", LEFT[i].value);
    // putchar('\n');

    // printf("RIGHT: ");
    for(i = 0; i < n2; i++){
        RIGHT[i] = A[mid + i];
        // printf("%d  ", RIGHT[i].value);
    }
    // printf("RIGHT index  %d  ", i);
    // i++;
    RIGHT[i].value = sentinel;
    // printf("RIGHT[%d]  %d  ", i, RIGHT[i].value);
    // putchar('\n');


    i = 0;
    j = 0;
    for(k = left; k < right; k++){
        if(LEFT[i].value <= RIGHT[j].value){
            // printf("LEFT[%d] %c %d  ", i, LEFT[i].suit, LEFT[i].value);
            A[k] = LEFT[i];
            i++;
        }else{
            // printf("RIGHT[%d] %c %d  LEFT[%d] %c %d  ", j, RIGHT[j].suit, RIGHT[j].value, i, LEFT[i].suit, LEFT[i].value);
            A[k] = RIGHT[j];
            j++;
        }
    }
    // putchar('\n');


}

void mergeSort(CARD *A, int left, int right){
    if(left + 1 < right){
        int mid = (left + right) /2;

        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);

        // for(int i = 0; i < right - left; i++){
        //     printf("%c %d  ", A[i].suit, A[i].value);
        // }   
        // putchar('\n');
    }
}

void check_stable(CARD *A, CARD *B, int n){
    int i;
    for (i = 0; i < n; i++){
        if(A[i].suit != B[i].suit){
            printf("Not stable\n");
            // printf("%c %d : %c %d \n", A[i].suit, A[i].value, B[i].suit, B[i].value);
            return;
        }
    }
    printf("Stable\n");
}

int main(void){
    int n;
    CARD A[MAX];
    CARD B[MAX];

    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%s %d", &A[i].suit, &A[i].value);
        B[i].suit = A[i].suit;
        B[i].value = A[i].value;
    }

    //printf("before quick\n");
    quickSort(A, 0, n - 1);

    
    mergeSort(B, 0, n);
    // mergeSort(A, 0, n);

    // for(int i = 0; i < n; i++){
    //     printf("%c %d  ", B[i].suit, B[i].value);
    // }   
    // for(int i = 0; i < n; i++){
    //     printf("%c %d  ", A[i].suit, A[i].value);
    // }  
    // putchar('\n');

    check_stable(A, B, n);

    for(int i = 0; i < n; i++){
        printf("%c %d\n", A[i].suit, A[i].value);
    }   
    // putchar('\n');


    return 0;
}

/*
6
D 3
H 2
D 1
S 3
D 2
C 1
*/
