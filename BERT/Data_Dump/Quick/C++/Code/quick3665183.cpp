#include<iostream>
using namespace std;
#define INF 1000000000

struct Card {
  char mark; int number;
};

int partition(Card A[], int left, int right){
  int x = A[right].number;
  int j = left;
  for ( int i = left; i < right; i++){
    if ( A[i].number <= x ){
      swap(A[i], A[j]);
      j ++;
    }
  }
  swap(A[j], A[right]);

  return j;
}

void quickSort(Card A[], int left, int right){
  if ( left < right ) {
    int q = partition(A, left, right);
    quickSort(A, left, q-1);
    quickSort(A, q+1, right);
  }
}

void merge(Card A[], int left, int mid, int right){
  int n1 = mid - left;
  int n2 = right - mid;
  Card l[n1], r[n2];
  for ( int i = 0; i < n1; i++){ l[i] = A[left + i]; } // 0 to mid-1
  for ( int i = 0; i < n2; i++){ r[i] = A[mid + i]; } // mid to right-1
  l[n1].number = INF;
  r[n2].number = INF;

  int i = 0, j = 0;
  for ( int k = left; k < right; k++){
    if ( l[i].number <= r[j].number){
      A[k] = l[i];
      i++;
    }else {
      A[k] = r[j];
      j++;
    }
  }
}

void mergeSort(Card A[], int left, int right){
  if ( left + 1 < right){
    int mid = ( left + right ) / 2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}

int main() {
  int n;
  cin >> n;
  Card c1[n+1], c2[n+1];

  char mark[2];
  int number;
  for ( int i = 0; i < n; i++){
    cin >> mark >> number;
    c1[i].mark = c2[i].mark = mark[0];
    c1[i].number = c2[i].number = number;
  }

  mergeSort(c1, 0, n);
  quickSort(c2, 0, n-1);

  string state = "Stable";
  for ( int i = 0; i < n; i++){
    if (c1[i].mark != c2[i].mark || c1[i].number != c2[i].number){
      state = "Not stable";
    }
  }

  cout << state << endl;
  for ( int i = 0; i < n; i++){
    cout << c2[i].mark << " " << c2[i].number << endl;
  }
  return 0;
}
