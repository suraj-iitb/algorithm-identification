#include<iostream>
using namespace std;

const int N = 500000;
const int INFTY = 1000000001;
int cnt;

void merge(int left, int mid, int right, int S[]) {
  int i, j, k, n1, n2;  
  n1 = mid - left;
  n2 = right - mid;
  
  int L[n1+1], R[n2+1];
  for (i = 0; i < n1; i++) L[i] = S[left+i];
  for (i = 0; i < n2; i++) R[i] = S[mid+i];
  L[n1] = R[n2] = INFTY;

  j = k = 0;
  for (i = 0; i < n1 + n2; i++) {
    if (L[j] <= R[k]) S[left+i] = L[j++];
    else S[left+i] = R[k++];
    cnt++;
  }
}

void merge_sort(int left, int right, int S[]) {
  if (left + 1 < right) {
    int mid = (left + right) / 2;
    merge_sort(left, mid, S);
    merge_sort(mid, right, S);
    merge(left, mid, right, S);
  }
}

int main() {
  int i, n;
  int S[N];

  cin >> n;
  for (i = 0; i < n; i++) cin >> S[i];

  cnt = 0;
  merge_sort(0, n, S);

  for (i = 0; i < n; i++) {
    if (i > 0) cout << " ";
    cout << S[i];
  }
  cout << endl << cnt << endl;

  return 0;
}
