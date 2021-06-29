#include <iostream>
#include <vector>
using namespace std;

int main(void) {
  vector<int> v;
  int num, n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> num;
    v.push_back(num);
  }
  int cnt = 0;
  for (int i = 0; i < v.size(); i++) {
    int flag = 0;
    int index = i;
    int min = v[i];
    for (int j = i; j < v.size(); j++) {
      if (min > v[j]) {
        min = v[j];
        index = j;
        flag = 1;
      }
    }
    // for (int i = 0; i < v.size(); i++) {
    //  cout << v[i] << (i == v.size() - 1 ? "\n" : " ");
    // }
    // cout << "index: " << index << endl;
    if(flag == 1) {
      int temp = v[i];
      v[i] = v[index];
      v[index] = temp;
      cnt++;
    }
  }

  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << (i == v.size() - 1 ? "\n" : " ");
  }
  cout << cnt << endl;
}
 
