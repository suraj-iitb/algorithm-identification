#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <cassert>
using namespace std;

void print_vector(const vector<int>& vec, const int n) {
  for(int i = 0; i < n; i++) {
    cout << vec[i];
    if(i != n - 1) {
      cout << " ";
    } else {
      cout << endl;
    }
  }
}

void insertion_sort(vector<int>& vec, int n) {
  print_vector(vec, n);
  for(int i = 1; i < n; i++) {
    int v = vec[i];
    int j = i - 1;
    while(j >= 0 && vec[j] > v) {
      vec[j + 1] = vec[j];
      j--;
    }
    vec[j + 1] = v;
    print_vector(vec, n);
  }
}

int main() {
  int n;
  cin >> n;
  vector<int> vec(n);
  for(auto& v : vec) {
    cin >> v;
  }
  insertion_sort(vec, n);
  return 0;
}

