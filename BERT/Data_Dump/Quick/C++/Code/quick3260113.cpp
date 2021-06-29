#include <iostream>
#include <limits>
using namespace std;

struct Card {
  char mark;
  int num;
};

int partition(Card A[], int p, int r) {
  int x = A[r].num;
  int i = p-1;
  for (int j = p; j < r; ++j) {
    if (A[j].num <= x) {
      swap(A[++i].num, A[j].num);
      swap(A[i].mark, A[j].mark);
    }
  }
  swap(A[i+1].num, A[r].num);
  swap(A[i+1].mark, A[r].mark);
  return i+1;
}

void quickSort(Card A[], int p, int r) {
  if (p < r) {
    int q = partition(A, p, r);
    quickSort(A, p, q-1);
    quickSort(A, q+1, r);
  }
}

void merge(Card A[], int left, int mid, int right) {
  int n1 = mid - left;
  int n2 = right - mid;
  Card L[n1+1];
  Card R[n2+1];
  for (int i = 0; i < n1; i++) {
    L[i] = A[left + i];
  }
  for (int i = 0; i < n2; i++) {
    R[i] = A[mid + i];
  }
  L[n1].num=numeric_limits<int>::max();
  R[n2].num=numeric_limits<int>::max();
  int i = 0, j = 0;
  for (int k = left; k < right;k++) {
    if (L[i].num <= R[j].num) {
      A[k] = L[i++];
    } else {
      A[k] = R[j++];
    }
  }
}

void mergeSort(Card A[], int left, int right) {
  if (left+1 < right) {
    int mid = (left + right) / 2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}

bool isStable(Card A[], Card B[], int n) {
  for (int i = 0; i < n; i++) {
    if (A[i].num != B[i].num) {
      cout << "error";
      return false;
    }
    if (A[i].mark != B[i].mark) {
      return false;
    }
  }
  return true;
}


int main() {
  int n;
  cin >> n;
  Card A[n];
  Card compare[n];
  for (int i = 0; i < n; i++) {
    cin >> A[i].mark;
    cin >> A[i].num;
    compare[i] = A[i];
  }
  quickSort(A, 0, n-1);
  mergeSort(compare, 0, n);
  if(isStable(A, compare, n)) {
    cout << "Stable" << endl;
  } else {
    cout << "Not stable" << endl;
  }
  for (int i = 0; i < n; i++) {
    cout << A[i].mark << " " << A[i].num << endl;
  }
}

