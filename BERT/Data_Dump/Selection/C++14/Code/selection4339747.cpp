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

    int count = 0;
    for (int i =0; i < N; i++) {
        int minJ = i;
        for (int j=i; j < N; j++) {
            if (vec[j] < vec[minJ]) {
                minJ = j;
            }
        }

        if (i != minJ && vec[i] != vec[minJ])
        {
            int tmp = vec[i];
            vec[i] = vec[minJ];
            vec[minJ] = tmp;
            count += 1;
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
