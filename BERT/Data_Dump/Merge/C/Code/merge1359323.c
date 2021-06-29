#include<stdio.h>
#include<limits.h>
#define N 500000
#define M 300000
#define SEN INT_MAX
int n,a=0;
int L[M],R[M],S[N];
int mergeSort(int,int);
int merge(int,int,int);
main(){
  int i,j;
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&S[i]);
  mergeSort(0,i);
  
  for(j=0;j<i;j++){
    printf("%d",S[j]);
    if(j<i-1){
      printf(" ");
    }
  }
  printf("\n");
  printf("%d\n",a);
  return 0;
}

int mergeSort(int left,int right){
  int mid;
  if (left + 1 < right){
    mid = (left + right) / 2;
    mergeSort(left, mid);
    mergeSort(mid, right);
    merge(left, mid, right);
  }
}





int merge(int left, int mid,int right){
  int i,j,k;
  int n1 = mid - left;
  int n2 = right - mid;


  for(i=0;i<n1;i++) L[i]=S[left+i];
  for(i=0;i<n2;i++) R[i]=S[mid+i];
  L[n1]=SEN;
  R[n2]=SEN;

  i=0;
  j=0;
  k=0;

  for(k=left;k<right;k++){
    a++;    
    if(L[i]<=R[j]){
      S[k]= L[i];
      i++;
    }
    else{
      S[k] = R[j];
      j++;
    }
  }
}
