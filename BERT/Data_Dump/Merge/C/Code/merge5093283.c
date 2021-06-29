#include<stdio.h>

void merge(int *, int, int, int);
void mergeSort(int *, int, int);

int count = 0;

int main(){
    int n, S[500000], i;

    scanf("%d",&n);

    for(i=0;i<n;i++){
        scanf("%d",&S[i]);
    }

    mergeSort(S, 0, n);

    for(i=0;i<n-1;i++){
        printf("%d ",S[i]);
    }

    printf("%d\n%d\n",S[n-1], count);

    return 0;
}

void merge(int *S, int left, int mid, int right){
    int n1, n2, i, j, k, L[500000], R[500000];

    n1 = mid - left;
    n2 = right - mid;

    for(i=0;i<n1;i++){
        L[i] = S[left+i];
    }
    for(i=0;i<n2;i++){
        R[i] = S[mid+i];
    }
    L[n1] = 1000000000;
    R[n2] = 1000000000;
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
