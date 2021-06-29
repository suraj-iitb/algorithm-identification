#include <stdio.h>
#include <string.h>

typedef struct _CARD {
    char kind;
    int num;
    int order;
} CARD;

CARD card[100000];

int partition(CARD *A, int p, int r)
{
    int x, i, j;
    CARD t;

    x = A[r].num;
    i = p - 1;
    for (j = p; j < r; j++){
        if (A[j].num <= x){
            i++;
            t = A[i];
            A[i] = A[j];
            A[j] = t;
         }
    }
    
    t = A[i + 1];
    A[i + 1] = A[r];
    A[r] = t;
    
    return (i + 1);
}


void quickSort(CARD *A, int p, int r)
{
    int q;
    
    if (p < r){
        q = partition(A, p, r);
        quickSort(A, p, q - 1);
        quickSort(A, q + 1, r);
    }
}

int main(void)
{
    int n;
    char kind[2];
    int num;
    int flag;
    int i;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++){
        scanf("%s%d", kind, &num);
        
        card[i].kind = kind[0];
        card[i].num = num;
        card[i].order = i;
    }
    quickSort(card, 0, n - 1);

    flag = 0;
    for (i = 1; i < n; i++){
        if (card[i - 1].num == card[i].num){
            if (card[i - 1].order > card[i].order){
                flag = 1;
                break;
            }
        }
    }
        
    if (flag == 0){
        printf("Stable\n");
    }
    else {
        printf("Not stable\n");
    }
    
    for (i = 0; i < n; i++){
        printf("%c %d\n", card[i].kind, card[i].num);
    }

    return (0);
}

