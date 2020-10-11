#include<stdio.h>
#define MAX 100000
#define SENTINEL 2000000000

typedef struct card{
    char suit;
    int value;
}card;

card L[MAX/2+2],R[MAX/2+2];

void merge(card A[],int n,int l,int m,int r){
    int i,j,k;
    int n1,n2;
    n1=m-l;
    n2=r-m;
    for(i=0;i<n1;i++)L[i]=A[l+i];
    for(i=0;i<n2;i++)R[i]=A[m+i];
    L[n1].value=R[n2].value=SENTINEL;
    i=j=0;
    for(k=l;k<r;k++){
        if(L[i].value<=R[j].value){
            A[k]=L[i++];
        }
        else{
            A[k]=R[j++];
        }
    }
}

void mergesort(card A[],int n,int l,int r){
    int mid;
    if(l+1<r){
        mid=(l+r)/2;
        mergesort(A,n,l,mid);
        mergesort(A,n,mid,r);
        merge(A,n,l,mid,r);
    }
}

int partition(card B[],int n,int p,int r){
    int i,j;
    card tmp,x;
    x=B[r];
    i=p-1;
    for(j=p;j<r;j++){
        if(B[j].value<=x.value){
            i++;
            tmp=B[i];
            B[i]=B[j];
            B[j]=tmp;
        }
    }
    tmp=B[i+1];
    B[i+1]=B[r];
    B[r]=tmp;
    return i+1;
}

void quick(card C[],int n,int p,int r){
    int q;
    if(p<r){
        q=partition(C,n,p,r);
        quick(C,n,p,q-1);
        quick(C,n,q+1,r);
    }
}

int main(){
    card A[MAX],B[MAX];
    int i,n,v,stable=1;
    char ch[10];

    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%s%d",ch,&v);
        A[i].suit=B[i].suit=ch[0];
        A[i].value=B[i].value=v;
    }
    mergesort(A,n,0,n);
    quick(B,n,0,n-1);

    for(i=0;i<n;i++){
        if(A[i].suit!=B[i].suit) stable=0;
    }

    if(stable==1){
        printf("Stable\n");
    }
    else{
        printf("Not stable\n");
    }
    for(i=0;i<n;i++){
        printf("%c %d\n",B[i].suit,B[i].value);
    }
    return 0;
}
