#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <functional>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> v(n, 0);
  for(int i = 0; i < n; i++){
    cin >> v[i];
  }
  int count = 0;
  for(int i = 0; i < n; i++){
    bool f = false;
    int minj = i;
    for(int j = i; j < n; j++){
      if(v[j] < v[minj]){
        minj = j;
        f = true;
      }
    }
    swap(v[i], v[minj]);
    if(f){ count++; }
  }
  
  for(int i = 0; i < n; i++){
    if(i != n - 1){
      cout << v[i] << " ";
    }
    else{
      cout << v[i] << endl;
    }
  }
  cout << count << endl;
} 
