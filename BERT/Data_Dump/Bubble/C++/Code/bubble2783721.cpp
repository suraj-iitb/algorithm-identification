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
// 1 bubbleSort(A, N) // N 個の要素を含む 0-オリジンの配列 A
// 2   flag = 1 // 逆の隣接要素が存在する
// 3   while flag
// 4     flag = 0
// 5     for j が N-1 から 1 まで
// 6       if A[j] < A[j-1]
// 7         A[j] と A[j-1] を交換
// 8         flag = 1
//   return 0;

  int n, cnt = 0, tmp;
  cin >> n;
  std::vector<int> a(n+1);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  bool flag = true;
  while(flag){
    flag = false;
    for(int j=n-1; j>0; j--){
      if(a[j] < a[j-1]){
        tmp = a[j];
        a[j] = a[j-1];
        a[j-1] = tmp;
        flag = true;
        cnt ++;
      }
    }
  }
  for(int i=0; i<n-1; i++){
    cout << a[i] << " ";
  }
  cout << a[n-1] << endl;
  cout << cnt << endl;
}

