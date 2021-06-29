#include <iostream>
using namespace std;

int main() {
  int n;  cin >> n;
  int v[100];
  for(int i = 0; i < n; i++) cin >> v[i];
  for(int i = 0; i < n; i++) cout << v[i] << (i == n-1 ? "\n" : " ");

  //---Insertion Sort---//
  for(int j = 1; j < n; j++) {
    //--- key を挿入していく ---//
    int key = v[j];
    //--- k は keyの左隣にあるインデックス ---//
    int k = j - 1;
    //--- key より小さければ右へずらす ---//
    while(k >= 0 && key < v[k]) {
      v[k + 1] = v[k];
      k--;
    }
    //--- ループが終わった段階で一つ左へ行きすぎているので k+1 で調整 ---//
    v[k + 1] = key;
    for(int i = 0; i < n; i++) {
      cout << v[i] << (i == n-1 ? "\n" : " ");
    }
  }
}

