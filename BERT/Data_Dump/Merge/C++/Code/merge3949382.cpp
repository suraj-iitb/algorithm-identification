#include <iostream>
#include <climits>

#define N 500000

using namespace std;

int merge(int A[], int left, int mid, int right) {
  int n1 = mid - left;
  int n2 = right - mid;
  //L[0...n1], R[0...n2] を生成
  int L[n1+1], R[n2+1];
  for(int i = 0; i < n1; i++) L[i] = A[left + i];
  for(int i = 0; i < n2; i++) R[i] = A[mid + i];
  L[n1] = INT_MAX;
  R[n2] = INT_MAX;
  int i = 0;  
  int j = 0;
  int count = 0;
  for(int k = left; k < right; k++) {
	if(L[i] <= R[j]) {
      A[k] = L[i];
      i = i + 1;
	  count++;
    }
    else {
      A[k] = R[j];
      j = j + 1;
	  count++;
    }
  }

  return count;
}

int mergeSort(int A[], int left, int right) {
  int count = 0;
  if(left+1 < right) {
    int mid = (left + right)/2;
    count += mergeSort(A, left, mid);
    count += mergeSort(A, mid, right);
    count += merge(A, left, mid, right);
  }

  return count;
}

int main(void)
{
  int n;
  cin >> n;
  int S[N];
  for(int i= 0; i<n; i++) cin >> S[i];

  int count = mergeSort(S, 0, n);

  for(int i= 0; i<n; i++) {
    if(i == n-1) cout << S[i] << endl;
    else cout << S[i] << " ";
  }
  cout << count << endl;

  return 0;
}
