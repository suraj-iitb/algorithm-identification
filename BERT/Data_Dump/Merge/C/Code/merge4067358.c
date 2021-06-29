#include <stdio.h>

#define S_MAX 500000
#define inf 1000000000

int cnt = 0;

void merge(int *,int,int,int);
void mergeSort(int *,int,int);

int main(void){
  int n,i;
  int S[S_MAX];

  scanf("%d",&n);
  for(i = 0;i < n;i++){
    scanf("%d",&S[i]);
  }

  mergeSort(S,0,n);
  
  for(i = 0;i < n;i++){
    if(i == n - 1){
      printf("%d\n%d\n",S[i],cnt);
    }else{
    printf("%d ",S[i]);
    }
  }

  return 0;
}

void merge(int *S,int left,int mid,int right){
  int N1,N2,i,j,k;
  N1 = mid - left;
  N2 = right - mid;
  int L[N1],R[N2];

  for(i = 0;i < N1;i++){
    L[i] = S[left + i];
  }
  for(i = 0;i < N2;i++){
    R[i] = S[mid + i];
  }
  L[N1] = inf;
  R[N2] = inf;
  i = 0;
  j = 0;
  for(k = left;k < right;k++){
    if(L[i] <= R[j]){
      S[k] = L[i];
      i++;
      cnt++;
    }else{
      S[k] = R[j];
      j++;
      cnt++;
    }
  }
}

void mergeSort(int *S,int left,int right){
  int mid;
  if(left + 1 < right){
    mid = (left + right) / 2;
    mergeSort(S,left,mid);
    mergeSort(S,mid,right);
    merge(S,left,mid,right);
  }
}

