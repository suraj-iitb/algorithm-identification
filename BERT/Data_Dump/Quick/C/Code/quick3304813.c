#include<stdio.h>
#define INFINITY 1000000000

typedef struct {
  int a;
  char c;
}kouzou;

int partition(kouzou A[],int p,int r){
  int x,i,j;
  kouzou v;
  x=A[r].a;
  i=p-1;
  for(j=p;j<r;j++){
    if(A[j].a<=x){
      i++;
      v=A[i];
      A[i]=A[j];
      A[j]=v;
    }
  }
  v=A[i+1];
  A[i+1]=A[r];
  A[r]=v;
  return i+1;
}


void quicksort(kouzou A[],int p,int r){
  int q;
  if(p<r){
    q=partition(A,p,r);
    quicksort(A,p,q-1);
    quicksort(A,q+1,r);
  }
}


void merge(kouzou A[],int left,int mid,int right){
  int n1,n2,i,k,j;
  n1=mid-left;
  n2=right-mid;

  kouzou l[n1+1],r[n2+1];
  for(i=0;i<n1;i++)l[i]=A[left+i];
  for(i=0;i<n2;i++)r[i]=A[mid+i];
  l[n1].a=INFINITY;
  r[n2].a=INFINITY;
  i=j=0;
  for(k=left;k<right;k++){
    if(l[i].a<=r[j].a){
      A[k]=l[i];
      i+=1;
    }
    else {
      A[k]=r[j];
      j+=1;
    }

  }
}

void mergesort(kouzou A[],int left,int right){

  int mid,i=0;
  if(left+1<right){
    mid=(left+right)/2;
    mergesort(A,left,mid);
    mergesort(A,mid,right);
    merge(A,left,mid,right);
  }
}
int main(){
  int n,i;
  kouzou A[100000],B[100000];
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf(" %c %d",&A[i].c,&A[i].a);
    for(i=0;i<n;i++)B[i]=A[i];
    quicksort(A,0,n-1);
    mergesort(B,0,n);
    for(i=0;i<n;i++){
      if(A[i].c!=B[i].c){
        printf("Not stable\n");
        break;
      }
      if(i==n-1)printf("Stable\n");
    }
    for(i=0;i<n;i++)printf("%c %d\n",A[i].c,A[i].a);
    return 0;
}

