#include<stdio.h>
#define N 100000
#define INF 1000000000
 
struct C{
  char s;
  int v;
};
 
struct C L[N], R[N];
 
void merge(struct C[], int , int , int );
void mergeSort(struct C[], int , int ); 
int partition(struct C[], int , int );
void quickSort(struct C[], int , int );
 
 
int main(){
   
  int n, i, v;
  struct C A[N], B[N];
  char S[10];
  int stable = 1;
   
  scanf("%d", &n);
 
  for ( i = 0; i < n; i++ ) {
    scanf("%s %d", S, &v);
    A[i].s = S[0];
    B[i].s = S[0];
    A[i].v = v;
    B[i].v = v;
  }
 
  mergeSort(A,0,n);
  quickSort(B,0,n-1);
 
  for(i=0;i<n;i++ ){
    if(A[i].s!=B[i].s){
      stable=0;
    }
  }
 
  if(stable==1){
    printf("Stable\n");
  }
  else{
    printf("Not stable\n");
  }
  for(i=0;i<n;i++){
    printf("%c %d\n", B[i].s, B[i].v);
  }
  return 0;
}
 
void merge(struct C A[],int left,int mid,int right){
   
  int i,j,k,n1,n2;
   
  n1=mid-left;
  n2=right-mid;
   
  for(i=0;i<n1;i++){
    L[i] = A[left + i];
  }
  for(i=0;i<n2;i++){
    R[i] = A[mid + i];
  }
 
  L[n1].v=INF;
  R[n2].v=INF;
  i=0;
  j=0;
   
  for (k=left;k<right;k++ ){
    if (L[i].v<=R[j].v){
      A[k] = L[i];
      i++;
    }
    else {
      A[k] = R[j];
      j++;
    }
  }
}
 
void mergeSort(struct C A[], int left, int right ){
   
  int mid;
   
  if (left+1<right){
    mid=(left + right)/2;
    mergeSort(A,left,mid);
    mergeSort(A,mid,right);
    merge(A,left,mid,right);
  }
}
 
int partition(struct C A[],int p,int r){
 
  int i,j;
  struct C t,x;
 
  x = A[r];
  i = p - 1;
  for (j=p;j<=r-1;j++ ){
    if ( A[j].v <= x.v){
      i++;
      t = A[i];
      A[i] = A[j];
      A[j] = t;
    }
  }
  t = A[i+1];
  A[i+1] = A[r];
  A[r] = t;
   
  return i+1;
}
 
void quickSort(struct C A[],int p,int r){
 
  int q;
   
  if (p<r){
    q = partition(A, p, r);
    quickSort(A, p, q - 1);
    quickSort(A, q + 1, r);
  }
}
