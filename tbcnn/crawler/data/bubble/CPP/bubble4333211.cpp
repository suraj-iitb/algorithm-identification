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
  bool f = true;
  int count = 0;
  while(f){
    f = false;
    for(int i = n - 1; i > 0; i--){
      if(v[i] < v[i - 1]){
        swap(v[i], v[i - 1]);
        count++;
        f = true;
      }
    }
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
