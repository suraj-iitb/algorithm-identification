#include <stdio.h>
#define MAXCARD 100010
#define INF 2000000000

struct Card {
    int value;
    char type;
};
typedef struct Card card_t;


card_t A[MAXCARD]; // for quickSort
card_t B[MAXCARD]; // for mergeSort
card_t L[MAXCARD/2], R[MAXCARD/2];


void swap(int a, int b)
{
    card_t t = A[a];
    A[a] = A[b];
    A[b] = t;
}

void merge(card_t B[], int l, int m, int r)
{
    int i, j, k;
    
    for (i = 0; i < m-l; i++) L[i] = B[l+i];
    for (i = 0; i < r-m; i++) R[i] = B[m+i];
    
    L[m-l].value = R[r-m].value = INF;
    
    for (i=j=0, k=l; k < r; k++) {
        if (L[i].value <= R[j].value) {
            B[k] = L[i++];
        }
        else {
            B[k] = R[j++];
        }
    }
}

void mergeSort(card_t B[], int l, int r)
{
    if (l+1 < r) {
        int m = (l+r)/2;
        mergeSort(B, l, m);
        mergeSort(B, m, r);
        merge(B, l, m, r);
    }
}


int partition(card_t A[], int p, int q)
{
    int x, i, j;
    x = A[q].value;
    i = p-1;
    for (j = p; j < q; j++) {
        if (A[j].value <= x) {
            i++;
            swap(i, j);
        }
    }
    swap(q, i+1);
    return i+1;
}

void quickSort(card_t A[], int p, int r) 
{
    if (p < r) {
        int q = partition(A, p, r);
        quickSort(A, p, q-1);
        quickSort(A, q+1, r);
    }
}

int main()
{
    int i;    
    int N;
    
    scanf("%d", &N);
    getchar();
    for (i = 0; i < N; i++) {
        scanf("%c %d", &A[i].type, &A[i].value);
        getchar();
        B[i] = A[i];
    }
    
    quickSort(A, 0, N-1);
    mergeSort(B, 0, N);
    
    /*
    puts("quickSort");
    for (i = 0; i < N; i++) {
        printf("%c %d\n", A[i].type, A[i].value);
    }
    puts("mergeSort");
    for (i = 0; i < N; i++) {
        printf("%c %d\n", B[i].type, B[i].value);
    }
    */
    
    int isStable = 1;
    for (i = 0; i < N; i++) {
        if (A[i].type != B[i].type) {
            isStable = 0;
            break;
        }
    }
    if (isStable) {
        puts("Stable");
    } else {
        puts("Not stable");
    }
    
    for (i = 0; i < N; i++) {
        printf("%c %d\n", A[i].type, A[i].value);
    }
    
    return 0;
}
