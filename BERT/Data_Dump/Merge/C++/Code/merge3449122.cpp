#include <iostream>
using namespace std;
#define INF 2000000000
#define MAX 500000

void mergeSort(int left, int right);
void merge(int left, int mid, int right);
int A[MAX];
int L[MAX/2+2], R[MAX/2+2];
long long cnt = 0, N;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    mergeSort(0, N);

    for (int i = 0; i < N; i++) {
        if (i) 
            cout << ' ';
        cout << A[i];
    }
    cout << '\n';
    cout << cnt << '\n';
}


void merge(int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;
    for (int i = 0; i < n1; i++) 
        L[i] = A[left + i];
    for (int i = 0; i < n2; i++) 
        R[i] = A[mid + i];
    L[n1] = INF; R[n2] = INF;
    int i = 0, j = 0;
    for(int k = left ; k < right; k++) {
        cnt++;
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        }
        else {
            A[k] = R[j];
            j++;
        }
    }
}

void mergeSort(int left, int right) {
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        mergeSort(left, mid);
        mergeSort(mid, right);
        merge(left, mid, right);
    }
}

