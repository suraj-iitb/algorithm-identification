#include<stdio.h>
#define max 100000
#define sen 2000000000

struct Card{
  char s;
  int v;
};

struct Card L[max/2+2], R[max/2+2];

void merge(struct Card A[], int n, int left, int mid, int right){
  int i, j, k;
  int n1=mid-left;
  int n2=right-mid;
  for(i=0 ; i<n1 ; i++)L[i]=A[left+i];
  for(i=0 ; i<n2 ; i++)R[i]=A[mid+i];
  L[n1].v=R[n2].v=sen;
  i=j=0;
  for(k=left ; k<right ; k++){
    if(L[i].v<=R[j].v){
      A[k]=L[i++];
    }else{
      A[k]=R[j++];
    }
  }
}

void mergeSort(struct Card A[], int n, int left, int right){
  int mid;
  if(left+1<right){
    mid=(left+right)/2;
    mergeSort(A, n, left, mid);
    mergeSort(A, n, mid, right);
    merge(A, n, left, mid, right);
  }
}

int partition(struct Card A[], int n, int p, int r){
  int i, j;
  struct Card t, x;
  x=A[r];
  i=p-1;
  for(j=p ; j<r ; j++){
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

void quickSort(struct Card A[], int n, int p, int r){
  int q;
  if(p<r){
    q=partition(A, n, p, r);
    quickSort(A, n, p, q-1);
    quickSort(A, n, q+1, r);
  }
}

int main(){
  int n, i, v;
  struct Card A[max], B[max];
  char S[10];
  int sta=1;
  scanf("%d",&n);
  for(i=0 ; i<n ; i++){
    scanf("%s%d",S, &v);
    A[i].s=B[i].s=S[0];
    A[i].v=B[i].v=v;
  }
  mergeSort(A, n, 0, n);
  quickSort(B, n, 0, n-1);
  for(i=0 ; i<n ; i++){
    if(A[i].s!=B[i].s)sta=0;
  }
  if(sta==1)printf("Stable\n");
  else printf("Not stable\n");
  for(i=0 ; i<n ; i++){
    printf("%c %d\n",B[i].s, B[i].v);
  }
  return 0;
}
