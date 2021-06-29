#include <stdio.h>
#define MAX 500000
#define Large 2000000000
int cnt;
int L[250000+2];
int R[250000+2];
int A[MAX];
void merge1(int l,int m,int r){
  int n1,n2,i;
  n1=m-l;     //?????´???????????¨
  n2=r-m;     //?????´???????????¨
  for(i=0;i<n1;i++){
    L[i]=A[l+i];
  }
  for(i=0;i<n2;i++){
    R[i]=A[m+i];
  }
  L[n1]=Large;
  R[n2]=Large;
  int i1=0,i2=0,j;
  for(j=l;j<r;j++){
    if(L[i1]<=R[i2]){
      A[j]=L[i1];
      i1++;
    }else{
      A[j]=R[i2];
      i2++;
    }
    cnt++;
  }
}

void mergesort(int l, int r){
  int m;
  if(l+1<r){
      m=(r+l)/2;
      mergesort(l,m);
      mergesort(m,r);
      merge1(l,m,r);
  }
}



int main(int argc, char const *argv[]) {
  int n,i;
  scanf("%d\n",&n);
  for(i=0;i<n;i++) scanf("%d",&A[i]);
  mergesort(0,n);
  for(i=0;i<n;i++){
    if(i==n-1)printf("%d\n",A[i]);
    else printf("%d ",A[i]);
  }
  printf("%d\n",cnt);
  return 0;
}
