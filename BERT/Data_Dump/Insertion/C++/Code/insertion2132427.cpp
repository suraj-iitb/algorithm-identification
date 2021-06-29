#include <iostream>

#define MIN_N 1
#define MAX_N 100
#define MIN_A 0
#define MAX_A 1000

using namespace std;

void print_array(int* a, int n) {
  for(int i=0; i<n; i++) {
    cout << a[i];
    if(i != n-1) {
      cout << " ";
    }
  }
  cout << endl;
}

int main() {
  int n;
  cin >> n;
  int a[MAX_N];
  for(int i=0; i<n; i++) {
    cin >> a[i];
  }

  // insertion sort
  for(int i=1; i<n; i++) {
    print_array(a, n);
    int v = a[i];
    int j = i-1;
    while(j >= 0 && a[j] > v) {
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = v;
  }
  print_array(a, n);

  return 0;
}
