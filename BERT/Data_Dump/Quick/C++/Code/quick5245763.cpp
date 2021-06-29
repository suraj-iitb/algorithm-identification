#include<bits/stdc++.h>
using namespace std;

const int MAX = 100000;
long int INF = 10000000000;
struct Card {char suit; int value;};

int partition(struct Card A[], int p, int r) {
    int x = A[r].value;
    int i = p - 1;
    for (int j = p; j < r; j++) {
        if (A[j].value <= x) {
            i++;
            Card tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
        }
    }
    Card tmp = A[i+1];
    A[i+1] = A[r];
    A[r] = tmp;

    return i + 1;
}

void quickSort(struct Card A[], int p, int r) {
    if ( p < r ) {
        int q = partition(A, p, r); 
        quickSort(A, p, q-1);
        quickSort(A, q+1, r);
    }
}



void merge(struct Card A[], int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;
    Card L[MAX], R[MAX];
    for (int i = 0; i < n1; i++) {
        L[i] = A[left+i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = A[mid+i];
    }
    L[n1].value = INF;
    R[n2].value = INF;
    int i = 0;
    int j = 0;
    for (int k = left; k < right; k++) {
        if (L[i].value <= R[j].value ) {
            A[k] = L[i];
            i++;
        }
        else{
            A[k] = R[j];
            j++;
        }
    }

}

void mergeSort(struct Card A[], int left, int right) {
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int main() {
    int n;
    Card q_A[MAX], m_A[MAX];

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> q_A[i].suit >> q_A[i].value;
        m_A[i] = q_A[i];
    }

    quickSort(q_A, 0, n-1);
    mergeSort(m_A, 0, n);

    for (int i = 0; i < n; i++) {
        if ( q_A[i].suit != m_A[i].suit) {
            cout << "Not stable" << endl;
            break;
        }
        else if ( i == n-1) {
            cout << "Stable" << endl;
        }
    }
    for (int i = 0; i < n; i++ ){
        cout << q_A[i].suit << " " << q_A[i].value << endl;
    }

    return 0;
}

