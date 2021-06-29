#include<stdio.h>

void merge(int[],int,int,int);
void mergesort(int[],int,int);

int count=0;

int main(){
  int i;
  int n;
  int S[500000];
  int l,r;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  l=0;
  r=n;

  mergesort(S,l,r);
  
  for(i=0;i<n;i++){
    printf("%d",S[i]);
    if(i<n-1){
      printf(" ");
    }
  }
  printf("\n");
  printf("%d\n",count++);
  return 0;
}

void merge(int S[],int l,int m,int r){
  int i,j,k;
  int n1,n2;
  int L[500000];
  int R[500000];
  n1=m-l;
  n2=r-m;
  for(i=0;i<n1;i++){
    L[i]=S[l+i];
  }
  for(i=0;i<n2;i++){
    R[i]=S[m+i];
  }
  L[n1]=1000000001;
  R[n2]=1000000001;
  i = 0;
  j = 0;
  for(k=l;k<r;k++){
    count++;
    if(L[i]<=R[j]){ 
      S[k]=L[i];
      i = i+1;
    } else{
      S[k]=R[j];
      j = j+1;
    }
  }
}

void mergesort(int S[],int l,int r){
  int m;
  if(l+1 < r){
    m = (l+r)/2;
    mergesort(S,l,m);
    mergesort(S,m,r);
    merge(S,l,m,r);
  }
}
