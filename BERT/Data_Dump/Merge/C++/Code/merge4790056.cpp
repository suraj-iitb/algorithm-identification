#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 500000
#define SENTINEL 1000000005

using namespace std;

vector<int> L(MAX/2+2);
vector<int> R(MAX/2+2);
int cnt = 0;

/*
 * merge
 */
void merge(vector<int> &S, int n, int left, int mid, int right) {
  //cout << "[merge] Running merge. left:" << left << " mid:" << mid << " right:" << right << "\n";

  // n1 = number of items in L, n2 = number of items in R
  int n1 = mid - left;
  int n2 = right - mid;

  // construct vector L and R
  for (int i=0; i < n1; i++) {
    L.at(i) = S.at(left + i);
  }
  for (int i=0; i < n2; i++) {
    R.at(i) = S.at(mid + i);
  }
  L.at(n1) = R.at(n2) = SENTINEL;

  // print debug
  /*
  cout << "L:";
  for (int i=0; i < n1; i++) {
    cout << L.at(i) << " ";
  }
  cout << "\n";
  cout << "R:";
  for (int i=0; i < n1; i++) {
    cout << R.at(i) << " ";
  }
  cout << "\n";
  */

  // compare L[0..] vs R[0..], then update the original list S[k] by the smaller value while (k < right)
  int i = 0, j = 0;
  for (int k = left; k < right; k++) {
    cnt++;
    if ( L.at(i) <= R.at(j) ) {
      S.at(k) = L.at(i++);
    }
    else {
      S.at(k) = R.at(j++);
    }
  }

  // print debug
  /*
  cout << "[merge] current S:";
  for (int k=0; k < n; k++) {
    cout << " ";
    cout << S.at(k);
  }
  cout << "\n";
  */
}

/*
 * mergeSort
 */
void mergeSort(vector<int> &S, int n, int left, int right) {
  //cout << "[mergeSort] left:" << left << " right:" << right << "\n";
  if ( left + 1 < right ) {
    int mid = (left + right) / 2;
    //cout << "[mergeSort] mid:" << mid << "\n";

    mergeSort(S, n, left, mid);
    mergeSort(S, n, mid, right);
    merge(S, n, left, mid, right);
  }
}

int main() {
  int n;
  cin >> n;

  vector<int> S(n + 1);
  for (int i=0; i < n; i++) {
    cin >> S.at(i);
  }

  mergeSort(S, n, 0, n);
  for (int i=0; i < n; i++) {
    if ( i > 0 ) {
      cout << " ";
    }
    cout << S.at(i);
  }
  cout << "\n";
  
  cout << cnt << "\n";
}
