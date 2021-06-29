#include <iostream>

using namespace std;

int n;
int a[110];

void show_array() {
  for (int i = 0; i < n - 1; i++) {
    cout << a[i] << " ";
  }
  cout << a[n-1] << endl;
}


int bubble_sort(int a[], int n) {
  int sw = 0;
  bool flag = 1;
  for (int i = 0; flag; i++) {
    flag = 0;
    for (int j = n-1; j >= i + 1; j--) {
      if (a[j] < a[j-1]) {
        swap(a[j], a[j-1]);
        //cout << "change" << endl;
        flag = 1;
        sw++;
        show_array();
      }
    }
  }
  return sw;
}

int my_bubble_sort(int a[], int n) {
  int sw = 0;
  bool can_continue = true;
  int j = 0;
  while(can_continue) {
    can_continue = false;
    //cout << j << "----" << endl;
    for (int i = n-1; i > j; i--) {
      int tmp = a[i];
      //cout << tmp << endl;
      //cout << "a[i]" << a[i] << ", a[i-1]" << a[i-1] << endl;
      if (a[i] < a[i-1]) {
        a[i] = a[i-1];
        a[i-1] = tmp;
        can_continue = true;
        sw++;
      }
    }
    j++;
    //show_array();
  }
  return sw;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int sw = my_bubble_sort(a, n);
  show_array();
  cout << sw << endl;
  return 0;
  cout << "-------" << endl;

  show_array();
}

