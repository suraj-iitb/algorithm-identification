#include<iostream>
using namespace std;
#define INFTY 1000000001
#define Max 500000

int cnt = 0;

void mergeSort(int a[], int left, int right);
void merge(int a[], int left, int mid, int right);

int main() {
    int n;
    cin >> n;
    int a[Max];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    mergeSort(a, 0, n);
    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << a[i];
    }
    cout << endl;
    cout << cnt << endl;
    return 0;
}
void mergeSort(int a[], int left, int right) {
    if (left < right-1) { //have more than 2
        int mid = (left + right) / 2;
        mergeSort(a, left , mid); //divide
        mergeSort(a, mid, right);
        merge(a, left, mid, right); //sort
    }
}
void merge(int a[], int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = a[left+i];
    for (int i = 0; i < n2; i++) R[i] = a[mid+i];
    L[n1] = INFTY; R[n2] = INFTY;
    int i = 0, j = 0;
    for (int k = left; k < right; k++) { //merge sort
        //left = 0   right = n
        cnt++;
        if (L[i] <= R[j]) { //be careful!
            a[k] = L[i++]; //stable
        } else {
            a[k] = R[j++];
        }
    }
}

