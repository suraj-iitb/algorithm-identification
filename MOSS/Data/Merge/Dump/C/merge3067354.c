#include<stdio.h>
#define N 500000
#define INFTY 1000000000

int n;
int cnt=0;
int L[N/2+2], R[N/2+2];

void merge(int A[], int left,int  mid, int right){
    int n1 = mid-left;
    int n2 = right-mid;
    
    int i,j=0;
    //L[0...n1], R[0...n2] を生成
    for (i=0; i<n1; i++){
         L[i]=A[left+i];
    }
    for(i=0; i<n2; i++){
        R[i]=A[mid+i];
    }
    L[n1]=INFTY;
    R[n2]=INFTY;
    i=0;j=0;
    for(int k=left; k<right; k++){
        cnt++;
        if(L[i]<=R[j]){
            A[k]=L[i];
            i++;
        }
        else{
            A[k]=R[j];
            j++;
        }
            }
    
}

void mergeSort(int A[],int left,int right){
    if(left+1 < right){
        int mid=(left + right)/2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
    

}


int main(){
    int A[N];
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        scanf("%d",&A[i]);
    }
    
    int left=0;
    int right=n;
    
    mergeSort(A, left, right);
    
  for(int i=0; i<n; i++){
        if(i) printf(" ");
        printf("%d",A[i]);
   }

    printf("\n%d\n",cnt);
    return 0;
    
}


