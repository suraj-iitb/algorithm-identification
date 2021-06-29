#include<stdio.h>

#define INFTY 1000000000
#define N 5000000

void merge(int *,int,int,int);
void mergesort(int *,int,int);

int cnt=0;

int main(){
    int n,i,S[N];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&S[i]);
    }
    mergesort(S,0,n);
    for(i=0;i<n-1;i++){
        printf("%d ",S[i]);
    }
    printf("%d\n%d\n",S[n-1],cnt);
    return 0;
}

void mergesort(int S[],int left,int right){
    int mid;
  if (left + 1 < right){
    mid = (left + right)/2;
    mergesort(S, left, mid);
    mergesort(S, mid, right);
    merge(S, left, mid, right);
}
}

void merge(int S[],int left,int mid,int right){
    int n1,n2,L[N/2],R[N/2],i,j,k;
  n1 = mid - left;
  n2 = right - mid;
  for(i=0;i<n1;i++){
    L[i] = S[left + i];
  }
  for(i=0;i<n2;i++){
    R[i] = S[mid + i];
  }
  L[n1] = INFTY;
  R[n2] = INFTY;
  i = 0;
  j = 0;
  for(k=left;k<right;k++){
    if(L[i] <= R[j]){
      S[k] = L[i];
      i = i + 1;
    }
    else{ 
      S[k] = R[j];
      j = j + 1;
    }
    cnt++;
  }
}
