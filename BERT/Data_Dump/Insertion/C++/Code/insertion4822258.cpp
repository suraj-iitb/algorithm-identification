  #include <bits/stdc++.h>
  using namespace std;


  int main() {
    int n, a, w, j;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; ++i) {
      cin >> a;
      v.at(i) = a;
    }
    for(int i = 0; i < v.size(); ++i) {
      if(i == v.size() - 1) {
        cout << v.at(i);
      }else {
        cout << v.at(i) << " ";
      }
    }
    cout << endl;

    for(int i = 1; i < n; ++i) {
      w = v.at(i);
      j = i - 1;
      while(j >= 0 && v.at(j) > w) {
        v.at(j + 1) = v.at(j);
        j--;
      }
      v.at(j + 1) = w;
      for(int k = 0; k < n; ++k) {
        if(k == n - 1) {
          cout << v.at(k);
        }else {
          cout << v.at(k) << " ";
        }
      }
      cout << endl;
    }
  }

