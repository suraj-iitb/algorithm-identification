#include <stdio.h>
#define MAX 500000
#define INF 2000000000

int LEFT[MAX/2], RIGHT[MAX];
int count = 0;

void merge(int S[], int n, int left, int mid, int right){
  int i, j, k;
  int n1, n2;

  n1 = mid-left;
  n2 = right-mid;

  for(i = 0; i < n1; i++){
    LEFT[i] = S[left+i];
  }
  for(i = 0; i < n2; i++){
    RIGHT[i] = S[mid+i];
  }

  LEFT[n1] = INF;
  RIGHT[n2] = INF;

  i = 0;
  j = 0;

  for(k = left; k < right; k++){
    count++;
    if(LEFT[i] <= RIGHT[j]){
      S[k] = LEFT[i++];
    }
    else{
      S[k] = RIGHT[j++];
    }
  }
}

void mergesort(int S[], int n, int left, int right){
  int mid;

  if(left+1 < right){
    mid = (left+right)/2;
    //再帰させる
    mergesort(S,n, left, mid);
    mergesort(S, n, mid, right);

    merge(S, n, left, mid, right);
  }
}

int main(){
  int S[MAX];
  int n, i;
  scanf("%d",&n);
  for(i = 0; i < n; i++) scanf("%d",&S[i]);

  mergesort(S,n, 0, n);
  for(i = 0; i < n; i++){
    printf("%d",S[i]);
    if(i != n-1) printf(" ");
  }
  printf("\n%d\n",count);
  return 0;
}

