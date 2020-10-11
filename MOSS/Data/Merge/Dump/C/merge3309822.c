#include<stdio.h>
#include<math.h>

#define N 500000 
void merge(int A[],int l,int m,int r);
void mergesort(int A[],int l,int r);
int n1,n2,c=0;

int a,b[N];

int main(){
  int i;
  scanf("%d",&a);
  for(i=0;i<a;i++)scanf("%d",&b[i]);
  mergesort(b,0,a);
  for(i=0;i<a;i++){
    printf("%d",b[i]);
    if(i==a-1)printf("\n");
    else printf(" ");
  }
  printf("%d\n",c);
}

void merge(int A[],int l,int m,int r){
  int i,j,k;
  n1=m-l;
  n2=r-m;
  int L[n1], R[n2];
  for(i=0;i<n1;i++)L[i]=A[l+i];
  for(i=0;i<n2;i++)R[i]=A[m+i];
  //printf("%d ",L[0]);
  L[n1]=INFINITY;
  R[n2]=INFINITY;
  i=0;
  j=0;
  for(k=l;k<r;k++){
    if(L[i]<=R[j]){
      A[k]=L[i];
      i++;
    }
    else{ 
      A[k]=R[j];
      j++;
    }
    c++;
  }
}

void mergesort(int A[],int left,int right){
  int mid;
  mid = (left + right)/2;
  if(left+1<right){
  mergesort(A, left, mid);
  mergesort(A, mid, right);
  merge(A, left, mid, right);
  }
}

