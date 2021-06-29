#include<stdio.h>
#include<math.h>
void mergeSort(int*,int,int);
void merge(int*,int,int,int);
int l=0;

int main(){
    int n,i;
    scanf("%d",&n);
    int S[n];
    for(i=0;i<n;i++) scanf("%d",&S[i]);
    int left=0,right=n;
    mergeSort(S,left,right);
    for(i=0;i<n;i++){
        if(i==n-1) printf("%d",S[i]);
        else printf("%d ",S[i]);
    }
    printf("\n");
    printf("%d\n",l);
    return 0;
}

void mergeSort(int *S,int left,int right){
    int mid=0;
    if(left+1<right){
        mid=(left+right)/2;
        mergeSort(S,left,mid);
        mergeSort(S,mid,right);
        merge(S,left,mid,right);
    }
}

void merge(int *S,int left,int mid,int right){
    int n1,n2,i,j,k;
    n1=mid-left;
    n2=right-mid;
    int L[n1+1],R[n2+1];
    for(i=0;i<=n1-1;i++) L[i]=S[left+i];
    for(i=0;i<=n2-1;i++) R[i]=S[mid+i];
    L[n1]=1e9+1;
    R[n2]=1e9+1;
    i=0;
    j=0;
    for(k=left;k<=right-1;k++){
        l++;
        if(L[i]<=R[j]){
            S[k]=L[i];
            i=i+1;
        }
        else{
            S[k]=R[j];
            j=j+1;
        }
    }
}
