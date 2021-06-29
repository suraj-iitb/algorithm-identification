#include<iostream>
using namespace std;
#define SENTINEL 2000000000

struct Card {
  char mark;
  int number;
};

int partition(Card A[], int p, int r){
  int x = A[r].number;
  int i = p - 1;
  for (int j = p; j < r; j++){
    if ( A[j].number <= x){
      i++;
      swap(A[i],A[j]);
    }
  }
  swap(A[i+1], A[r]);

  return i+1;
}

void quickSort(Card A[], int p, int r){
  if (p < r){
    int q = partition(A, p, r);
    quickSort(A, p, q-1);
    quickSort(A, q+1, r);
  }
}

void merge(Card A[], int left, int mid, int right){
  Card L[100000], R[100000];
  int n1 = mid - left;
  int n2 = right - mid;
  for ( int i = 0; i < n1; i++) L[i] = A[left + i];
  for ( int i = 0; i < n2; i++) R[i] = A[mid + i];
  L[n1].number = R[n2].number = SENTINEL;

  int i = 0, j = 0;
  for ( int k = left; k < right; k++){
    if ( L[i].number <= R[j].number ) A[k] = L[i++];
    else A[k] = R[j++];
  }
}

void mergeSort(Card A[], int left, int right){
  if (left + 1 < right){
    int mid = (left + right) / 2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}

int main(){
  int n, val, stable = 1;
  char mark;

  Card A[100000], B[100000];

  cin >> n;
  for ( int i = 0; i < n; i++){
    cin >> mark >> val;
    A[i].mark = B[i].mark = mark;
    A[i].number = B[i].number = val;
  }

  quickSort(A, 0, n-1);
  mergeSort(B, 0, n);

  for ( int i = 0; i < n; i++){
    if (A[i].mark != B[i].mark) stable = 0;
  }
  if (stable) cout << "Stable" << endl;
  else cout << "Not stable" << endl;

  for ( int i = 0; i < n; i++) cout << A[i].mark << " " << A[i].number << endl;

  return 0;
}
