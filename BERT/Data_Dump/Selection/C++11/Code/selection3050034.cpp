#include <iostream>

using namespace std;

void show_array(int a[], int n) {
  for (int i = 0; i < n - 1; i++) {
    cout << a[i] << " ";
  }
  cout << a[n-1] << endl;
}

int get_min_elem_index(int a[], int n, int begin, int end) {
  int min_elem = 10000;
  int min_elem_index;
  for (int i = begin; i <= end; i ++) {
    if (a[i] < min_elem) {
      min_elem = a[i];
      min_elem_index = i;
    }
  }
  //cout << "min_index:" << min_elem_index << endl;
  return min_elem_index;
}

int selection_sort2(int a[], int n) {
  int sw = 0;
  int minj;
  for (int i = 0; i < n - 1; i++) {
    minj = i;
    // 最小値探す
    //cout << "imakara min sagasu for " << i << endl;
    for (int j = i; j < n; j++) {
      //cout << "a[j]" << a[j] << endl;
      if (a[j] < a[minj]) {
        minj = j;
      }
    }
    //cout << "min:" << minj << "(" << a[minj] << ")" << " wo i:" << i << " to torikae" << endl;
    // 交換
    int tmp = a[minj];
    a[minj] = a[i];
    a[i] = tmp;

    if (i != minj) {
      sw++;
    }
  }
  return sw;
}


int selection_sort(int a[], int n) {
  int sw = 0;
  int b[110];
  for (int i = 0; i < n; i++) {
    int min_elem_index = get_min_elem_index(a, n, sw, n-1);
    //cout << "min_elem_index:" << min_elem_index << endl;
    if (sw == min_elem_index) {
      continue;
    }
    if (a[i] > a[min_elem_index]) {
      int tmp = a[min_elem_index];
      a[min_elem_index] = a[sw];
      a[sw] = tmp;
      sw++;
      //cout << "change" << endl;
      //show_array(a, n);
    }
    //cout << "-----------" << endl;
  }
  return sw;
}

int main() {
  int n;
  int a[110];
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int sw = selection_sort2(a, n);
  show_array(a, n);
  cout << sw << endl;
}

