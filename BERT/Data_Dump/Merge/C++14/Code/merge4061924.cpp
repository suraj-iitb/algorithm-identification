#include <vector>
#include <cstdio>
#define INF (10e9+1)
#define int long long
using namespace std;
int comp;
void merge(int* A, int left, int mid, int right){
  int n1 = mid - left;
  int n2 = right - mid;
  vector<int> L(n1+1), R(n2+1);
  for( int i = 0; i < n1 ; ++i)
    L[i] = A[left + i] ;
  for( int i = 0; i < n2 ; ++i)
    R[i] = A[mid + i];
  L[n1] = INF;
  R[n2] = INF;
  int i = 0, j = 0;
  for (int k = left ; k < right ; ++k){
    if (L[i] <= R[j]){
      A[k] = L[i];
      i = i + 1;
    }
    else {
      A[k] = R[j];
      j = j + 1;
    }
    comp++;
  }
}

void mergeSort(int* A, int left, int right){
  if (left+1 < right){
    int mid = (left + right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}

int s[500000];
signed main(){
  int n;
  scanf("%lld", &n);
  for (int i=0;i<n;i++){
    scanf("%lld", s+i);
  }
  comp = 0;
  mergeSort(s, 0, n);
  for (int i=0;i<n;i++){
    if (i!=0) printf(" ");
    printf("%lld", s[i]);
  }
  printf("\n%d\n", comp);
  return 0;
}

