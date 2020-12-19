#include <iostream>

using namespace std;

struct Elem {
    int num;
    char pict;
    int id;
} a[100000];

int partition(Elem *a, int p, int r) {
    int x = a[r].num;
    int i = p;
    for (int j = p; j < r; ++j) {
        if (a[j].num <= x)
            swap(a[i++], a[j]);
    }
    swap(a[i], a[r]);
    return i;
}

void quickSort(Elem *a, int p, int r) {
    if (p < r) {
        int q = partition(a, p, r);
        quickSort(a, p, q - 1);
        quickSort(a, q + 1, r);
    }
}

bool isStable(Elem *a, int n) {
    for (int i = 0; i < n - 1; ++i) {
        if (a[i].num == a[i + 1].num) {
            if (a[i].id > a[i + 1].id)
                return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].pict >> a[i].num;
        a[i].id = i;
    }
    quickSort(a, 0, n - 1);
    if (isStable(a, n))
        cout << "Stable" << endl;
    else
        cout << "Not stable" << endl;
    
    for (int i = 0; i < n; ++i) {
        cout << a[i].pict << " " << a[i].num << endl;
    }

    return 0;
}
