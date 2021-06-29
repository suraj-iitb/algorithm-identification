#include <stdio.h>
#include <stdlib.h>

typedef struct{
  char c[2];
  int a;
}Point;

int partition(Point *, int, int);
int quickSort(Point *, int, int);
void merge(Point *,int, int, int);
void mergeSort(Point *,int, int);

int n;

int main()
{
  int flag=0, i;
  Point A1[100000], A2[100000];
  
  scanf("%d",&n);
  
  for( i=0 ; i<n ; i++ ){
    scanf(" %s%d",A1[i].c,&A1[i].a);
    A2[i] = A1[i];
  }

  quickSort(&A1[0],0,n-1);
  mergeSort(&A2[0],0,n);

  

  for( i=0 ; i<n ; i++ ){
    if(A1[i].c[0]!=A2[i].c[0] || A1[i].a!=A2[i].a)
      flag = 1;
  }
  if(flag==1) printf("Not stable\n");
  else printf("Stable\n");

  for( i=0 ; i<n-1 ; i++ ){
    printf("%c %d\n",A1[i].c[0],A1[i].a);
  }
  printf("%c %d\n",A1[i].c[0],A1[i].a);
  
  return 0;
}

int partition(Point *A, int p, int r)
{
  int i, j;
  Point x, str;
  x = A[r];
  i = p-1;
  for( j=p ; j<=r-1 ; j++ ){
    if(A[j].a<=x.a){
      i++;
      str = A[i];
      A[i] = A[j];
      A[j] = str;
    }
  }
  A[r] = A[i+1];
  A[i+1] = x;
  return i+1;
}

int quickSort(Point *A, int p, int r)
{
  int q;
  if(p<r){
    q = partition(A,p,r);
    quickSort(A,p,q-1);
    quickSort(A,q+1,r);
  }
}

void merge(Point *A, int left, int mid, int right)
{
  int n1, n2, i, j, k;
  Point L[50001],R[50001];
  n1 = mid-left;
  n2 = right - mid;
  for( i=0 ; i<n1 ; i++ ){
    L[i] = A[left+i];
  }
  for( i=0 ; i<n2 ; i++ ){
    R[i] = A[mid+i];
  }
  L[n1].a=1000000100;
  R[n2].a=1000000100;
  i=0;
  j=0;
  for( k=left ; k<right ; k++ ){
    if(L[i].a<=R[j].a){
      A[k]=L[i];
      i++;
    }
    else{
      A[k]=R[j];
      j++;
    }
  }
}
void mergeSort(Point *A,int left, int right)
{
  int mid;
  if((left+1)<right){
    mid=(left+right)/2;
    mergeSort(A,left,mid);
    mergeSort(A,mid,right);
    merge(A,left,mid,right);
  }
}
