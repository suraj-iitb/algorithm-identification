#include<stdio.h>
#define INFTY 1000000001
#define N 500000

void merge(int,int,int,int);
void mergeSort(int,int,int);
int S[N],count=0;

int main(){
  int n,i;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  
  mergeSort(n,0,n);

  for(i=0;i<n;i++){
    if(i>0) printf(" ");
    printf("%d",S[i]);
  }
  printf("\n");
  printf("%d\n",count);
  return 0;
}

void merge(int n,int l,int m,int r){
  int n1,n2,L[N],R[N],k,i,j;
  n1=m-l;
  n2=r-m;
  for(i=0;i<n1;i++){
    L[i]=S[l+i];
  }
  for(i=0;i<n2;i++){
    R[i]=S[m+i];
  }
  L[n1]=INFTY;
  R[n2]=INFTY;
  i=0;
  j=0;
  for(k=l;k<=r-1;k++){
    count++;
    if(L[i]<=R[j]){
      S[k]=L[i];
      i=i+1;
    }else{
      S[k]=R[j];
      j=j+1;
    }
  }
}

void mergeSort(int n,int l,int r){
  int m,i;
  if(l+1<r){
    m=(l+r)/2;
    mergeSort(n,l,m);
    mergeSort(n,m,r);
    merge(n,l,m,r);
  }
}

  

