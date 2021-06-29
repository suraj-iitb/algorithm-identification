#include<stdio.h>
#define INFTY 2000000000

int S[1000000001];
int count=0;

void merge(int left, int mid, int right){
    int n1=mid-left;
    int n2=right-mid;
    int L[n1+1], R[n2+2];
    
    for(int i=0;i<n1;i++) L[i]=S[left+i];
    for(int i=0;i<n2;i++) R[i]=S[mid+i];
    L[n1]=INFTY;
    R[n2]=INFTY;
    int i=0;
    int j=0;
    for(int k=left;k<right;k++){
        count++;
        if(L[i]<=R[j]){
            S[k]=L[i];
            i++;
        }
        else{
            S[k]=R[j];
            j++;
        }
    }
}

void mergeSort(int left, int right){
    if(left+1<right){
        int mid=(left+right)/2;
        mergeSort(left,mid);
        mergeSort(mid,right);
        merge(left,mid,right);
    }
}

int main(void){
    int n;
    
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&S[i]);
    }
    
    mergeSort(0,n);
    
    for(int i=0;i<n;i++){
        printf("%d",S[i]);
        if(i!=n-1) printf(" ");
        else printf("\n%d\n",count);
    }
    
    return 0;
}
