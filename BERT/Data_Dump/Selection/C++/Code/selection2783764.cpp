#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <limits.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <map>
#include <numeric>
#include <typeinfo>
#include <stdlib.h>


using namespace std;


int main(int argc, char* argv[]){
// 1 selectionSort(A, N) // N個の要素を含む0-オリジンの配列A
// 2   for i が 0 から N-1 まで
// 3     minj = i
// 4     for j が i から N-1 まで
// 5       if A[j] < A[minj]
// 6         minj = j
// 7     A[i] と A[minj] を交換

  int n, cnt = 0, tmp, minj;
  cin >> n;
  std::vector<int> a(n+1);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }

  for(int i=0; i<n; i++){
    minj = i;
    for(int j=i; j<n; j++){
      if (a[j] < a[minj]){
        minj = j;
      }
    }
    tmp = a[i];
    a[i] = a[minj];
    a[minj] = tmp;
    // for(int i=0; i<n-1; i++){
    //   cout << a[i] << " ";
    // }
    // cout << a[n-1] << endl;
    if(minj != i){
      cnt ++;
    }
  }

  for(int i=0; i<n-1; i++){
    cout << a[i] << " ";
  }
  cout << a[n-1] << endl;
  cout << cnt << endl;
}

