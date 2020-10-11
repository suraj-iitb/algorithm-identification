#include <stdio.h>
#define M 100000
#define  S 2000000000

struct node{
    char pair;
    int number;
};

struct node L[M/2+2],R[M/2+2];

    void merge(struct node A[],int n,int left,int mid,int right){
        int i,j,k,n1,n2;
    n1=mid-left;
    n2=right-mid;

    for(i=0;i<n1;i++){
        L[i]=A[left+i];
    }
    for(i=0;i<n2;i++){
        R[i]=A[mid+i];
    }
    L[n1].number = R[n2].number=S;
    i=j=0;
    for(k=left;k<right;k++){
        if(L[i].number <= R[j].number){
            A[k]=L[i++];
        }else{
            A[k]=R[j++];
        }
    }

    }

    void mergesort(struct node A[],int n,int l,int r){
        int mid;
        if(l+1<r){
            mid=(l+r)/2;
            mergesort(A,n,l,mid);
            mergesort(A,n,mid,r);
            merge(A,n,l,mid,r);
        }
    }

    int partition(struct node A[],int n,int p,int r){
        int i,j;
        struct node cng,x;
        x=A[r];
        i=p-1;
        for(j=p;j<r;j++){
            if(A[j].number<=x.number){
                i++;
                cng=A[i];
                A[i]=A[j];
                A[j]=cng;
            }
        }
        cng=A[i+1];
        A[i+1]=A[r];
        A[r]=cng;
        return i+1;
    }

    void qsort(struct node A[],int i,int j,int k){
        int q;
        if(j<k){
            q=partition(A,i,j,k);
            qsort(A,i,j,q-1);
            qsort(A,i,q+1,k);
        }
    }

    int main(){
        int n,i,t;
        struct node A[M],B[M];
        char c[10];
        int stb=1;

        scanf("%d",&n);

        for(i=0;i<n;i++){
            scanf("%s %d",c,&t);
            A[i].pair=B[i].pair=c[0];
            A[i].number=B[i].number=t;
        }
        mergesort(A,n,0,n);
        qsort(B,n,0,n-1);

        for(i=0;i<n;i++){
            if(A[i].pair!=B[i].pair)
            stb=0;
        }

        if(stb == 1)printf("Stable\n");
        else printf("Not stable\n");
        for(i=0;i<n;i++){
            printf("%c %d\n",B[i].pair,B[i].number);
        }
        return 0;
    }
