#include<stdio.h>
#define MAX 500000
#define SENTINEL 2000000000
void merge(int [],int,int,int);
void mergeSort(int [],int,int);

int cnt,n;
int L[MAX/2+2],R[MAX/2+2];

int main()
{
  int S[MAX],i;
  cnt=0;
  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  mergeSort(S,0,n);
  for(i=0;i<n;i++){
    if(i!=0) printf(" ");
    printf("%d",S[i]);
  }
  printf("\n%d\n",cnt);
  
  return 0;
}
  
void merge(int S[], int left, int mid,int right){
  int i,j,k;
  
  int n1 = mid - left;
  int n2 = right - mid;
  //L[0...n1], R[0...n2] を生成
  for(i=0;i<n1;i++) L[i] = S[left + i];
  for(i=0;i<n2;i++) R[i] = S[mid + i];
  L[n1]=R[n2]=SENTINEL;
  i=0;
  j=0;
  for(k=left;k<right;k++){
    cnt++;
    if(L[i]<=R[j]){
      S[k]=L[i++];
    }
    else{
      S[k]=R[j++];
    }
  }
}

void mergeSort(int *S, int left, int right){
  int mid,i;
  if(left+1<right){
    mid=(left + right)/2;
    mergeSort(S, left, mid);
    mergeSort(S, mid, right);
    merge(S, left, mid, right);
  }
}

