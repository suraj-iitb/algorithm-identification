#include <stdio.h>
#define N 1000000001
void merge(int*,int,int,int);
void mergeSort(int*,int,int);
int count=0,L[250002],R[250002];
int main(){
  int n,i,S[500000];
  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&S[i]);
  
  mergeSort(S,0,n);

  for(i=0;i<n;i++){
    if(i)
      printf(" ");
    printf("%d",S[i]);
  }

  printf("\n");
  printf("%d\n",count);

  return 0;
}
void merge(int* S,int l,int m,int r){
  int n1,n2,i,j,k;
  n1=m-l;
  n2=r-m;

  for(i=0;i<n1;i++)
    L[i]=S[l+i];
  for(i=0;i<n2;i++)
    R[i]=S[m+i];
  L[n1]=N;
  R[n2]=N;
  i=0;
  j=0;
  for(k=l;k<r;k++){
    count++;
    if(L[i]<=R[j]){
      S[k]=L[i];
      i+=1;
    }
    else {
     S[k]=R[j];
      j+=1;
    }
  }
}
void mergeSort(int* S,int l,int r){
  int m;
  if(l+1<r){
    m=(l+r)/2;
    mergeSort(S,l,m);
    mergeSort(S,m,r);
    merge(S,l,m,r);
  }
}

