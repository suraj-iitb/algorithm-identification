#include <stdio.h>
#include <stdlib.h>

#define MAX 100000
#define SENTINEL 2000000000

struct Card{
    char suit;
    int value;
};

struct Card L[MAX / 2 + 2], R[MAX / 2 + 2];

void Merge(struct Card A[],int left , int mid , int right){
    int n1 = mid - left;
    int n2 = right - mid;
    for(int i = 0; i < n1 ; i++) L[i] = A[left + i];
    for(int i = 0; i < n2 ; i++) R[i] = A[mid + i];
    L[n1].value = R[n2].value = SENTINEL;
    int i = 0 ,  j = 0;
    for(int k = left ;k < right; k++){
        if(L[i].value <= R[j].value)
            A[k] = L[i++];
        else
            A[k] = R[j++];
    }
}

void mergesort (struct Card A[], int left , int right){
    int mid;
    if(left + 1 < right){
        mid = (left + right) / 2;
        mergesort(A,left,mid);
        mergesort(A,mid,right);
        Merge(A,left,mid,right);
    }
}

int Partition(struct Card A[],int p , int r){
    int i , j ;
    struct Card t,x;
    i = p - 1;
    x = A[r];
    for(j = p ; j < r ; j++){
        if(A[j].value <= x.value){
            i++;
            t = A[i]; A[i] = A[j]; A[j] = t;
        }
    }
    t = A[i + 1]; A[i + 1] = A[r]; A[r] = t;
    return i + 1;
}

void Quicksort(struct Card A[],int p , int r){
    int q;
    if( p < r){
        q = Partition(A , p , r);
        Quicksort(A , p , q-1);
        Quicksort(A , q+1 , r);
    }
}
int main()
{
    int Stable  =  1;
    int v, n;
    char s[10];
    struct Card A[MAX],B[MAX];
    scanf("%d", &n);

    for(int i = 0 ; i < n ; i++){
        scanf("%s %d", s , &v);
        A[i].suit = B[i].suit = s[0];
        A[i].value = B[i].value = v;
    }

    mergesort(A,0,n);
    Quicksort(B,0,n-1);

    for(int i = 0; i < n ;i++){
        if(A[i].suit != B[i].suit)  Stable = 0;
    }

    if(Stable) printf("Stable\n");
    else  printf("Not stable\n");

    for(int i = 0 ; i < n ; i++){
        printf("%c %d\n",B[i].suit,B[i].value);
    }

    return 0;
}

