#include <stdio.h>

#define INFTY 1000000000
int S[500000];

int merge(int A[500000],int left,int mid,int right){
    int n1,n2,i,j,k;
    n1=mid-left;
    n2=right-mid;
    int L[n1+1],R[n2+1];
    for(i=0;i<n1;i++)
        L[i]=A[left+i];
    for(i=0;i<n2;i++)
        R[i]=A[mid+i];
    L[n1]=INFTY;
    R[n2]=INFTY;
    i=0;
    j=0;
    for(k=left;k<right;k++){
        if(L[i]<=R[j]){
            A[k]=L[i];
            i+=1;
        }else{
            A[k]=R[j];
            j+=1;
        }
    }
    return i+j;
}

int mergeSort(int A[500000],int left,int right){
    int mid,sum=0;
    if(left+1<right){
        mid=(left+right)/2;
        sum+=mergeSort(A,left,mid);
        sum+=mergeSort(A,mid,right);
        sum+=merge(A,left,mid,right);
    }
    return sum;
}

int main(){
    int i,n,sum;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&S[i]);
    }
    sum=mergeSort(S,0,n);
    for(i=0;i<n-1;i++)
        printf("%d ",S[i]);
    printf("%d\n%d\n",S[n-1],sum);
    
    return 0;
}
