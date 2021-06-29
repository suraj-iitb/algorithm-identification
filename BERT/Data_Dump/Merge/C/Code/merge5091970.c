#include <stdio.h>
#include <limits.h>

const int MAX = 5e5;
const int INF = INT_MAX;

void merge(int*, int, int, int);
void mergesort(int*, int, int);

int ans;

int main(){
  int n, i, hairetsu[MAX];

  scanf("%d" ,&n);
  
  for(i = 0 ; i < n ; i++){
    scanf("%d" ,hairetsu + i);
  }

  mergesort(hairetsu, 0, n);

  for(i = 0 ; i < n ; i++){
    printf("%d%c" ,hairetsu[i], i != n-1 ? ' ':'\n');
  }
  printf("%d\n" ,ans);

  return 0;
  
}

void merge(int hairetsu[], int left, int mid, int right){
  int n1 = mid - left, n2 = right - mid;
  int L[n1+1], R[n2+1], i, j, k;

  for(i = 0 ; i < n1 ; i++){
    L[i] = hairetsu[left + i];
  }

  for(i = 0 ; i < n2 ; i++){
    R[i] = hairetsu[mid + i];
  }

  L[n1] = R[n2] = INF;

  for(i = 0, j = 0, k = left ; k < right ; k++, ans++){
    if(L[i] <= R[j]){
      hairetsu[k] = L[i++];
    }else{
      hairetsu[k] = R[j++];
    }
  }
  
}

void mergesort(int hairetsu[], int left, int right){
  int mid;
  if(left + 1 < right){
    mid = (left + right) / 2;
    mergesort(hairetsu, left, mid);
    mergesort(hairetsu, mid, right);
    merge(hairetsu, left, mid, right);
  }
  
}
