#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Card{
    char name[1];
    int val;
} Card;

void swap(Card* A, Card* B){
    Card C = *A;
    *A = *B;
    *B = C;
}

int Divide(Card A[], int low, int high){
    int i = low-1;
    for(int j=low; j<high; j++){
        if(A[j].val <= A[high].val){
            i++;
            swap(&A[i],&A[j]);
        }
    }
    swap(&A[i+1],&A[high]);

    return i+1;
}

void QuickSort(Card A[], int low, int high){
    if(low < high){
        int mid = Divide(A,low,high);
        QuickSort(A,low,mid-1);
        QuickSort(A,mid+1,high);
    }
}

bool Stability(Card A[], Card B[], int n){
    // Card Deck with no overlapping-value cards
    int tmp[n];
    int tmp_size = 0;
    for(int i=0; i<n; i++){
        if(A[i].val != A[i+1].val){
            tmp[tmp_size] = A[i].val;
            tmp_size++;
        }
    }
    // Check for stability 
    for(int i=0; i<tmp_size; i++){    
        Card a[n], b[n];
        int count_a = 0, count_b = 0;

        for(int j=0; j<n; j++){
            if(tmp[i] == A[j].val){
                a[count_a] = A[j];
                count_a++;
            }
            if(tmp[i] == B[j].val){
                b[count_b] = B[j];
                count_b++;
            }
        }

        for(int i=0; i<count_a; i++){
            if(a[i].name[0] != b[i].name[0])
                return 0;
        }
    }
    return 1;
}

void copyCard(Card A[], Card B[], int n){
    for(int i=0; i<n; i++)
        B[i] = A[i];
}

void printCard(Card A[], int n){
    for(int i=0; i<n; i++)
        printf("%s %d\n",A[i].name,A[i].val);
}


int main(){
    int n;
    scanf("%d",&n);
    Card A[n], B[n];
    for(int i=0; i<n; i++)
        scanf("%s %d",A[i].name,&A[i].val);

    copyCard(A,B,n);
    QuickSort(A,0,n-1);
    
    if(Stability(A,B,n) == 1)
        printf("Stable\n");
    else
        printf("Not stable\n");
    printCard(A,n);

    return 0;
}
