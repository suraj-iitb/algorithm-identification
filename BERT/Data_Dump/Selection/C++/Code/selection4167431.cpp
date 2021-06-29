#include <iostream>
#include <vector>

using namespace std;

vector<int> a;

void swap_a(int i1, int i2) {
  int tmp = a.at(i1);
  a.at(i1) = a.at(i2);
  a.at(i2) = tmp;
}

void print_a() {
  for(int i = 0; i < a.size(); i++) {
    cout << a.at(i);
    if(i < a.size() - 1) {
      cout << " ";
    }
  }
  cout << endl;
}

int main() {
  int n;
  cin >> n;

  a.resize(n);
  for(int i = 0; i < a.size(); i++) {
    cin >> a.at(i);
  }

  int swcnt = 0;
  int mini;
  for(int i = 0; i < n; i++) {
    mini = i;
    for(int j = i + 1; j < n; j++) {
      if(a.at(j) < a.at(mini)) {
	mini = j;
      }
    }
    if(i != mini) {
      swcnt++;
      swap_a(i, mini);
    }
  }

  print_a();
  cout << swcnt << endl;
}

