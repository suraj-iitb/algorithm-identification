#include<stdio.h>

#define N 500000
#define INFTY 1000000000

void mergeSort(int S[],int n,int left,int right);
void merge(int S[],int n,int left,int mid,int right);

int L[N/2 + 2],R[N/2 + 2];
int count;

int main(void)
{
  int S[N],n;
  int i;

  scanf("%d",&n);
  for(i = 0;i < n;i++){
    scanf("%d",&S[i]);
  }

  mergeSort(S,n,0,n);

  printf("%d",S[0]);
  for(i = 1;i < n;i++){
    if(i != n) printf(" ");
    printf("%d",S[i]);
  }
  printf("\n");
  printf("%d\n",count);
  
  return 0;
}
    




void merge(int S[],int n,int left,int mid,int right){
  int n1,n2;
  int i,j,k;
  
  n1 = mid - left;
  n2 = right - mid;

  for(i = 0;i < n1;i++){
    L[i] = S[left+i];
  }
  for(i = 0;i < n2;i++){
    R[i] = S[mid+i];
  }
  
  L[n1] = INFTY;
  R[n2] = INFTY;
  
  i = 0;
  j = 0;
  
  for(k = left;k < right;k++){
    if(L[i] <= R[j]){
      S[k] = L[i];
      i++;
    } else {
      S[k] = R[j];
      j++;
    }
    count++;
  }
}



void mergeSort(int S[],int n,int left,int right){
  int m;
  
  if(left+1 < right){
    m = (left + right)/2;
    
    mergeSort(S,n,left,m);
    mergeSort(S,n,m,right);
    merge(S,n,left,m,right);
  }
}

