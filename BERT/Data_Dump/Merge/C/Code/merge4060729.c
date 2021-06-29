#include <stdio.h>
#include <stdlib.h>
#define N 500000

void merge(int *,int,int,int);
void mergeSort(int *,int,int);

int cnt;

int main()
{
  int n,i,S[N];

  scanf("%d",&n);
  if(n>N) exit(1);
  for(i=0;i<n;i++){
    scanf(" %d",&S[i]);
    if(S[i]<0 || S[i]>1000000000) exit(2);
  }

  mergeSort(&S[0],0,n);
  
  for(i=0;i<n;i++){
    printf("%d",S[i]);
    if(i != n-1) printf(" ");
  }
  printf("\n");

  printf("%d\n",cnt);
  
  return 0;
}
  
void merge(int *S,int l,int m,int r)
{
  int n1,n2,i,L[N],R[N],j=0,k=0;

  n1 = m-l;
  n2 = r-m;

  //printf("確認 n1:%d , n2:%d\n",n1,n2);

  for(i=0;i<n1;i++) L[i] = S[l+i];
  for(i=0;i<n2;i++) R[i] = S[m+i];
  L[n1] = 999999999;
  R[n2] = 999999999;

  for(i=l;i<r;i++){
    cnt++;
    if(L[j]<=R[k]){
      S[i] = L[j];
      j += 1;
    }
    else{
      S[i] = R[k];
      k += 1;
    }
  }
}
void mergeSort(int *S,int l,int r)
{
  int m;
  
  if(l+1 < r){
    m = (l+r)/2;
    mergeSort(S,l,m);
    mergeSort(S,m,r);
    merge(S,l,m,r);
  }
}

