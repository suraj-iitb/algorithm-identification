#include<iostream>
#include<vector>
using namespace std;

int print_vector(vector<int> vc) {
  int i;
  for (i; i < vc.size() - 1; i++) {
    cout << vc[i] << " ";
  }

  cout << vc[i] << endl;

  return 0;
}

int main()
{
  int element_number;
  cin >> element_number;

  vector<int> elements;
  for (int i = 0; i < element_number; i++) {
    int n;
    cin >> n;
    elements.push_back(n);
  }

  print_vector(elements);

  int v, j;

  for (int i = 1; i < element_number; i++) {
    v = elements[i];

    // 今見ている要素の一つ前の要素から比較を始める
    j = i - 1;
    while (j >= 0 && elements[j] > v) {
      elements[j + 1] = elements[j];
      j--;
    };
    elements[j+1] = v;
    print_vector(elements);
  }

  return 0;
}

