#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> vec(n);
  for(int i = 0; i < n; i++){
    cin >> vec.at(i);
  }

  int flag = 1,num = 0;
  while(flag) {
    flag = 0;
    for(int j = n - 1; j >= 1; j--){
      int container;
      if(vec.at(j) < vec.at(j - 1)) {
        container = vec.at(j);
        vec.at(j) = vec.at(j - 1);
        vec.at(j-1) = container;
        flag = 1;
        num++;
      }
    }
  }

  for(int i = 0; i < n; i++){
    if(i > 0) cout << " ";
    cout << vec.at(i);
  }

  cout << endl;
  cout << num << endl;

  
}
