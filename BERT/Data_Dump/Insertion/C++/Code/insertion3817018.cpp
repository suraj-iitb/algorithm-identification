#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>
#include <string>
#include <cstdio>
#include <cmath>
#include <cstdlib>
using namespace std;

void insertionSort(vector<int> a, int n){
  //表示
  cout << a[0];
  for (int x = 1; x < n; x++){
    cout << " " << a[x];
  }
  cout << "\n";

  for (int i = 1; i < n; i++){
    int tmp = a[i];
    int j = i - 1;

    while(j >= 0 && a[j] > tmp){
      a[j + 1] = a[j];
      j--;
    }
    a[j + 1] = tmp;

    //表示
    cout << a[0];
    for (int x = 1; x < n; x++){
      cout << " " << a[x];
    }
    cout << "\n";
  }
}

int main(){
  int n;
  vector<int> a;

  cin >> n;

  a.resize(n);

  for (int i = 0; i < n; i++){
    int num;
    cin >> num;
    a[i] = num;
  }

  insertionSort(a, n);

  return 0;
}

