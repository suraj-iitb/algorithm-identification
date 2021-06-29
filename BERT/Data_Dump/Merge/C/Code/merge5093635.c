#include<stdio.h>
#define MAX 500000
void marge(int *,int,int,int);
void margesort(int *,int,int);
int n,count;
int L[MAX];
int R[MAX];
int main()
{
  int i;
  count = 0;
  scanf("%d",&n);
  int A[n];
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  margesort(A,0,n);

  for(i=0;i<n;i++){
    if(i == n-1) printf("%d\n",A[i]);
    else printf("%d ",A[i]);
  }
  printf("%d\n",count);

  return 0;
}

void marge(int *a,int l,int m,int r)
{
  int n1,n2,i,j,k;
  n1 = m - l;
  n2 = r - m;
  for(i=0;i<n1;i++) L[i] = *(a+l+i);
  for(i=0;i<n2;i++) R[i] = *(a+m+i);
  L[n1] = 2000000000;
  R[n2] = 2000000000;
  i = 0;
  j = 0;
  for(k=l;k<r;k++){
      count++;
    if(L[i] < R[j]){
      *(a+k) = L[i];
      i = i + 1;
    }
      else {
      *(a+k) = R[j];
      j = j + 1;
    }
  }
}
void margesort(int *a,int l,int r)
{
  int m;
  if(l + 1 < r){
    m = (l+r)/2;
    margesort(a,l,m);
    margesort(a,m,r);
    marge(a,l,m,r);
  }
}
