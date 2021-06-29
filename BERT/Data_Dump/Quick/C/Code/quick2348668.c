#include<stdio.h>
#define N 100000
struct Card{
  char s;
  int v;
};
struct Card L[N], R[N];
void merge(struct Card [], int , int , int );
void mergeSort(struct Card [], int , int ); 
int partition(struct Card [], int , int );
void quickSort(struct Card [], int , int );
int main(){
  int n, i, v;
  struct Card A[N], B[N];
  char s[10];
  int flag=1;
  scanf("%d",&n);
  for (i=0;i<n;i++){
    scanf("%s %d",s,&v);
    A[i].s = s[0];
    B[i].s = s[0];
    A[i].v = v;
    B[i].v = v;
  }
  mergeSort(A, 0, n);
  quickSort(B, 0, n-1);
 
  for (i=0;i<n;i++ ){
    if (A[i].s!=B[i].s) {
       flag=0;
    }
  }
  if(flag==1){
    printf("Stable\n");
  }
  else{
    printf("Not stable\n");
  }
  for (i=0;i<n;i++){
    printf("%c %d\n",B[i].s,B[i].v);
  }
  return 0;
}
void merge(struct Card A[], int left, int mid, int right){
  int i,j,k,n1,n2;  
  n1=mid-left;
  n2=right-mid;
  for(i=0;i<n1;i++){
    L[i] = A[left + i];
  }
  for(i=0;i<n2;i++){
    R[i] = A[mid + i];
  }
  L[n1].v=1000000000;
  R[n2].v=1000000000;
  i=0;
  j=0;
  for (k=left;k<right;k++){
    if (L[i].v<=R[j].v){
      A[k]=L[i];
      i++;
    }
    else {
      A[k]=R[j];
      j++;
    }
  }
}
void mergeSort(struct Card A[], int left, int right ){
  int mid;
  if (left+1<right){
    mid=(left+right)/2;
    mergeSort(A,left,mid);
    mergeSort(A,mid,right);
    merge(A,left,mid,right);
  }
}
void quickSort(struct Card A[], int p, int r){
  int q;
  if (p<r){
    q = partition(A,p,r);
    quickSort(A,p,q - 1);
    quickSort(A,q + 1,r);
  }
}
int partition(struct Card A[], int p, int r){
  int i, j;
  struct Card change, x;
  x=A[r];
  i=p-1;
  for (j=p;j<=r-1;j++){
    if (A[j].v<=x.v){
      i++;
      change=A[i];
      A[i]=A[j];
      A[j]=change;
    }
  }
  change=A[i+1];
  A[i+1]=A[r];
  A[r]=change;
  return i+1;
}
