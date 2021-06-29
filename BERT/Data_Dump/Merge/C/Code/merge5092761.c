#include <stdio.h>
#include <math.h>

void mer(int *, int, int, int);
void mergesort(int *, int, int);

int L[500000], R[500000], cnt = 0;

int main(){
  int i,n,A[500000];
    
    scanf("%d", &n);
    for(i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    mergesort(A,0,n);
    
    for(i=0;i<n;i++){
        printf("%d",A[i]);
        if(i==n-1)
            printf("\n");
        else
            printf(" ");
    }
    
    printf("%d\n", cnt);
    
    return 0;
}

void mer(int A[],int left,int mid,int right) {
  int i,j,k,n1,n2;
    n1 = mid - left;
    n2 = right - mid;
    
    for(i=0;i<n1;i++){
        L[i] = A[left+i];
    }
    for(i=0;i<n2;i++){
        R[i] = A[mid + i];
    }
    
    L[n1] = 1000000000;
    R[n2] = 1000000000;
    i = 0;
    j = 0;
    
    for(k=left;k<right;k++){
        cnt++;
        if(L[i]<=R[j]) {
            A[k]=L[i];
            i=i+1;
        }
	else {
            A[k]=R[j];
            j=j+1;
        }
    }
}
void mergesort(int A[], int left, int right) {
    int mid;
    
    if(left+1<right) {
        mid=(left+right)/2;
        mergesort(A,left,mid);
        mergesort(A,mid,right);
        mer(A,left,mid,right);
    }
}

