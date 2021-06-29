#include<stdio.h>
#define MAX 100000
#define SEN 100000000000

typedef struct{
    char suit;
    int value;
}Card;

Card L[MAX],R[MAX];

int partition(Card *,int,int,int);
void mergesort(Card *,int,int,int);
void merge(Card *,int,int,int,int);
void quicksort(Card *,int,int,int);

int main()
{
    int i,N,v;
    Card A[MAX],B[MAX];
    char S[100];
    int stable=1;
    
    scanf("%d",&N);
    
    for(i=0;i<N;i++){
        scanf("%s%d",S,&v);
        A[i].suit=B[i].suit=S[0];
        A[i].value=B[i].value=v;
    }
    
    mergesort(A,N,0,N);
    quicksort(B,N,0,N-1);
    
    for(i=0;i<N;i++){
        if(A[i].suit!=B[i].suit) stable=0;
    }
    if(stable==1) printf("Stable\n");
    else printf("Not stable\n");
    
    for(i=0;i<N;i++) printf("%c %d\n",B[i].suit,B[i].value);
    return 0;
}

int partition(Card A[],int n,int a,int b)
{
    int i,j;
    Card x,y;
    
    y=A[b];
    i=a-1;
    
    for(j=a;j<b;j++){
        if(A[j].value<=y.value){
            i++;
            x=A[i];
            A[i]=A[j];
            A[j]=x;
        }
    }
    x=A[i+1];
    A[i+1]=A[b];
    A[b]=x;
    return i+1;
}

void mergesort(Card A[],int n,int l,int r)
{
    int m;
    
    if(l+1<r){
        m=(l+r)/2;
        mergesort(A,n,l,m);
        mergesort(A,n,m,r);
        merge(A,n,l,m,r);
    }
}

void merge(Card A[],int n,int l,int m,int r)
{
    int i,j,k;
    int n1=m-l;
    int n2=r-m;
    
    for(i=0;i<n1;i++) L[i]=A[l+i];
    for(i=0;i<n2;i++) R[i]=A[m+i];
    
    L[n1].value=R[n2].value=SEN;
    i=j=0;
    
    for(k=l;k<r;k++){
        if(L[i].value<=R[j].value) A[k]=L[i++];
        else A[k]=R[j++];
    }
}

void quicksort(Card A[],int n,int a,int b)
{
    int c;
    
    if(a<b){
        c=partition(A,n,a,b);
        quicksort(A,n,a,c-1);
        quicksort(A,n,c+1,b);
    }
}
