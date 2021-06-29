#include <iostream>
#include <vector>
using namespace std;

void show(vector<int> a) {
    int n = a.size();
    for (int i = 0; i < n; i++) {
        if (i > 0) printf(" ");
        cout << a[i];
    }
    cout << endl;
}

void insertion_sort(vector<int>& a) {
    int n = (int)a.size();
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i-1;
        while (j >= 0 && a[j] > key) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
        show(a);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    show(a);
    insertion_sort(a);
    return 0;
}

