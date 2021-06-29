#include <bits/stdc++.h>
using namespace std;
//using ll = long long;

void merge(vector<int> &A, int left, int mid, int right, int &count) {
  int n1 = mid - left;
  int n2 = right - mid;
  vector<int> L(n1+1);
  vector<int> R(n2+1);
  for (int i = 0; i < n1; i++)
    L.at(i) = A.at(left+i);
  for (int i = 0; i < n2; i++) 
    R.at(i) = A.at(mid+i);
  L.at(n1) = 2147483647;
  R.at(n2) = 2147483647;
  int i = 0, j = 0;
  for(int k = left; k < right; k++) {
    if (L.at(i) <= R.at(j)) {
      A.at(k) = L.at(i);
      i++;
      count++;
    } else {
      A.at(k) = R.at(j);
      j++;
      count++;
    }
  }
}

void mergeSort(vector<int> &A, int left, int right, int &count) {
  if (left+1 < right) {
    int mid = (left + right) / 2;
    mergeSort(A, left, mid, count);
    mergeSort(A, mid, right, count);
    merge(A, left, mid, right, count);
  }
}

void display(vector<int> A) {
  for (int i = 0; i < A.size(); i++) {
    cout << A.at(i);
    if (i != A.size()-1) 
    cout << " ";
  }
  cout << endl;
}
int main(void) {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i = 0; i < n; i++)
    cin >> A.at(i);
  int count = 0;
  mergeSort(A, 0, n, count);
  display(A);
  cout << count << endl;
}
