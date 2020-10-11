#include <stdio.h>
#define Max 500000
#define INFTY 2000000000

int L[Max/2+2];
int R[Max/2+2];
int count =0;

void mergeA(int A[],int left,int mid,int right){
    int n1 = mid-left;
    int n2 = right-mid;
    
    int i,j,k;
    for(i=0; i<n1; i++) L[i]=A[left + i];
    for(i=0; i<n2; i++) R[i]=A[mid + i];
    L[n1] = INFTY;
    R[n2] = INFTY;
    i=0;
    j=0;
    for(k=left; k<right; k++){
        if(L[i]<=R[j]){
            A[k] = L[i];
            i++;
            count++;
        }else{
            A[k] = R[j];
            j++;
            count++;
        }
    }
    
    
}

void mergeSort(int A[],int left,int right){
    if(left+1<right){
        int mid =(left+right)/2;
        mergeSort(A,left,mid);
        mergeSort(A,mid,right);
        mergeA(A,left,mid,right);
    }
}




int main() {
    int n;
    int i;
    int A[Max];
    scanf("%d",&n);
    
    for(i=0; i<n; i++){
        scanf("%d",&A[i]);
    }
    mergeSort(A, 0, n);
    
    for(i=0; i<n; i++){
        printf("%d",A[i]);
        if(i<n-1) printf(" ");
    }
    printf("\n%d\n",count);
    
    return 0;
}
