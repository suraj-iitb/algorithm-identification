// Last Change:           11/26/2018 18:18:13.
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <list>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

struct Card {
  char mark;
  int num;
};

int Partition(Card card[], int p, int r) {
  Card x = card[r];
  int i = p - 1;
  Card tmp;
  for (int j = p; j < r; j++) {
    if (card[j].num <= x.num) {
      i++;
      tmp = card[j];
      card[j] = card[i];
      card[i] = tmp;
    }
  }
  tmp = card[i + 1];
  card[i + 1] = card[r];
  card[r] = tmp;
  return i + 1;
}

void QuickSort(Card card[], int p, int r) {
  if (p < r) {
    int q = Partition(card, p, r);
    QuickSort(card, p, q - 1);
    QuickSort(card, q + 1, r);
  }
}

#define INFTY 1000000010
int countNum;
Card L[250005];
Card R[250005];
void Merge(Card A[], int left, int mid, int right) {
  int n1 = mid - left;
  int n2 = right - mid;
  for (int i = 0; i < n1; i++) {
    L[i] = A[left + i];
  }
  for (int i = 0; i < n2; i++) {
    R[i] = A[mid + i];
  }
  L[n1].num = INFTY;
  R[n2].num = INFTY;
  int i = 0;
  int j = 0;
  for (int k = left; k < right; k++) {
    if (L[i].num <= R[j].num) {
      A[k] = L[i];
      i++;
    } else {
      A[k] = R[j];
      j++;
    }
    countNum++;
  }
}

void MergeSort(Card A[], int left, int right) {
  if (left + 1 < right) {
    int mid = (left + right) / 2;
    MergeSort(A, left, mid);
    MergeSort(A, mid, right);
    Merge(A, left, mid, right);
  }
}

int main() {
  int N;
  Card card[100000], A[100000];
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> card[i].mark >> card[i].num;
    A[i] = card[i];
  }
  QuickSort(card, 0, N - 1);
  MergeSort(A, 0, N);

  bool isStable = true;
  for (int i = 0; i < N; i++) {
    if (card[i].mark != A[i].mark) { // structの比較はそのままでは行えない
      isStable = false;
      break;
    }
  }
  if (isStable) {
    cout << "Stable" << endl;
  } else {
    cout << "Not stable" << endl;
  }

  for (int i = 0; i < N; i++) {
    cout << card[i].mark << " " << card[i].num << "\n";
  }
  cout << flush;
}

