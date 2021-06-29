#include <bits/stdc++.h>
using namespace std;

#define MAX 500000
#define SENTINEL 2000000000

int n;
int S[MAX];
int cmp = 0;
int L[MAX/2 + 2];
int R[MAX/2 + 2];

void merge(int S[], int begin, int mid, int end){
  //begin ~ mid-1
  //mid ~ end-1
  //のそれぞれが整列済
  for(int i=0; i<mid-begin; i++){
    L[i] = S[begin + i];
  }
  L[mid-begin] = SENTINEL;
  for(int i=0; i<end-mid; i++){
    R[i] = S[mid + i];
  }
  R[end-mid] = SENTINEL;

  int l_ptr = 0;
  int r_ptr = 0;

  for(int i=begin; i<end; i++){
    if(L[l_ptr] <= R[r_ptr]){
      S[i] = L[l_ptr++];
    }
    else{
      S[i] = R[r_ptr++];
    }
    cmp++;
  }
}


void mergeSort(int S[], int begin, int end){
  if(begin+1 < end){
    int mid = (begin + end)/2;
    mergeSort(S, begin, mid);
    mergeSort(S, mid, end);
    merge(S, begin, mid, end);
  }
}


int main(){

  scanf("%d", &n);
  for(int i=0; i<n; i++){
    scanf("%d", &S[i]);
  }

  mergeSort(S,0,n);

  for(int i=0; i<n-1; i++){
    printf("%d ", S[i]);
  }
  printf("%d\n%d\n",S[n-1],cmp);

  return 0;
}

