#include<stdio.h>
#define INF 1000000000
int cnt=0;
void merge(int *,int,int,int);
void mergeSort(int *,int,int);
int main(){
  int n;
  int S[500001];
  int i;
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&S[i]);
  mergeSort(S,0,n);
  for(i=0;i<n;i++){
    printf("%d",S[i]);
    if(i!=n-1) printf(" ");
  }
  printf("\n");
  printf("%d\n",cnt);
  return 0;
}

void merge(int S[],int left,int mid,int right){
  int n1 = mid - left;
  int n2 = right - mid;
  int L[n1+1],R[n2+1];
  int i,j,k;
  for(i=0;i<n1;i++) L[i] = S[left + i];
  for(i=0;i<n2;i++) R[i] = S[mid + i];
  L[n1] = INF;
  R[n2] = INF;
  i = 0;
  j = 0;
  for(k = left; k< right;k++){
    if(L[i] <= R[j]){
      S[k] = L[i];
      i++;
    }
    else {
      S[k] = R[j];
      j++;
    }
    cnt++;
  }
}

void mergeSort(int S[],int left,int right){
  int mid;
  if(left + 1 < right){
    mid = (left + right) / 2;
    mergeSort(S,left,mid);
    mergeSort(S,mid,right);
    merge(S,left,mid,right);
  }
}

