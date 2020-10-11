#include<stdio.h>
#define N 100000
#define M 2000000000
#define O 0
#define I 1
#define W 2
#define Z 10

struct Card{
  char s;
  int v;
};

struct Card L[N],R[N];

void merge(struct Card A[],int n,int left,int mid,int right){
  int i,j,k;
  int n1=mid-left;
  int n2=right-mid;
  for(i=O;i<n1;i++){
    L[i]=A[left+i];
  }
  for(i=O;i<n2;i++){
    R[i]=A[mid+i];
  }
  L[n1].v=R[n2].v=M;
  i=j=O;
  for(k=left;k<right;k++){
    if(L[i].v<=R[j].v){
      A[k]=L[i++];
    }
    else{
      A[k]=R[j++];
    }
  }
}

void m_sort(struct Card A[],int n,int left,int right){
  int mid;
  if(left+I<right){
    mid=(left+right)/W;
    m_sort(A,n,left,mid);
    m_sort(A,n,mid,right);
    merge(A,n,left,mid,right);
  }
}

int partition(struct Card A[],int n,int p,int r){
  int i,j;
  struct Card t,x;
  x=A[r];
  i=p-I;
  for(j=p;j<r;j++){
    if(A[j].v<=x.v){
      i++;
      t=A[i];
      A[i]=A[j];
      A[j]=t;
    }
  }
  t=A[i+I];
  A[i+I]=A[r];
  A[r]=t;
  return i+I;
}

void quickSort(struct Card A[],int n,int p,int r){
  int q;
  if(p<r){
    q=partition(A,n,p,r);
    quickSort(A,n,p,q-I);
    quickSort(A,n,q+I,r);
  }
}

int main(){
  int i,n,v;
  struct Card A[N],B[N];
  char S[Z];
  int stable=I;

  scanf("%d",&n);
  for(i=O;i<n;i++){
    scanf("%s %d",S,&v);
    A[i].s=B[i].s=S[O];
    A[i].v=B[i].v=v;
  }
  m_sort(A,n,O,n);
  quickSort(B,n,O,n-I);
  for(i=O;i<n;i++){
    if(A[i].s!=B[i].s){
      stable=O;
    }
  }

  if(stable==I){
    printf("Stable\n");
  }
  else{
    printf("Not stable\n");
  }
  for(i=O;i<n;i++){
    printf("%c %d\n",B[i].s,B[i].v);
  }
  return O;
}

