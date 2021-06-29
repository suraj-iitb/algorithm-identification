#include <iostream>
#include <vector>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  std::vector<int> v;
  for(int tmp, k = 0; k < N; k++){
    cin >> tmp;
    v.push_back(tmp);
  }
  for (int i, key, j = 1; j <= v.size(); j++){
    bool isHead = true;
    for(int num : v){
      if (isHead){
        isHead = false;
      } else{
        cout << " ";
      }
      cout << num;
    }
    cout << endl;
    if (j == v.size()) { break; }
    key = v[j];
    i = j - 1;
    while (i >= 0 && v[i] > key){
      v[i+1] = v[i];
      i--;
    }
    v[i + 1] = key;
  }
  return 0;
}
