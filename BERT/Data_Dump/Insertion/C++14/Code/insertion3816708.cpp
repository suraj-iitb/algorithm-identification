#include <stdio.h>
#include <iostream>
#include <set>
#include <vector>
#include <map>
using namespace std;

int main() {

  vector<int> vc;
  std::map<int, int> mp; 
  set<int> st;

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    vc.push_back(num);
  }
  for (int s = 0; s < n - 1; s++) {
    cout << vc[s] << " ";
  }
  cout << vc[n-1] << endl;

  for (int i = 1; i < n; i++) {

    int v = vc[i];
    int j = i - 1;
    while(j >= 0 && vc[j] > v) {
      vc[j+1] = vc[j];
      j--;
    }
    vc[j+1] = v;

    for (int s = 0; s < n - 1; s++) {
      cout << vc[s] << " ";
    }
    cout << vc[n-1] << endl;
  }
}

