#include<stdio.h>

#define  MAX 500000
#define INFTY 2000000000

int L[MAX/2+2], R[MAX/2+2];
int cnt;

void haku(int A[],int n,int l,int m,int r){
    int n1=m-l;
    int n2=r-m;
    for(int i=0;i<n1;i++)L[i]=A[l+i];
    for(int i=0;i<n2;i++)R[i]=A[m+i];
    L[n1]=R[n2]=INFTY;
    int i=0,j=0;
    for(int k=l;k<r;k++){
        cnt++;
        if(L[i]<=R[j]){
            A[k]=L[i++];
        }else{
            A[k]=R[j++];
        }
    }
}

void kota(int A[],int n,int l, int r){
    if(l+1<r){
        int m=(l+r)/2;
        kota(A,n,l,m);
        kota(A,n,m,r);
        haku(A,n,l,m,r);
    }
}

int main(){
    int A[MAX],n,i;
    cnt=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",&A[i]);
    kota(A,n,0,n);
    for(i=0;i<n;i++){
      if(i)printf(" ");
        printf("%d",A[i]);
    }
    printf("\n");
    printf("%d\n",cnt);
    return 0;
}
