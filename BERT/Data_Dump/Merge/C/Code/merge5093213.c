#include<stdio.h>

#define M 500000
#define N 1000000000

void merge(int *, int, int, int);
void mergeSort(int *, int, int);

int count=0;

int main()
{
    int S[M], n, i;

    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&S[i]);
    }

    mergeSort(S, 0, n);

    for(i=0;i<n;i++){
        if(i<n-1){
            printf("%d ",S[i]);
        }
        else{
            printf("%d\n%d\n",S[i], count);
        }
    }

    return 0;
}

void merge(int *S, int left, int mid, int right){
    int n1, n2, i, j, k, L[M], R[M];

    n1 = mid - left;
    n2 = right - mid;

    for(i=0;i<n1;i++){
        L[i] = S[left + i];
    }
    for(i=0;i<n2;i++){
        R[i] = S[mid + i];
    }

    L[n1] = N;
    R[n2] = N;
    i=0;
    j=0;

    for(k=left;k<right;k++){
        if(L[i] <= R[j]){
            S[k] = L[i];
            i++;
        }
        else{
            S[k] = R[j];
            j++;
        }
        count++;
    }
}

void mergeSort(int *S, int left, int right){
    int mid;

    if(left+1 < right){
        mid = (left + right) / 2;
        mergeSort(S, left, mid);
        mergeSort(S, mid, right);
        merge(S, left, mid, right);
    }
}
