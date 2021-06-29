#include<stdio.h>
#define MAX 100000

typedef struct node{
  char s;
  int v;
}Card;

Card L[MAX/2+2],R[MAX/2+2];
void merge(Card A[],int n,int left,int m,int right){
  int i,j,k,n1,n2;
  n1=m-left;
  n2=right-m;
  for(i=0;i<n1;i++) L[i]=A[left+i];
  for(i=0;i<n2;i++) R[i]=A[m+i];
  L[n1].v=R[n2].v=2000000000;
  i=j=0;
  for(k=left;k<right;k++){
    if(L[i].v<=R[j].v){
      A[k]=L[i++];
    }else{
      A[k]=R[j++];
    }
  }
}

void mergesort(Card A[],int n,int left ,int right){
  int m;
  if(left +1 < right){
    m =(left+right)/2;
    mergesort(A,n,left,m);
    mergesort(A,n,m,right);
    merge(A,n,left,m,right);
  }
}
int partition(Card A[],int n,int p,int r){
  int i,j;
  Card t,x;
  x=A[r];
  i=p-1;
  for(j=p;j<r;j++){
    if(A[j].v<=x.v){
      i++;
      t=A[i];
      A[i]=A[j];
      A[j]=t;
    }
  }
  t=A[i+1];
  A[i+1]=A[r];
  A[r]=t;
  return i+1;
}
void quicksort(Card A[],int n,int p,int r){
  int q;
  if(p<r){
    q=partition(A,n,p,r);
    quicksort(A,n,p,q-1);
    quicksort(A,n,q+1,r);
  }
}
int main(){
  int n,i,b;
  scanf("%d",&n);
  Card A[MAX],B[MAX];
  char T[10];

  for(i=0;i<n;i++){
    scanf("%s %d",T,&b);
    A[i].s =B[i].s = T[0];
    A[i].v =B[i].v =b;
  }
  mergesort(A,n,0,n);
  quicksort(B,n,0,n-1);
int stable =1;
  for(i=0;i<n;i++){
    if(A[i].s!=B[i].s)stable=0;
  }
  if(stable==1)printf("Stable\n");
  else printf("Not stable\n");
  for(i=0;i<n;i++){
    printf("%c %d\n",B[i].s,B[i].v);
  }
  return 0;
}

