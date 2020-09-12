#include<iostream>
#include<stdio.h>
using namespace std;
#define MAX 500000
#define banhei 2000000000

struct card{
    char C;
    int I;
};


struct card L[MAX/2+2];
struct card R[MAX/2+2];
 
void merge(struct card A[],int n,int left,int mid,int right){
    int n1=mid-left;
    int n2=right-mid;
    for(int i=0;i<n1;i++)L[i]=A[left+i];
    for(int i=0;i<n2;i++)R[i]=A[mid+i];
    L[n1].I=R[n2].I=banhei;
    int i=0;
    int j=0;
    for(int k=left;k<right;k++){
        if(L[i].I<=R[j].I){
            A[k]=L[i++];
        }else{
            A[k]=R[j++];
        }
    }
}
 
void mergesort(struct card A[],int n,int left,int right){
    if(left+1<right){
        int mid=(left+right)/2;
    mergesort(A,n,left,mid);
    mergesort(A,n,mid,right);
    merge(A,n,left,mid,right);
    }
}
 
int partition(struct card A[],int n,int p,int r){
    int i,j;
    struct card x;
    x=A[r];
    i=p-1;
    for(j=p;j<r;j++){
        if(A[j].I<=x.I){
            i++;
            swap(A[j],A[i]);
        }
    }
    swap(A[i+1],A[r]);
    return i+1;
}

void quicksort(struct card A[],int n,int p,int r){
    int q;
    if(p<r){
        q=partition(A,n,p,r);
        quicksort(A,n,p,q-1);
        quicksort(A,n,q+1,r);
    }
}
 
int main(){
    int n,i,M;
    struct card A[MAX],B[MAX];
    char S[5];
    int stable=1;
    cin>>n;
    
    for(i=0;i<n;i++){
    scanf("%s %d",S,&M);
    A[i].C=B[i].C=S[0];
    A[i].I=B[i].I=M;
    }
 
    mergesort(A,n,0,n);
    quicksort(B,n,0,n-1);
    
    for(i=0;i<n;i++){
        if(A[i].C!=B[i].C)stable=0;
    }
    
    if(stable)printf("Stable\n");
    else printf("Not stable\n");
    
    for(i=0;i<n;i++){
        printf("%c %d\n",B[i].C,B[i].I);
    }
    return 0;
}
