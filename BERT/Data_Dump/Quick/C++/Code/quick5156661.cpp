#include<iostream>
#include<vector>
using namespace std;

const int INFTY = 1000000000;

struct Card {
    char key;
    int value;
};

int partition(vector<Card> &a, int p, int r) {
    int x = a[r].value;
    int i = p-1;
    for (int j = p; j < r; j++) {
        if (a[j].value <= x) {
            i += 1;
            swap(a[i], a[j]);
        }
    }
    swap(a[i+1], a[r]);
    return i+1;
}

void quickSort(vector<Card> &a, int p, int r) {
    if (p < r) {
        int q = partition(a, p, r);
        quickSort(a, p, q-1);
        quickSort(a, q+1, r);
    }
}

void merge(vector<Card> &a, int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;
    vector<Card> l(n1 + 1);
    vector<Card> r(n2 + 1);
    for (int i = 0; i < n1; i++) l[i] = a[left + i];
    for (int i = 0; i < n2; i++) r[i] = a[mid + i];
    l[n1] = Card{ 'z', INFTY };
    r[n2] = Card{ 'z', INFTY };
    int i = 0;
    int j = 0;
    for (int k = left; k < right; k++) {
        if (l[i].value <= r[j].value) {
            a[k] = l[i];
            i += 1;
        } else {
            a[k] = r[j];
            j += 1;
        }
        // cnt += 1;
    }
}

void mergeSort(vector<Card> &a, int left, int right) {
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        mergeSort(a, left, mid);
        mergeSort(a, mid, right);
        merge(a, left, mid, right);
    }
}

int main() {
    int n, value;
    char key;
    cin >> n;
    
    vector<Card> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> key >> value;
        a[i] = Card{ key, value };
        b[i] = Card{ key, value };
    }
    
    quickSort(a, 0, n-1);
    mergeSort(b, 0, n);
    
    bool stable = true;
    for (int i = 0; i < n; i++) {
        if (a[i].key != b[i].key) {
            stable = false;
            break;
        }
    }
    if (stable) cout << "Stable" << endl;
    else cout << "Not stable" << endl;
    
    for (int i = 0; i < n; i++) 
        cout << a[i].key << " " << a[i].value << endl;
    
    return 0;
}
