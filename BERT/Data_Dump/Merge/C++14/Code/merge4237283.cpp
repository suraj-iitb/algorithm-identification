#include <bits/stdc++.h>
using namespace std;

size_t N;
vector<int> A;
unsigned CNT = 0;

void read() {
  cin >> N;
  for (size_t i = 0; i < N; i++) {
    int a;
    cin >> a;
    A.push_back(a);
  }
}

void merge(vector<int> &A, size_t left, size_t mid, size_t right) {
  size_t n1 = mid - left;
  size_t n2 = right - mid;
  vector<int> L(n1 + 1);
  vector<int> R(n2 + 1);
  L.at(n1) = 1'000'000'000 + 1;
  R.at(n2) = 1'000'000'000 + 1;
  for (size_t i = 0; i < n1; i++) L.at(i) = A.at(left + i);
  for (size_t i = 0; i < n2; i++) R.at(i) = A.at(mid + i);
  size_t i = 0;
  size_t j = 0;
  for (size_t k = left; k < right; k++) {
    CNT++;
    if (L.at(i) <= R.at(j))
      A.at(k) = L.at(i++);
    else
      A.at(k) = R.at(j++);
  }
}

void merge_sort(vector<int> &A, size_t left, size_t right) {
  if (left + 1 < right) {
    size_t mid = (left + right) / 2;
    merge_sort(A, left, mid);
    merge_sort(A, mid, right);
    merge(A, left, mid, right);
  }
}

int main() {
  read();
  merge_sort(A, 0, N);
  cout << A.at(0);
  for (size_t i = 1; i < N; i++) cout << " "s << A.at(i);
  cout << endl;
  cout << CNT << endl;
}

