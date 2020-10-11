#include<stdio.h>
#define MAX 500000
#define SEN 2000000000
void merge(int *,int,int,int,int);
void mergesort(int *,int,int,int);

int cnt = 0;
int main(){
  int n;

  int S[MAX];
  int i;
  scanf("%d",&n);
  for(i = 0;i < n;i++){
    scanf("%d",&S[i]);
  }
  mergesort(S,n,0,n);

  for(i = 0;i < n;i++){
    printf("%d",S[i]);
    if(i != n-1){
      printf(" ");
    }
  }
  printf("\n");
  printf("%d\n",cnt);
  return 0;
}


void merge(int S[],int n,int left,int mid,int right){
  int L[MAX],R[MAX];
  int n1 = mid - left;
  int n2 = right - mid;
  for(int i = 0;i < n1;i++){
    L[i] = S[left + i];
  }
  for(int i = 0;i < n2;i++){
    R[i] = S[mid + i];
  }
  L[n1] = R[n2] = SEN;
  int i = 0,j = 0;
  for(int k = left;k<right;k++){
    cnt++;
    if(L[i] < R[j]){
      S[k] = L[i++];
    }else{
      S[k] = R[j++];
    }
  }
}


void mergesort(int S[],int n,int left,int right){
  if(left+1<right){
    int mid = (left + right)/2;
    mergesort(S,n,left,mid);
    mergesort(S,n,mid,right);
    merge(S,n,left,mid,right);
  }
}

