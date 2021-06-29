#include<cstdio>
using namespace std;

int count;

void merge(int A[],int left,int mid,int right){
    int n1,n2,i,j;
    n1=mid-left;
    n2=right-mid;
    int L[n1+1],R[n2+1];
    for(int i=0;i<n1;i++){
        L[i]=A[left+i];
    }
    for(int i=0;i<n2;i++){
        R[i]=A[mid+i];
    }
    L[n1]=1000000000;
    R[n2]=1000000000;
    i=0;
    j=0;
    for(int k=left;k<right;k++){
        count+=1;
        if(L[i]<=R[j]){
            A[k]=L[i];
            i=i+1;
        }else{
            A[k]=R[j];
            j=j+1;
        }
    }
}

void mergeSort(int A[],int left,int right){
    if(left+1<right){
        int mid;
        mid=(left+right)/2;
        mergeSort(A,left,mid);
        mergeSort(A,mid,right);
        merge(A,left,mid,right);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int S[n];
    for(int i=0;i<n;i++){
        scanf("%d",&S[i]);
    }
    count=0;
    mergeSort(S,0,n);
    for(int i=0;i<n;i++){
        if(i!=(n-1)){
            printf("%d ",S[i]);
        }else{
            printf("%d\n",S[i]);
        }
    }
    printf("%d\n",count);

    return 0;
}
