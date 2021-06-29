#include <stdio.h>
#define N 500000
#define SENTINEL 1000000500

void Merge_Sort(int*,int,int);
void Merge(int*,int,int,int);

int L[N/2+2],R[N/2+2];
int cnt=0;

int main(){
    int A[N],n;
    int i;

    scanf("%d",&n);

    for(i=0;i<n;i++){
        scanf("%d",&A[i]);
    }

    Merge_Sort(A,0,n);

    for(i=0;i<n;i++){
        printf("%d",A[i]);
        if(i<n-1)printf(" ");
    }
    printf("\n");
    printf("%d\n",cnt);

    return 0;
}

void Merge_Sort(int* A,int left,int right){
    int mid;
    if( left+1 < right){
        mid = (left + right)/2;
        Merge_Sort(A,left,mid);
        Merge_Sort(A,mid,right);
        Merge(A,left,mid,right);
    }
}

void Merge(int* A,int left,int mid,int right){
    int n1 = mid - left;
    int n2 = right - mid;
    int i,j,k;

    for(i=0;i<n1;i++){
        L[i] = A[left + i];
    }
    for (i=0;i<n2;i++){
        R[i] = A[mid + i];
    }
    R[n2] = L[n1] = SENTINEL;
    i = j = 0;
    for(k=left;k<right;k++){
        cnt++;
        if(L[i] <= R[j]){
            A[k] = L[i++];
        }
        else{
            A[k] = R[j++];
        }
    }
}
