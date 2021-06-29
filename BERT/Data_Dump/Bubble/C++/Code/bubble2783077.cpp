#include <iostream>

using namespace std;


int buble_sort(int *seq, int length) {
  int temp, count = 0;
  for (int i = 0; i < length; i ++) {
    for (int j = length - 1; j > i; j --) {
      if (seq[j] < seq[j-1]) {
        temp = seq[j];
        seq[j] = seq[j - 1];
        seq[j - 1] = temp;
        count ++;
      }
    }
  }
  return count;
}


int main(){
  int N, count;
  int seq[100];
  cin >> N;
  for (int i = 0; i < N; i ++)
    cin >> seq[i];
  count = buble_sort(seq, N);
  for (int k = 0; k < N; k ++)
    cout << seq[k] << ((k == N-1) ? "" : " ");
  cout << endl;
  cout << count << endl;
}

