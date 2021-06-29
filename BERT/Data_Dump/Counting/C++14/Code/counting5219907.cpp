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

#define MAX (2000000 + 10)

// KはA[]に含まれる最大値

int n;

void countingSort (int A[], int B[], int k){
  vector<int> C;
  for(int i = 0; i <= k; i++) C.push_back(0);
  for(int i = 0; i < n; i++) C[A[i]]++;
  for(int i = 1; i <= k; i++) C[i] += C[i-1];

// 2 5 1 3 2 3 0
  for(int i = n-1; 0 <= i; i--) {
    B[C[A[i]]] = A[i];
    // cout << "i: " << i << " " << A[i] << " " << C[A[i]] << " " << B[C[A[i]]] << endl;
    C[A[i]]--;
  }
}

int main () {
  int A[MAX];
  int B[MAX];
  cin >> n;
  int k = 0;

  for(int i = 0; i < n; i++) {
    cin >> A[i];
    k = max(k, A[i]);
  }

  countingSort(A, B, k);

  for(int i = 0; i < n; i++) {
    if(i) cout << " ";
    cout << B[i+1];
  }

  cout << endl;
}

