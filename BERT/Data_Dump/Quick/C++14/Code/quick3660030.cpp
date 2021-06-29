#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define INFTY 2000000000

struct Card {
    char c;
    int x;
};

#define vc vector<Card>

void merge(vc& A, int left, int mid, int right) {

  int n1 = mid - left;
  int n2 = right - mid;
  vc L, R;
  for (int i = 0; i < n1; i++) {
      L.push_back(A[left + i]);
  }
  for (int i = 0; i < n2; i++) {
      R.push_back(A[mid + i]);
  }
  Card t;
  t.c = 'X';
  t.x = INFTY;
  L.push_back(t);
  R.push_back(t);
  int i = 0;
  int j = 0;
  for (int k = left; k < right; k++) {
      if (L[i].x <= R[j].x) {
          A[k] = L[i];
          i++;
      }
      else {
          A[k] = R[j];
          j++;
      }
  }
}

void mergeSort(vc& A, int left, int right) {
    if (left+1 < right) {
        int mid = (left + right)/2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int partition(vc& A, int p, int r) {
    int x = A[r].x;
    int i = p - 1;
    for (int j = p; j < r; j++) {
        if (A[j].x <= x) {
            i++;
            swap(A[i], A[j]);
        }
    }
    swap(A[i+1], A[r]);

    return i + 1;
}

void printArray(vc& A) {
    for (int i = 0; i < A.size(); i++) {
        cout << A[i].c << " " << A[i].x << endl;;
    }
}

void quickSort(vc& A, int p, int r) {
    if (p < r) {
        int q = partition(A, p, r);
        quickSort(A, p, q - 1);
        quickSort(A, q + 1, r);
    }
}

void compareArray(vc& A, vc& B) {
    for (int i = 0; i < A.size(); i++) {
        if (A[i].c != B[i].c) {
            cout << "Not stable" << endl;
            return;
        }
    }
    cout << "Stable" << endl;
    return;
}

int main() {

    int n;
    vc A, B;
    char tmp_c;
    int tmp_x;
    Card t;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tmp_c >> tmp_x;
        t.c = tmp_c;
        t.x = tmp_x;
        A.push_back(t);
    }
    B = A;

    quickSort(A, 0, n-1);
    mergeSort(B, 0, n);

    compareArray(A, B);
    printArray(A);

    return 0;
}

