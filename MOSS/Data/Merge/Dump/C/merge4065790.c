#include <stdio.h>
#define INFTY 1410065408

void mergeSort(int*,int,int);
void merge(int*,int,int,int);

int count=0;

int main(){
  int n,i;
  scanf("%d",&n);
  int S[n];

  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }

  mergeSort(S,0,n);

  for(i=0;i<n;i++){
    if(i==n-1) printf("%d\n",S[i]);
    else printf("%d ",S[i]);
  }
  printf("%d\n",count);
  
  return 0;
}

void mergeSort(int *S,int left,int right){
  int mid=(left+right)/2;
  if(left+1<right){
    mergeSort(S,left,mid);
    mergeSort(S,mid,right);
    merge(S,left,mid,right);
  }
  
}


void merge(int *S,int left,int mid,int right){
  int i,j,k;
  int n1=mid-left;
  int n2=right-mid;
  int L[n1+1],R[n2+1];
  
  for(i=0;i<n1;i++){
    L[i]=S[left+i];
  }
  L[i]=INFTY;
  
  for(i=0;i<n2;i++){
    R[i]=S[mid+i];
  }
  R[i]=INFTY;
  
  i=0;
  j=0;

  for(k=left;k<right;k++){
    if(L[i]<=R[j]){
      S[k]=L[i];
      i++;
    }

    else{
      S[k]=R[j];
      j++;
    }
    count++;
  }
}

