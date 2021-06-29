#include<stdio.h>
#define MAX 500000
#define SEN 2000000000

void marge(int*,int,int,int,int);
void margeSort(int*,int,int,int);

int L[MAX/2+2],R[MAX/2+2];
int cnt;

int main(){
  int i,n;
  int S[MAX];
  cnt = 0;

  scanf("%d",&n);

  for(i = 0;i < n;i++){
    scanf("%d",&S[i]);
  }

  margeSort(S,n,0,n);

  for(i = 0;i < n;i++){
    printf("%d",S[i]);
    if(i == n-1)break;
    printf(" ");
  }

  printf("\n%d\n",cnt);

  return 0;
}

void marge(int S[],int n,int left,int mid,int right){
  int i,k;
  int n1 = mid - left;
  int n2 = right - mid;

  for(i = 0;i < n1;i++){
    L[i] = S[left + i];
  }
  for(i = 0;i < n2;i++){
    R[i] = S[mid + i];
  }
  
  L[n1] = R[n2] = SEN;
  i = 0;
  int j = 0;

  for(k = left;k < right;k++){
    cnt++;
    if(L[i] <= R[j]){
      S[k] = L[i++];
    } else {
      S[k] = R[j++];
    }
  }
}

void margeSort(int S[],int n,int left,int right){
  if(left+1 < right){
    int mid = (left+right)/2;
    margeSort(S,n,left,mid);
    margeSort(S,n,mid,right);
    marge(S,n,left,mid,right);
  }
}

