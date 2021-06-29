#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

//============================================================================
#define pred(x) ((x)-1)
#define succ(x) ((x)+1)
//============================================================================
typedef struct{
    long number;
    char suit;
    long order;
}TCard;
//----------------------------------------------------------------------------
const char suits[5]="SHCD";
//----------------------------------------------------------------------------
void exchange(TCard *x, TCard *y)
{
    TCard z;
    z=*x, *x=*y, *y=z;
}
//----------------------------------------------------------------------------
long Partition(TCard *A, long p,  long r)
{
    long i,j,x;

    x = A[r].number;
    i = p-1;
    for (j = p; j<r; j++)
        if (A[j].number <= x){
            i++;
            exchange(&A[i], &A[j]);
        }
    exchange(&A[i+1], &A[r]);
    return i+1;
}
//----------------------------------------------------------------------------
void Quicksort(TCard *A, long p, long r)
{
    long q;

    if (p<r){
        q = Partition(A, p, r);
        Quicksort(A, p, q-1);
        Quicksort(A, q+1, r);
    }
}
//----------------------------------------------------------------------------
/*
12
13 19 9 5 12 8 7 4 21 2 6 11
*/
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
void input(FILE *file)
{
    long i,n,x; TCard *A; char buffer[20];

    fgets(buffer, sizeof(buffer)-1, file);
    sscanf(buffer, "%ld", &n);
    A = malloc(succ(n)*sizeof(TCard));
    for (i=0; i<n; i++){
        fgets(buffer, sizeof(buffer)-1, file);
        sscanf(buffer, "%c",  &A[i].suit);
        sscanf(buffer+2, "%ld", &A[i].number);
        A[i].order=i;
    }
    Quicksort(A, 0, pred(n));
    for (i=x=0; i<n && !x; i++){
        if (A[i].number==A[succ(i)].number)
            if (A[i].order>A[succ(i)].order)
                x++;
    }
    printf("%s\n", (x)?"Not stable":"Stable");
    for (i=0; i<n; i++){
        printf("%c %d\n", A[i].suit, A[i].number);
    }
    //printf("\n");
    free(A);
}
//============================================================================
#ifndef DESKTOP
int main()
{
    input(stdin);
    return 0;
}
#endif
