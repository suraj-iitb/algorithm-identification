#include <iostream>

using namespace std;

struct cards {
    int num;
    char ch;
    int id;
} a[100000];

int partition(cards *a, int p, int r) {
    int x = a[r].num;
    int i = p;
    for (int j = p; j < r; ++j) {
        if (a[j].num <= x)
            swap(a[i++], a[j]);
    }
    swap(a[i], a[r]);
    return i;
}

void quickSort(cards *a, int p, int r) {
    if (p < r) {
        int q = partition(a, p, r);
        quickSort(a, p, q - 1);
        quickSort(a, q + 1, r);
    }
}

bool checker(cards *a, int n) {
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
        cin >> a[i].ch >> a[i].num;
        a[i].id = i;
    }
    quickSort(a, 0, n - 1);
    if (checker(a, n))
        cout << "Stable" << endl;
    else
        cout << "Not stable" << endl;
    
    for (int i = 0; i < n; ++i) {
        cout << a[i].ch << " " << a[i].num << endl;
    }

    return 0;
    
}
