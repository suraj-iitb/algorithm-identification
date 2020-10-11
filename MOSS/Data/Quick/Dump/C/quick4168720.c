#include<stdio.h>
#define MAX 100000
#define MAX2 1000000000

typedef struct{
    char gara;
    int value;
}point;
point L[MAX/2+2],R[MAX/2+2];
void merge(point A[],int n,int l,int m,int r){
    int i,j,k;
    int x1=r-m;
    int x2=m-l;
    for(i=0;i<x1;i++)R[i]=A[m+i];
    for(i=0;i<x2;i++)L[i]=A[l+i];
    L[x2].value=R[x1].value=MAX2;
    i=j=0;
    for(k=l;k<r;k++){
        if(L[i].value<=R[j].value){
            A[k]=L[i++];
        }else{
            A[k]=R[j++];
        }
    }
}
void sort(point A[],int n,int l,int r){
    int m;
    if(l+1<r){
        m=(l+r)/2;
        sort(A,n,l,m);
        sort(A,n,m,r);
        merge(A,n,l,m,r);
    }
}
int part(point A[],int n,int p,int r){
    int i,j;
    point k,x;
    x=A[r];
    i=p-1;
    for(j=p;j<r;j++){
        if(A[j].value<=x.value){
            i++;
            k=A[i];
            A[i]=A[j];
            A[j]=k;
        }
    }
    k=A[i+1];
    A[i+1]=A[r];
    A[r]=k;
    return i+1;
}
void quick(point A[],int n,int p,int r){
    int q;
    if(p<r){
        q=part(A,n,p,r);
        quick(A,n,p,q-1);
        quick(A,n,q+1,r);
    }
}
int main(){
    int n,i,x,stable=1;
    point data[MAX],data2[MAX];
    char C[10];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%s %d",C,&x);
        data[i].value=data2[i].value=x;
        data[i].gara=data2[i].gara=C[0];
    }
    sort(data,n,0,n);
    quick(data2,n,0,n-1);
    for(i=0;i<n;i++){
        if(data[i].gara!=data2[i].gara)stable=0;
    }
    if(stable==1)printf("Stable\n");
    else printf("Not stable\n");
    for(i=0;i<n;i++){
        printf("%c %d\n",data2[i].gara,data2[i].value);
    }
    return 0;

}

