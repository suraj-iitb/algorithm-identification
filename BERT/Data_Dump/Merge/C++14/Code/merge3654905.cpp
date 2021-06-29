#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define INFTY 2000000000;

int ans;

void merge(vi& A, int left, int mid, int right) {

  int n1 = mid - left;
  int n2 = right - mid;
  vi L, R;
  for (int i = 0; i < n1; i++) {
      L.push_back(A[left + i]);
  }
  for (int i = 0; i < n2; i++) {
      R.push_back(A[mid + i]);
  }
  L[n1] = INFTY;
  R[n2] = INFTY;
  int i = 0;
  int j = 0;
  for (int k = left; k < right; k++) {
      ans++;
      if (L[i] <= R[j]) {
          A[k] = L[i];
          i++;
      }
      else {
          A[k] = R[j];
          j++;
      }
  }
}

void mergeSort(vi& A, int left, int right) {
    if (left+1 < right) {
        int mid = (left + right)/2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int main() {

    int n;
    vi A;
    int tmp;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        A.push_back(tmp);
    }

    ans = 0;
    mergeSort(A, 0, n);

    for (int i = 0; i < A.size(); i++) {
        cout << A[i];
        if (i < A.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;
    cout << ans << endl;

    return 0;
}

