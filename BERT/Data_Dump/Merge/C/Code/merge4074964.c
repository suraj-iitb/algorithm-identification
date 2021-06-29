#include<stdio.h>
#define MAX 500000
#define SEN 2000000000
void merge(int *,int,int,int,int);
void mergeSort(int *,int,int,int);



int L[MAX/2+2],R[MAX/2+2],count;

int main(){
  int H[MAX],n,i;
  count=0;

  scanf("%d",&n);
  for(i=0;i <= n-1;i++){
    scanf("%d",&H[i]);
  }
  mergeSort(H,n,0,n);
  for(i=0;i <= n-1;i++){
    if(i>0)printf(" ");
    printf("%d",H[i]);
  }
  printf("\n");
  printf("%d\n",count);
  return 0;
}
void merge(int *H,int n,int l,int m,int r){
  int n1,n2,i,j,k;
  n1=m-l;
  n2=r-m;
  for(i=0;i<n1;i++){
L[i]=H[l+i];
  }
  for(i=0;i<n2;i++){
R[i]=H[m+i];
  }
  L[n1]=R[n2]=SEN;
  i=0;
  j=0;
  for(k=l;k<r;k++){
    count++;
    if(L[i]<=R[j]){
      H[k]=L[i++];
    }
    else{
      H[k]=R[j++];
    }}}

void mergeSort(int *H,int n,int l,int r){
  if(l+1 < r){
    int m;
    m=(l+r)/2;
    mergeSort(H,n,l,m);
    mergeSort(H,n,m,r);
    merge(H,n,l,m,r);
  }}

