#include <stdio.h>
#include <math.h>

#define MAX 1000000

void merge(int[],int,int,int);
void mergeSort(int[],int,int);

int count = 0;
int n;
int L[MAX/2],R[MAX/2];

int main(){
    int A[MAX];

    scanf("%d",&n);

    for(int i = 0;i < n;i++){
        scanf("%d",&A[i]);
    }


    mergeSort(A,0,n);

    for(int i = 0;i < n;i++){
        printf("%d",A[i]);
        if(i < n-1)printf(" ");
    }
    printf("\n");

    printf("%d\n",count);

    return 0;
}

void merge(int A[MAX],int left,int mid,int right){
    int i,j;
    int n1,n2;

    n1 = mid - left;
    n2 = right - mid;

    for(i = 0;i < n1;i++)L[i] = A[left + i];
    for(i = 0;i < n2;i++)R[i] = A[mid + i];
    L[n1] = 1e9+1;
    R[n2] = 1e9+1;

    i = 0;
    j = 0;

    for(int k = left;k < right;k++){
        count++;
        if(L[i] <= R[j]){
            A[k] = L[i];
            i++;
        }
        else {
            A[k] = R[j];
            j++;
        }
    }
}

void mergeSort(int A[MAX],int left,int right){
    int mid;

    if(left + 1 < right){
        mid = (left + right) / 2;
        mergeSort(A,left,mid);
        mergeSort(A,mid,right);
        merge(A,left,mid,right);
    }
}
