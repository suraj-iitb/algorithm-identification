#include <iostream>
using namespace std;

const int MAX = 500000;
const int MAXV = 1000000001;

int L[MAX / 2 + 2], R[MAX / 2 + 2];
int cnt;

void merge(int A[], int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;
    for (int i = 0; i < n1; i++) {
        L[i] = A[left + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = A[mid + i];
    }
    
    L[n1] = MAXV;
    R[n2] = MAXV;

    int i{ 0 }, j{ 0 };
    for (int k = left; k < right; k++) {
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

void mergeSort(int A[], int left, int right) {
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int main()
{
    int n, i;
    int A[MAX];
    //A = (int*)malloc(MAX);

    cnt = 0;

    cin >> n;
    for (i = 0; i < n;i++) {
        cin >> A[i];
    }
    
    mergeSort(A, 0, n);

    for (i = 0; i < n; i++) {
        if (i != 0) cout << " ";
        cout << A[i];
    }

    std::cout << "\n" << cnt << "\n";
}
