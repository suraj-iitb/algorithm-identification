#include <iostream>
#include <vector>

using namespace std;

void printCurrent(vector<int> a) {
    for (int i = 0; i < a.size(); i++) {
        if (i != 0) {
            cout << " ";
        }
        cout << a[i];
    }
    cout << endl;
}

vector<int> insertionSort(vector<int> a) {
    for (int i = 1; i < a.size(); i++) {
        int v = a[i];
        int j = i - 1;
        while (j >=0 && a[j] > v) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = v;
        printCurrent(a);
    }
    return a;
}

int main() {
    int n;
    cin >> n;
    vector<int> a = vector<int>(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    printCurrent(a);
    insertionSort(a);

    return 0;
}
