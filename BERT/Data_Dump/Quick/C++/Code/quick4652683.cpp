#include <bits/stdc++.h>
using namespace std;
const int INFTY = (1<<30);

struct Card{
  char suit;
  int value;
};

int partition(vector<Card> &A, int p, int r) {
  int x = A[r].value;
  int i = p - 1;
  for (int j = p; j < r; j++) {
    if (A[j].value <= x) {
      i++;
      swap(A[i], A[j]);
    }
  }
  swap(A[i+1], A[r]);
  return i + 1;
}

void quickSort(vector<Card> &A, int p, int r) {
  if (p < r) {
    int q = partition(A, p, r);
    quickSort(A, p, q - 1);
    quickSort(A, q + 1, r);
  }
}

void merge(vector<Card> &A, int left, int mid, int right) {
  int n1 = mid - left;
  int n2 = right - mid;
  vector<Card> L(n1+1);
  vector<Card> R(n2+1);
  for (int i = 0; i < n1; i++) {
    L[i] = A[left+i];
  }
  for (int j = 0; j < n2; j++) {
    R[j] = A[mid+j];
  }
  L[n1].value = INFTY;
  R[n2].value = INFTY;
  int i = 0;
  int j = 0;
  for (int k = left; k < right; k++) {
    if (L[i].value <= R[j].value) {
      A[k] = L[i];
      i++;
    }
    else {
      A[k] = R[j];
      j++;
    }
  }
}

void mergeSort(vector<Card> &A, int left, int right) {
  if (right - left > 1) {
    int mid = (left + right) / 2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}

int main() {
  int n;
  cin >> n;
  vector<Card> A(n), B(n);
  for (int i = 0; i < n; i++) {
    char s;
    int v;
    cin >> s >> v;
    A[i].suit = s;
    A[i].value = v;
  }
  B = A;
  
  quickSort(A, 0, n - 1);
  mergeSort(B, 0, n);

  bool is_same = true;
  for (int i = 0; i < n; i++) {
    if (!(A[i].suit == B[i].suit && A[i].value == B[i].value)) {
      is_same = false;
      break;
    }
  }

  if (is_same) {
    cout << "Stable" << endl;
  }
  else {
    cout << "Not stable" << endl;
  }
  for (int i = 0; i < n; i++) {
    cout << A[i].suit << " " << A[i].value << endl;
  }
}
