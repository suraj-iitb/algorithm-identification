#include <iostream>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

void out(int n, int a[]){
    int i = 0;
    while (i < n - 1) {
        cout << a[i] << ' ';
        i++;
    }
    cout << a[n - 1] << endl;
}

int cnt = 0;
#define SENTINEL 2e9

void merge(int a[], int left, int mid, int right);
void mergesort(int a[], int left, int right);

int main(){
    int n;
    cin >> n;
    int a[n];
    rep(i, n) cin >> a[i];
    mergesort(a, 0, n);
    out(n, a);
    cout << cnt << endl;
}

void merge(int a[], int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;
    int l[n1 + 1];
    int r[n2 + 1];
    rep(i, n1) l[i] = a[left + i];
    rep(i, n2) r[i] = a[i + mid];
    l[n1] = r[n2] = SENTINEL;
    int i = 0, j = 0;
    for (int k = left; k < right; k++){
        cnt++;
        if (l[i] <= r[j]) {
            a[k] = l[i];
            i++;
        }
        else {
            a[k] = r[j];
            j++;
        }
    }
}

void mergesort(int a[], int left, int right) {
    if (left + 1 < right){
        int mid = (left + right) / 2;
        mergesort(a, left, mid);
        mergesort(a, mid, right);
        merge(a, left, mid, right);
    }
}
