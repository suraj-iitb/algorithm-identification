#include<iostream>
#include<vector>
using namespace std;

int printVector(vector<int> vc) {
  int i;
  for (i; i < vc.size() - 1; i++) {
    cout << vc[i] << " ";
  }

  cout << vc[i] << endl;

  return 0;
}

int bubbleSort(vector<int> &vc, int &counter) {
  bool existUnsorted = true;
  while (existUnsorted) {
    existUnsorted = false;
    // 処理中の要素と1つ前の要素を比べ、ソートされていなければ交換する
    for (int j = vc.size() - 1; j >= 1; j--) {
      if (vc[j] < vc[j - 1]) {
        int tmp = vc[j];
        vc[j] = vc[j - 1];
        vc[j - 1] = tmp;
        counter++;
        existUnsorted = true;
      }
    }
  }
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

  int sort_counter = 0;

  bubbleSort(elements, sort_counter);

  printVector(elements);
  cout << sort_counter << endl;

  return 0;
}

