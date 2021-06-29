#include<stdio.h>
#define MAX 500000
#define BANPEI 1000000000
void marge(int *,int ,int ,int ,int);
void margesort(int *,int ,int ,int );

int LEFT[MAX/2+2],RIGHT[MAX/2+2],cnt=0;

int main(){
    int A[MAX],n,i;

    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    margesort(A,n,0,n);

    for(i=0;i<n-1;i++){
        printf("%d ",A[i]);
    }
    printf("%d\n",A[n-1]);
    printf("%d\n",cnt);

    return 0;
}

void marge(int *A,int n,int left,int mid,int right){
    int indexlen1=mid-left;
    int indexlen2=right-mid;
    int i;
    for(i=0;i<indexlen1;i++){
        LEFT[i]=A[left+i];
    }
    for(i=0;i<indexlen2;i++){
        RIGHT[i]=A[mid+i];
    }
    LEFT[indexlen1]=RIGHT[indexlen2]=BANPEI;
    int k,j=0;
    i=0;
    for(k=left;k<right;k++){
        cnt++;
        if(LEFT[i]<=RIGHT[j]){
            A[k]=LEFT[i++];
        }else{
            A[k]=RIGHT[j++];
        }
    }
}

void margesort(int *A,int n,int left,int right){
    if(left+1<right){
        int mid=(left+right)/2;
        margesort(A,n,left,mid);
        margesort(A,n,mid,right);
        marge(A,n,left,mid,right);
    }
}
