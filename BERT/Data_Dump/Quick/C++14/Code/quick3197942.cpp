#include <iostream>
using namespace std;
#define MAX 100000
#define SENTINEL 2000000000

struct Card {
    char suit;
    int value;
};

void merge(struct Card a[], int left, int mid, int right) {
    struct Card L[MAX / 2 + 2], R[MAX / 2 + 2];
    int n1 = mid - left;
    int n2 = right - mid;
    for (int i = 0; i < n1; i++) L[i] = a[left + i];
    for (int i = 0; i < n2; i++) R[i] = a[mid + i];
    L[n1].value = R[n2].value = SENTINEL;
    int i = 0, j = 0;
    for (int k = left; k < right; k++) {
        if(L[i].value <= R[j].value) {
            a[k] = L[i++];
        } else {
            a[k] = R[j++];
        }
    }
}

void mergeSort(struct Card a[], int n, int left, int right) {
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        mergeSort(a, n, left, mid);
        mergeSort(a, n, mid, right);
        merge(a, left, mid, right);
    }
}

int partition(struct Card a[], int p, int r) {
    struct Card x = a[r];
    int i = p - 1;
    for (int j = p; j < r; j++) {
        if (a[j].value <= x.value) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i+1], a[r]);
    return i + 1;
}

void quickSort(struct Card a[], int p, int r) {
    if (p < r) {
        int q = partition(a, p, r);
        quickSort(a, p, q - 1);
        quickSort(a, q + 1, r);
    }
}

int main() {
    int n, v;
    struct Card a[MAX], b[MAX];
    string s;
    int stable = true;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s >> v;
        a[i].suit = b[i].suit = s[0];
        a[i].value = b[i].value = v;
    }

    mergeSort(a, n, 0, n);
    quickSort(b, 0, n - 1);

    for (int i = 0; i < n; i++) {
        if (a[i].suit != b[i].suit) {
            stable = false;
            break;
        }
    }

    if (stable) {
        cout << "Stable" << endl;
    } else {
        cout << "Not stable" << endl;
    }
    for (int i = 0; i < n; i++) {
        cout << b[i].suit << " " << b[i].value << endl;
    }
}

