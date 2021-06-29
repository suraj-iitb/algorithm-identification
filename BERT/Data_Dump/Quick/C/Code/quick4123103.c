#include<stdio.h>
#define N 100000
#define INFTY 1000000001

typedef struct{
  char c;
  int x;
}card;

int part(card *A,int p,int r){
  int f,i,j;
  card tmp;

  f=A[r].x;
  i=p-1;
  for(j=p;j<r;j++){
    if(A[j].x<=f){
      i=i+1;
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

void quick(card *A,int p,int r){
  int q;
  if(p<r){
    q=part(A,p,r);
    quick(A,p,q-1);
    quick(A,q+1,r);
  }
}

void merge(card *C,int left,int mid,int right){
  int n1=mid-left;
  int n2=right-mid;
  int i,j,k;
  card L[n1+N],R[n2+N];
  for(i=0;i<n1;i++) L[i]=C[left + i];
  for(i=0;i<n2;i++) R[i]=C[mid + i];
  L[n1].x=INFTY;
  R[n2].x=INFTY;
  i=0;
  j=0;
  for(k=left;k<right;k++){
    if(L[i].x<=R[j].x){
      C[k]=L[i];
      i=i+1;
    }
    else{
      C[k]=R[j];
      j=j+1;
    }
  }
}

void  mergeSort(card *C,int left,int right){
  int mid;
  if (left+1<right){
    mid=(left+right)/2;
    mergeSort(C,left,mid);
    mergeSort(C,mid,right);
    merge(C,left,mid,right);
  }
}

int main(){

  int i,j,n,x,flag=0;
  card A[N],B[N];

  scanf("%d",&n);

  for(i=0;i<n;i++) {
    scanf(" %c%d",&A[i].c,&A[i].x);
    B[i].c=A[i].c;
    B[i].x=A[i].x;
  }

  quick(A,0,n-1);

  mergeSort(B,0,n);

  for(i=0;i<n;i++){
    if(B[i].c != A[i].c){
      flag=1;
      break;
    }
  }

  if(flag==1)printf("Not stable\n");
  else printf("Stable\n");

  for(i=0;i<n;i++){
    printf("%c %d\n",A[i].c,A[i].x);
  }

  return 0;
}

