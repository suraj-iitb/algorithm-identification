#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstdio>
#include <queue>
using namespace std;

typedef pair<int, char> p;

int partition(vector<p> &v, int p, int r){
  int x = v[r].first;
  int i = p-1;
  for(int j=p;j<r;j++){
    if(v[j].first <= x){
      swap(v[++i], v[j]);
    }
  }
  swap(v[i+1], v[r]);

  return i+1;
}

void quickSort(vector<p> &v, int p, int r){
  if(p < r){
    int q = partition(v, p, r);
    quickSort(v, p, q-1);
    quickSort(v, q+1, r);
  }
}

int main(void){
  int n;
  cin >> n;
  vector<p> v(n);
  vector<p> b(n);

  for(int i=0;i<n;i++){
    cin >> v[i].second >> v[i].first;
    b[i].first = v[i].first;
    b[i].second = v[i].second;
  }
  
  quickSort(v, 0, n-1);

  for(int i=1;i<n;i++){
    if(v[i].first == v[i-1].first){
      int k,l;
      for(k=0;k<n;k++){
        if(v[i-1].first == b[k].first && v[i-1].second == b[k].second){
          break;
        }
      }
      for(l=0;l<n;l++){
        if(v[i].first == b[l].first && v[i].second == b[l].second){
          break;
        }
      }
      if(k > l){
        cout << "Not stable" << endl;
        break;
      }
    }
    if(i == n-1)
      cout << "Stable" << endl;
  }
  for(int i=0;i<n;i++){
    cout << v[i].second << " " << v[i].first << endl;
  }
  return 0;
}
