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
  int n,v,j;
  cin >> n;
  std::vector<int> a(n+1);
  for (int i=0; i<n; i++){
    cin >> a[i];
  }

  //表示
  for(int k=0; k<n-1; k++){
    cout << a[k] << " ";
  }
  cout << a[n-1] << endl;

  for (int i=1; i<n; i++){
    //挿入ソートの1ステップ
    v = a[i];
    j = i-1;
    while(j>=0 && a[j]>v){
      a[j+1] = a[j];//右に1つずらす
      j --;
    }
    a[j+1] = v;

    //表示
    for(int k=0; k<n-1; k++){
      cout << a[k] << " ";
    }
    cout << a[n-1] << endl;
  }
// 1 insertionSort(A, N) // N個の要素を含む0-オリジンの配列A
// 2   for i が 1 から N-1 まで
// 3     v = A[i]
// 4     j = i - 1
// 5     while j >= 0 かつ A[j] > v
// 6       A[j+1] = A[j]
// 7       j--
// 8     A[j+1] = v
  
  return 0;
}

