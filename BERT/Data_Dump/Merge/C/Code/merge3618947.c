#include <stdio.h>

int count = 0;
void merge(int arr[],  int left, int mid, int right)
{
    int i,j,k;
    int left_size = mid - left + 1;
    int right_size = right - mid;

    /*creat temp arrays*/
    int L[left_size], R[right_size];

    /*copy data to temp arrays L[] and R[]*/
    for(i=0; i<left_size; i++)
        L[i] = arr[left+i];
    for(j=0; j<right_size; j++)
        R[j] = arr[mid+1+j];
    /*merge two temp arrays*/
    i = 0; //initial index of first subarray
    j = 0; //initial index of second subarray
    k = left; //initial index of merged subarray

    while(i<left_size && j<right_size){
        if(L[i]<=R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
        count++;
    }

    while(i<left_size){
        arr[k] = L[i];
        i++;
        k++;
        count++;
    }
    while(j<right_size){
        arr[k] = R[j];
        j++;
        k++;
        count++;
    }
}
void mergesort(int A[], int left, int right)
{
    int mid;
    if(left<right){
        mid = left + (right-left)/2;
        mergesort(A, left, mid);
        mergesort(A, mid+1, right);
        merge(A, left, mid, right);
    }
}

int main(){
    /*int A[] = {8, 5, 9, 2, 6, 3, 7, 1, 10, 4};*/
    int n, A[500005];
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &A[i]);
    }
    mergesort(A, 0, n-1);
    for(int i=0; i<n; i++){
        if(i!=n-1) printf("%d ", A[i]);
        else printf("%d\n", A[i]);
    }
    printf("%d\n", count);
}

