#include <iostream>
using namespace std;

#define INF 1001001001
#define SIZE 500100

int L[SIZE / 2], R[SIZE / 2], cnt = 0;

void merge(int a[], int left, int middle, int right) {
    int n1 = middle - left, n2 = right - middle;
    for (int i = 0; i < n1; i++) L[i] = a[left + i];
    for (int i = 0; i < n2; i++) R[i] = a[middle + i];
    L[n1] = R[n2] = INF;
    int i = 0, j = 0;
    for (int k = left; k < right; k++) {
        if (L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        } else {
            a[k] = R[j];
            j++;
        }
        cnt++;
    }
    return;
}

void mergeSort(int a[], int left, int right) {
    if (left + 1 < right) {
        int middle = (left + right) / 2;
        mergeSort(a, left, middle);
        mergeSort(a, middle, right);
        merge(a, left, middle, right);
    }
    return;
}

void print(int n,int a[]) {
    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << a[i];
    }
    cout << endl;
    return;
}

int main() {
    int n, S[SIZE];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> S[i];
    mergeSort(S, 0, n);
    print(n, S);
    cout << cnt << endl;
    return 0;
}
