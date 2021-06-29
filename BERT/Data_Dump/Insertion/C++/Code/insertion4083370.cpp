#include <iostream>
#include <vector>

using namespace std;


vector<int> a;

void print_a() {
  for(unsigned long i  = 0; i < a.size(); i++) {
    cout << a.at(i);
    if(i < a.size() - 1) {
      cout << " ";
    }
    else {
      cout << endl;
    }
  }
}

int main() {
  int n;
  cin >> n;

  a.resize(n);
  for(int i = 0; i < n; i++) {
    cin >> a.at(i);
  }

  print_a();
  
  for(int i = 0; i < n - 1; i++) {
    for(int j = i; j >= 0; j--) {
      if(a[j + 1] < a[j]) {
	int t = a[j + 1];
	a[j + 1] = a[j];
	a[j] = t;
      }
      else {
	break;
      }
    } 
    print_a();
 }

  return 0;
}

