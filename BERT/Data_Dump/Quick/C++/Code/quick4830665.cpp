#include <iostream>
#include <cmath>

using namespace std;

template<typename T>
void swap(T *a, T *b){
  T tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}

struct Card {
  char c;
  int v;
};

int partition(Card *A, int p, int r) {
  int i = p-1;
  int x = A[r].v;
  for(int j = p; j < r; j++) {
    if(A[j].v <= x) {
      i++;
      swap(A[i], A[j]);
    }
  }
  swap(A[r], A[i+1]);

  return i+1;
}

void quicksort(Card *A, int p, int r) {
  if(p < r) {
    int q = partition(A, p, r);
    quicksort(A, p, q-1);
    quicksort(A, q+1, r);
  }
}

void merge(Card *B, int left, int mid, int right) {
  int n1 = mid - left;
  int n2 = right - mid;
  Card L[n1+1], R[n2+1];
  for(int i = 0; i < n1; i++) L[i] = B[left + i];
  for(int i = 0; i < n2; i++) R[i] = B[mid + i];

  L[n1] = {'X', (int)pow(10, 9)};
  R[n2] = {'Y', (int)pow(10, 9)};

  int i = 0, j = 0;
  for(int k = left; k < right; k++) {
    if(L[i].v <= R[j].v) {
      B[k] = L[i];
      i++;
    } else {
      B[k] = R[j];
      j++;
    }
  }
}

void mergeSort(Card *B, int left, int right) {
  if(left+1 < right) {
    int mid = (left+right)/2;
    mergeSort(B, left, mid);
    mergeSort(B, mid, right);
    merge(B, left, mid, right);
  }
}

int main(){
  int n;
  cin >> n;
  Card A[n], B[n];
  for(int i = 0; i < n; i++) cin >> A[i].c >> A[i].v;

  // bubble sort
  for(int i = 0; i < n; i++) {
    B[i].c = A[i].c;
    B[i].v = A[i].v;
  }
  mergeSort(B, 0, n);

  quicksort(A, 0, n-1);

  bool stable = true;
  for(int i = 0; i < n; i++) {
    if(B[i].c != A[i].c) {
      stable = false;
      break;
    }
  }
  if(stable) cout << "Stable" << endl;
  else cout << "Not stable" << endl;

  for(int i = 0; i < n; i++) {
    cout << A[i].c << " " << A[i].v << endl;
  }

  return 0;
}

