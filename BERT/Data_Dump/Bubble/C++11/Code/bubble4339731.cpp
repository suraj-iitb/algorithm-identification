#include <bits/stdc++.h>
#include<iostream>
using namespace std;

string join(vector<int> v, const char* delim = 0) {
  string s;
  if (!v.empty()) {
    s += to_string(v[0]);
    for (int i = 1, c = v.size(); i < c; ++i) {
      if (delim) s += delim;
      s += to_string(v[i]);
    }
  }
  return s;
}

int main() {
    int N;
    cin >> N;
    vector<int> vec(N);
    for (int i = 0; i < N; i++) {
        cin >> vec.at(i);
    }

    bool flag = true;
    int count = 0;
    while (flag) {
        flag = false;
        for (int j = N-1; j >= 1; j--) {
            if (vec[j] < vec[j-1]) {
                count += 1;
                int tmp = vec[j];
                vec[j] = vec[j-1];
                vec[j-1] = tmp;
                flag = true;
            }
        }
    }

    const char* delim_ = " ";
    string answer = join(vec, delim_);
    answer.erase(answer.size() - std::char_traits<char>::length(delim_) + 1);
    answer.erase(0, answer.find_first_not_of(" \n\r\t"));
    cout << answer << endl;
    cout << count << endl;

    return 0;
}
