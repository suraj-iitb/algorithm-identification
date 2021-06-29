#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void print(vector<int> a) {
    for (int i = 0; i < a.size(); i++) {
        cout << a[i];
        if (i != a.size() - 1) cout << " ";
    }
    cout << endl;
}

void bubbleSort(vector<int> a) {
    int count = 0;
    for (int j = 0; j < a.size(); j++) {
        for (int i = 0; i < a.size() - 1; i++) {
            if (a[i] > a[i + 1]) {
                int tmp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = tmp;
                count++;
            }
        }
    }
    print(a);
    cout << count << endl;
    return;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    bubbleSort(a);
    return 0;
}
