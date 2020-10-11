#include<stdio.h>
#define N 100000
#define INF 1000000000
int count;
typedef struct{
  char mark;
  int value;
}card;
void quicksort(card[],int,int);
void merge(card[],int,int,int);
void mergeSort(card[],int,int,int);
int partition(card[],int,int);
int main(){
  int n,i,x,z=1;
  card A[N],B[N];
  char X[100];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%s %d",X,&x);
    A[i].mark=B[i].mark=X[0];
    A[i].value=B[i].value=x;
  }
  mergeSort(A,n,0,n);
  quicksort(B,0,n-1);
  for(i=0;i<n;i++){
    if(A[i].mark!=B[i].mark)
      z=0;
  }
  if(z==1)
    printf("Stable\n");
  else
    printf("Not stable\n");
  for(i=0;i<n;i++){
    printf("%c %d\n",B[i].mark,B[i].value);
  }
  return 0;
}


void quicksort(card A[],int p,int r){
  int q;
  if(p<r){
    q=partition(A, p, r);
    quicksort(A, p, q-1);
    quicksort(A, q+1, r);
  }
}
void merge(card A[],int left,int mid,int right){
  int i,j,x;
  int inf=1000000000;
  int n1=mid-left;
  int n2=right-mid;
  card L[n1],R[n2];
  for(i=0;i<n1;i++){
    L[i]=A[left+i];
  }
  for(i=0;i<n2;i++){
    R[i]=A[mid+i];
  }
  L[n1].value=R[n2].value=inf;
  i=0;
  j=0;
  for(x=left;x<right;x++){
    count++;
    if(L[i].value<=R[j].value){
      A[x]=L[i];
      i=i+1;
    }
    else{
      A[x]=R[j];
      j=j+1;
    }
  }
}
void mergeSort(card A[],int n,int left,int right){
  if(left+1<right){
    int mid=(left+right)/2;
    mergeSort(A,n,left,mid);
    mergeSort(A,n,mid,right);
    merge(A,left,mid,right);
  }
}
int partition(card A[],int p,int r){
  int i,y;
  card x,z;
  x=A[r];
  y=p-1;
  for(i=p;i<r;i++){
    if(A[i].value<=x.value){
      y++;
      z=A[y];
      A[y]=A[i];
      A[i]=z;
    }
  }
  z=A[y+1];
  A[y+1]=A[r];
  A[r]=z;
  return y+1;
}

