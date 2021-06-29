#include <iostream>
#include <climits>
using namespace std;

struct Card {
  char suit;
  int num;
};

void merge(Card A[], int left, int mid, int right) {
  int n1 = mid - left;
  int n2 = right - mid;
  Card *L = new Card[n1+1];
  Card *R = new Card[n2+1];
  for (int i = 0; i < n1; i++) L[i] = A[left + i];
  for (int i = 0; i < n2; i++) R[i] = A[mid + i];
  L[n1].num = R[n2].num = INT_MAX;

  int i = 0, j = 0;
  for (int k = left; k < right; k++) {
    if (L[i].num <= R[j].num) {
      A[k] = L[i++];
    } else {
      A[k] = R[j++];
    }
  }
}

void mergeSort(Card A[], int left, int right) {
  if (left + 1 < right) {
    int mid = (left + right) / 2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}

int partition(Card A[], int p, int r) {
  Card x = A[r];
  int i = p - 1;
  for (int j = p; j < r; j++) {
    if (A[j].num <= x.num) {
      i++;
      swap(A[i], A[j]);
    }
  }
  swap(A[i+1], A[r]);
  return i+1;
}

void quickSort(Card A[], int p, int r) {
  if (p < r) {
    int q = partition(A, p, r);
    quickSort(A, p, q-1);
    quickSort(A, q+1, r);
  }
}

int main() {
  int n;
  cin >> n;

  Card *A = new Card[n];
  Card *B = new Card[n];
  for (int i = 0; i < n; i++) {
    cin >> A[i].suit >> A[i].num;
    B[i] = A[i];
  }

  quickSort(A, 0, n-1);
  mergeSort(B, 0, n);

  bool flag = false;
  for (int i = 0; i < n; i++) {
    if (A[i].suit != B[i].suit) {
      flag = true;
      break;
    }
  }
  if (flag) cout << "Not stable" << endl;
  else cout << "Stable" << endl;

  for (int i = 0; i < n; i++) {
    cout << A[i].suit << " " << A[i].num << endl;
  }

  return 0;
}
