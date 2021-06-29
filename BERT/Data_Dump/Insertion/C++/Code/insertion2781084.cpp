#include <iostream>

using namespace std;


void insertion_sort(int *seq, int length) {
  int key, j;
  for (int i = 1; i < length; i ++) {
    key = seq[i];
    j = i - 1;
    while (j >= 0 && seq[j] > key) {
      seq[j + 1] = seq[j];
      j --;
    }
    seq[j + 1] = key;
    for (int k = 0; k < length; k ++)
      cout << seq[k] << ((k == length-1) ? "" : " ");
    cout << endl;
  }
}


int main(){
  int N;
  int seq[100];
  cin >> N;
  for (int i = 0; i < N; i ++)
    cin >> seq[i];
  for (int k = 0; k < N; k ++)
    cout << seq[k] << ((k == N-1) ? "" : " ");
  cout << endl;
  insertion_sort(seq, N);
}

