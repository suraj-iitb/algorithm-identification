#include<stdio.h>

#define N 100000
#define MAX 2000000000

typedef struct {
    char suit;
    int val;
}Card;
Card L[N/2+2], R[N/2+2];

int n, A[N];


void merge(Card A[], int n, int left, int mid, int right){
    int n1 = mid - left;
    int n2 = right - mid;
    
    for(int i=0; i<n1; i++){
        L[i] = A[left+i];
    }
    for(int i=0; i<n2; i++){
        R[i] = A[mid+i];
    }
    L[n1].val=MAX;
    R[n2].val=MAX;
    int i=0;
    int j=0;

    for(int k=left; k<right; k++){
        
        if(L[i].val <= R[j].val){
            A[k] = L[i];
            i++;
        }
        else{
            A[k] = R[j];
            j++;
        }
    }
}

void mergeSort(Card A[],int n,  int left, int right){
    int mid;
    if(left+1 < right){
        mid = (left+right)/2;
        mergeSort(A, n, left, mid);
        mergeSort(A, n, mid, right);
        merge(A, n, left, mid, right);
    }
}

int partition(Card A[], int n, int p, int r){
    Card x=A[r];
    int i=p-1;
    for(int j=p; j<r; j++){
        if(A[j].val<=x.val){
            i++;
            Card temp;
            temp=A[i];
            A[i]=A[j];
            A[j]=temp;
        }
    }
    Card temp;
    temp=A[i+1];
    A[i+1]=A[r];
    A[r]=temp;

    return i+1;

}

void quicksort(Card A[], int n, int p, int r){
    if(p<r){
        int q=partition(A, n, p, r);
        quicksort(A, n, p, q-1);
        quicksort(A, n, q+1, r);
    }
}

int main(void){
    Card A[N], B[N];
    char S[10];
    int v;
    int check=1;
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf("%s %d", S, &v);
        A[i].suit=B[i].suit=S[0];
        A[i].val=B[i].val=v;

    }

    mergeSort(A, n, 0, n);
    quicksort(B, n, 0, n-1);

    for(int i=0; i<n; i++){
        if(A[i].suit!=B[i].suit){
            check=0;
        }
    }

    if(check==1){
        printf("Stable\n");
    }
    else{
        printf("Not stable\n");
    }

    for(int i=0; i<n; i++){
        printf("%c %d\n", B[i].suit, B[i].val);
    }
    
    return 0;
}




