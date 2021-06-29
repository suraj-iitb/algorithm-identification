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

int bubble_sort(vector<int>& a) {
    int n = a.size();
    int sw = 0;
    for (int i = 0; i < n; i++) {
        for (int j = n-1; j > i; j--) {
            if (a[j] < a[j-1]) {
                swap(a[j], a[j-1]);
                sw++;
            }
        }
    }
    return sw;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int sw = bubble_sort(a);
    show(a);
    cout << sw << endl;
    return 0;
}

