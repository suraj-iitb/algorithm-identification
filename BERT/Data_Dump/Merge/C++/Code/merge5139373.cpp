#include<iostream>
using namespace std;

const int INFTY = 1000000000;

int cnt = 0;

void merge(int a[], int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;
    int l[n1 + 1];
    int r[n2 + 1];
    for (int i = 0; i < n1; i++) l[i] = a[left + i];
    for (int i = 0; i < n2; i++) r[i] = a[mid + i];
    l[n1] = INFTY;
    r[n2] = INFTY;
    int i = 0;
    int j = 0;
    for (int k = left; k < right; k++) {
        if (l[i] <= r[j]) {
            a[k] = l[i];
            i += 1;
        } else {
            a[k] = r[j];
            j += 1;
        }
        cnt += 1;
    }
}

void mergeSort(int a[], int left, int right) {
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        mergeSort(a, left, mid);
        mergeSort(a, mid, right);
        merge(a, left, mid, right);
    }
}

void print(int n, int a[]) {
    cout << a[0];
    for (int i = 1; i < n; i++) cout << " " << a[i];
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    int s[n];
    for (int i = 0; i < n; i++) cin >> s[i];
    mergeSort(s, 0, n);
    print(n, s);
    cout << cnt << endl;
    return 0;
}
