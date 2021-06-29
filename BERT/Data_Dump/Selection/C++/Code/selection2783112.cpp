#include <iostream>

using namespace std;


int selection_sort(int *seq, int length) {
  int temp, mini, count = 0;
  for (int i = 0; i < length - 1; i ++) {
    mini = i;
    for (int j = i + 1; j < length; j ++) {
      if (seq[j] < seq[mini]) {
        mini = j;
      }
    }
    if (mini != i) {
      temp = seq[i];
      seq[i] = seq[mini];
      seq[mini] = temp;
      count ++;
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
  count = selection_sort(seq, N);
  for (int k = 0; k < N; k ++)
    cout << seq[k] << ((k == N-1) ? "" : " ");
  cout << endl;
  cout << count << endl;
}

