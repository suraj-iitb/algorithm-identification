#include <iostream>
#include <vector>

using namespace std;

vector<int> a;

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
  for(int i = 0; i < n; i++) {
    cin >> a.at(i);
  }

  int cCnt = 0;
  for(int i = 0; i < a.size(); i++) {
    for(int j = a.size() - 1; j > i; j--) {
      if(a.at(j) < a.at(j-1)) {
	int t = a.at(j);
	a.at(j) = a.at(j-1);
	a.at(j-1) = t;
	cCnt++;
      }
    }
  }
  
  print_a();
  cout << cCnt << endl;
  return 0;
}

