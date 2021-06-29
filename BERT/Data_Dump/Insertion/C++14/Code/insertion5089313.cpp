#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <map>
#include <queue>
#include <climits>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;

vector<int> insertionSort (vector<int> vec) {
  vector<int> newVec = vec;
  for(int k = 0; k < newVec.size(); k++) {
    cout << newVec[k];
    if(k != newVec.size()-1) cout << " ";
  }
  cout << endl;

  for(int i = 1; i < vec.size(); i++) {
    int j = i-1;

    // jをi-1から0まで見ていき、今動かす対象のvec[i]よりも大きければ一個上にずらしていく。
    while (j >= 0 && newVec[j] > vec[i]) {
      newVec[j+1] = newVec[j];
      j--;
    }

    newVec[j+1] = vec[i];

    // 表示処理
    for(int k = 0; k < newVec.size(); k++) {
      cout << newVec[k];
      if(k != newVec.size()-1) cout << " ";
    }
    cout << endl;
  }

  return vec;
}

int main () {
  int n;
  cin >> n;

  vector<int> vec;

  int a;
  for(int i = 0; i < n; i++) {
    cin >> a;
    vec.push_back(a);
  }

  insertionSort(vec);
}

