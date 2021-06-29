#include <iostream>
using namespace std;

const int INFTY = 2e9;

struct Card{
    char M;
    int V;
};

Card A[100001], B[100001], L[50001], R[50001];

void merge(int left, int mid, int right){
    int n1 = mid - left;
    int n2 = right - mid;
    for(int i = 0; i < n1; i++) L[i] = A[left+i];
    for(int i = 0; i < n2; i++) R[i] = A[mid+i];
    L[n1].V = INFTY;
    R[n2].V = INFTY;
    int i = 0, j = 0;
    for(int k = left; k < right; k++){
        if(L[i].V <= R[j].V){
            A[k] = L[i];
            i++;
        }
        else{
            A[k] = R[j];
            j++;
        }
    }
}

void mergeSort(int left, int right){
    if(left+1 < right){
        int mid = (left + right) / 2;
        mergeSort(left, mid);
        mergeSort(mid, right);
        merge(left, mid, right);
    }
}

void MySwap(Card &a, Card &b){
  Card tmp = a;
  a = b;
  b = tmp;
}
  

int partition(int p, int r){
  int x = B[r].V;
  int i = p - 1;
  for(int j = p; j < r; j++){
    if(B[j].V <= x){
      MySwap(B[++i], B[j]);
    }
  }
  MySwap(B[++i], B[r]);
  return i;
}

void quicksort(int p, int r){
    if(p < r){
        int q = partition(p, r);
        quicksort(p, q-1);
        quicksort(q+1, r);
    }
}

int main(){
    int n;
    Card a;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a.M >> a.V;
        A[i] = a;
        B[i] = a;
    }
    mergeSort(0, n);
    quicksort(0, n - 1);
    bool f = false;
    for(int i = 0; i < n; i++) if(A[i].M != B[i].M) f = true;
    if(f) cout << "Not stable" << endl;
    else cout << "Stable" << endl;
    for(int i = 0; i < n; i++) cout << B[i].M << " " << B[i].V << endl;
    return 0;
}
