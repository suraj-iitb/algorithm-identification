#include <iostream>
using namespace std;
#define MAX 500000
#define SENTINEL 2000000000//番兵を定義.

int L[MAX/2 + 2], R[MAX/2 + 2];
int count;

void merge(int A[], int n, int left, int mid, int right){
    int n1 = mid - left;
    int n2 = right - mid;
    int i = 0, j = 0;
    while(i < n1){
        L[i] = A[left + i];
        i += 1;
    }
    i = 0;
    while(i < n2){
        R[i] = A[mid + i];
        i += 1;
    }
    L[n1] = R[n2] = SENTINEL;
    i = 0;
    int k = left;
    while(k < right){//ここから33行目までで与えられた配列Aを大きい順に並び替える.
        count += 1;
        if (L[i] <= R[j]){
            A[k] = L[i];
            i += 1;
        } else {
            A[k] = R[j];
            j += 1;
        }
        k += 1;
    }
}
    
void mergesort (int A[], int n, int left, int right){
    if (left+1 < right){//leftに1を加えているのは, 2つ以上の要素を大小比較するためである.
        int mid = (left + right) / 2;
        mergesort(A, n, left, mid);//38, 39行目でmergesortを再帰的に呼び出して, 最終的には要素を1つずつに分割する.
        mergesort(A, n, mid, right);
        merge(A, n, left, mid, right);
    }
}
    
int main(){
    int A[MAX], n;
    int i = 0;
    count = 0;
    cin >> n;
    while(i < n){
        cin >> A[i];
        i += 1;
    }
    i = 0;
    mergesort(A, n, 0, n);
    while(i < n - 1){
        cout << A[i] << " ";
        i += 1;
    }
    cout << A[n - 1] << endl;
    cout << count << endl;
    
    return 0;
}
