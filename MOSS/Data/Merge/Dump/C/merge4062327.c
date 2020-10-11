#include<stdio.h>

#define MAX 500000
#define IMF 1000000001

int merge(int *,int,int,int);
int mergeSort(int *,int,int);

int cnt=0;

int main(){
  int n,S[MAX];
  int i;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }

  mergeSort(S,0,n);

  for(i=0;i<n-1;i++){
    printf("%d ",S[i]);
  }
  printf("%d\n",S[i]);
  printf("%d\n",cnt);

  return 0;
}

int merge(int *S,int left,int mid,int right)
{
  int n1 = mid-left,n2 = right-mid;
  int L[n1],R[n2];
  int i,j,k;

  for(i=0;i<n1;i++){
    L[i] = S[left+i];
  }
  for(i=0;i<n2;i++){
    R[i] = S[mid+i];
  }
  L[n1] = IMF;
  R[n2] = IMF;

  i=0;
  j=0;
  for(k=left;k<right;k++){
    if(L[i] <= R[j]){
      S[k] = L[i];
      i++;
      cnt++;
    }
    else{
      S[k] = R[j];
      j++;
      cnt++;
    }
  }
  
}

int mergeSort(int *S,int left,int right)
{
  int mid;
  
  if ((left+1) < right){
    mid = (left + right)/2;
    mergeSort(S,left,mid);
    mergeSort(S,mid,right);
    merge(S,left,mid,right);
  }
}

