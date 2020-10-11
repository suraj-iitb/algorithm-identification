#include <stdio.h>
#define INFTY 1000000001
struct C
{
    char c;
    int x;
};
typedef struct C data;
int partition(data *,int,int);
void quicksort(data *,int,int);
void mergesort(data *,int,int);
void merge(data *,int,int,int);
int main (){
    int n,i,flag=0;
    data a[100000],b[100000];
    scanf("%d\n",&n);
    for(i=0;i<n-1;i++){
        scanf("%c %d\n",&a[i].c,&a[i].x);
        b[i]=a[i];
    }
    scanf("%c %d",&a[i].c,&a[i].x);
    b[i]=a[i];
    quicksort(a,0,n-1);
    mergesort(b,0,n);
    for(i=0;i<n;i++){
        if(a[i].c!=b[i].c){
            flag=1;
            break;
        }
    }
    if(flag){
        printf("Not stable\n");
    }
    else{
        printf("Stable\n");
    }
    for(i=0;i<n;i++){
        printf("%c %d\n",a[i].c,a[i].x);
    }
    return 0;
}
int partition(data *A,int p,int r){
    data x,tmp;
    int i,j;
    x=A[r];
    i=p-1;
    for(j=p;j<r;j++){
        if(A[j].x<=x.x){
            i++;
            tmp=A[i];
            A[i]=A[j];
            A[j]=tmp;
        }
    }
    tmp=A[i+1];
    A[i+1]=A[r];
    A[r]=tmp;
    return i+1;
}
void quicksort(data *A,int p,int r){
    int q;
    if(p<r){
        q = partition(A, p, r);
        quicksort(A, p, q-1);
        quicksort(A, q+1, r);
    }
}
void mergesort(data *A,int left,int right){
  int mid;
  if(left+1<right){
    mid=(left+right)/2;
    mergesort(A,left,mid);
    mergesort(A,mid,right);
    merge(A,left,mid,right);
  }
}
void merge(data *A,int left,int mid,int right){
  int n1,n2,i,j,k;
  n1=mid-left;
  n2=right-mid;
  data L[n1+1],R[n2+1];
  for(i=0;i<n1;i++)
    L[i]=A[left+i];
  for(i=0;i<n2;i++)
    R[i]=A[mid+i];
  L[n1].x=INFTY;
  R[n2].x=INFTY;
  i=0;
  j=0;
  for(k=left;k<right;k++){
    if(L[i].x<=R[j].x){
      A[k]=L[i];
      i++;
    }
    else{
      A[k]=R[j];
      j++;
    }
  }
}

