#include<iostream>
using namespace std;
static const int INF = 1000000001;

struct Card{
  char c;
  int num;
};

int partition(struct Card *A, int p, int r){
  int x = A[r].num;
  int i = p-1;
  for(int j=p; j<r; j++){
    if(A[j].num <= x){
      i++;
      swap(A[i], A[j]);
    }
  }
  swap(A[i+1], A[r]);
  return i+1;
}

void quickSort(struct Card *A, int p, int r){
  if(p < r){
    int q = partition(A, p, r);
    quickSort(A, p, q-1);
    quickSort(A, q+1, r);
  }
}

void print(struct Card *A, int n){
  for(int i=0; i<n; i++)
    cout << A[i].c << " " << A[i].num << endl;
}

void merge(struct Card *A, int left, int mid, int right){
  int n1 = mid -left;
  int n2 = right - mid;
  struct Card L[n1+1], R[n2+1];
  for(int i=0; i<n1; i++) L[i] = A[left + i];
  for(int i=0; i<n2; i++) R[i] = A[mid + i];
  L[n1].num = INF;
  R[n2].num = INF;
  int i=0, j=0;
  for(int k=left; k<right; k++){
    if(L[i].num <= R[j].num) A[k] = L[i++];
    else A[k] = R[j++];
  }
  return;
}

void mergeSort(struct Card *A, int left, int right){
  if(left+1 < right){
    int mid = (left+right) / 2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
  return;
}

int main(){
  int n;
  struct Card C[100000];
  struct Card M[100000];
  
  cin >> n;
  for(int i=0; i<n; i++){
    cin >> C[i].c >> C[i].num;
    M[i] = C[i];
  }

  quickSort(C, 0, n-1);
  mergeSort(M, 0, n);
  bool flag = false;
  for(int i=0; i<n; i++)
    if(C[i].c != M[i].c) flag = true;
  if(flag) cout << "Not stable";
  else cout << "Stable";
  cout << endl;
  print(C, n);
  return 0;
}

