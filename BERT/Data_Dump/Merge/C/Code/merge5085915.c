#include <stdio.h>
#define N 500000
#define MAXNUM 1000000001

int A[N], count = 0, numA;

void merge(int, int, int);
void mergeSort(int, int);

int main(){
    int i;

scanf("%d", &numA);

for(i = 0; i < numA; i++){
    scanf("%d", &A[i]);
}

mergeSort(0, numA);
    
for(i = 0; i < numA; i++){
    if (i > 0) printf(" ");
    
    printf("%d", A[i]);
}

printf("\n%d\n", count);
    

    return 0;
}

void merge(int left, int mid, int right){
    int n1, n2, i, j, k, L[N], R[N];
    n1 = mid - left;
    n2 = right - mid;

    for(i = 0; i < n1; i++){
        L[i] = A[left+i];
    }

    for(i = 0; i < n2; i++){
        R[i] = A[mid+i];
    }

    L[n1] = MAXNUM;
    R[n2] = MAXNUM;

    i = 0;
    j = 0;

    for(k = left; k < right; k++){
        count++;
        if(L[i] <= R[j]){
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }

}

void mergeSort(int left, int right){
    int mid;
    if(left+1 < right){
        mid = (left + right) / 2;
        mergeSort(left, mid);
        mergeSort(mid, right);
        merge(left, mid, right);
    }

}
