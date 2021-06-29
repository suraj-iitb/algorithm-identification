#include<stdio.h>
#define MAX 500000
#define INTMAX 2147483647

int L[MAX/2+2];
int R[MAX/2+2];
int cnt;

void merge(int A[], int n, int lef, int mid, int rig){
    int i, j, k;
    
    int n1 = mid - lef;
    int n2 = rig - mid;
    for(i=0 ; i<n1 ; i++){
        L[i] = A[lef+i];
    }
    for(i=0 ; i<n2 ; i++){
        R[i] = A[mid+i];
    }
    L[n1] = R[n2] = INTMAX;
    i = j = 0;
    for(k=lef ; k<rig ; k++){
        cnt++;
        if(L[i] <= R[j]){
            A[k] = L[i++];
        }
        else{
            A[k] = R[j++];
        }
    }
}

void mergesort(int A[], int n, int lef, int rig){
    int mid;
    if(lef+1 < rig){
        mid = (lef+rig)/2;
        mergesort(A, n, lef, mid);
        mergesort(A, n, mid, rig);
        merge(A, n, lef, mid, rig);
    }
}

int main(){
    int A[MAX], n, i;
    scanf("%d", &n);
    cnt = 0;
    for(i=0 ; i<n ; i++){
        scanf("%d", &A[i]);
        if(A[i] >= INTMAX){
            return 1;
        }
    }
    
    mergesort(A, n, 0, n);
    
    for(i=0 ; i<n ; i++){
        if(i){
            printf(" ");
        }
        printf("%d", A[i]);
    }
    printf("\n");
    printf("%d\n", cnt);
    
    return 0;
}
