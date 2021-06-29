#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define SENT 1000000000


int merge(int A[], int first, int mid, int last){
    
    int i,j,k, former, latter, *L, *R, cmp;
    cmp = 0;
    
    
    former = mid - first + 1;
    latter = last - mid;
    
    L = (int*)malloc(sizeof(int) * (former+1));
    R = (int*)malloc(sizeof(int) * (latter+1));
    
    for (i=0; i < former; i++) {
        L[i] = A[first + i];
    }
    L[former] = SENT;
    
    for (i=0; i < latter; i++) {
        R[i] = A[i + mid + 1];
    }
    R[latter] = SENT;
    
    j=k=0;
    for (i = first; i < last + 1; i++) {
        if (L[j] < R[k]) {
            A[i] = L[j];
            j++;
        }
        else
        {
            A[i] = R[k];
            k++;
        }
        cmp += 1;
    }
    return cmp;
    
}

int MergeSort(int A[], int first, int last){
    
    int cmp, mid;
    cmp = 0;
    
    if (first < last) {
        mid = (first + last)/2;
        cmp += MergeSort(A, first, mid);
        cmp += MergeSort(A, mid+1, last);
        cmp += merge(A, first, mid, last);
    }
    
    return cmp;
}


int main(){
    
    int i,n, *array, cmp;
    
    cmp = 0;
    
    //the number
    scanf("%d",&n);
    
    array = (int*)malloc(sizeof(int)*n);
    
    for (i=0; i<n; i++) {
        scanf("%d", &array[i]);
    }
    
    cmp = MergeSort(array, 0, n-1);
    
    for (i=0; i<n; i++) {
        printf("%d", array[i]);
        if (i != n-1) {
            printf(" ");
        }
    }
    printf("\n");
    
    printf("%d\n", cmp);
    
    free(array);
    
    return 0;
}
