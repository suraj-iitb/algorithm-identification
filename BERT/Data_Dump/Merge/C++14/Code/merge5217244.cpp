# if 0

# endif
#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <map>
#include <queue>
#include <stack>
#include <climits>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;

#define MAX 500000
#define SENTINEL 2000000000

int counter= 0;
int L[MAX/2+2], R[MAX/2+2];

void merge(int A[], int n, int left, int mid, int right) {
  int n1 = mid - left;
  int n2 = right - mid;

  for(int i = 0; i < n1; i++) L[i] = A[left + i];
  for(int i = 0; i < n2; i++) R[i] = A[mid + i];

  L[n1] = R[n2] = SENTINEL;

  int i = 0, j = 0;

  // ここの条件文よくわからん
  for(int k = left; k < right; k++){

    counter++;
    // ここの条件分岐とやってることの意味がわからん。
    if(L[i] <= R[j]) {
    A[k] =L[i++];
    } else {
      A[k] = R[j++];
    }
  }
}

void mergeSort(int A[], int n, int left, int right) {
  // ?????????よくわからない....
  if( left + 1 < right) {
    int mid = (left + right ) / 2;
    mergeSort(A, n, left, mid);
    mergeSort(A, n, mid, right);
    merge(A, n, left, mid, right);
  }
}

int main () {
  // Aはソート対象の配列
  int A[MAX], n, i;

  counter = 0;

  cin >> n;

  for(int i=0; i<n; i++) cin >> A[i];

  mergeSort(A, n, 0, n);

  for(int i = 0; i<n; i++) {
    if(i) cout << " ";
    cout <<A[i];
  }

  cout << endl;

  cout << counter << endl;
  return 0;
}

