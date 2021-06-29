#include <iostream>
#include <vector>

using namespace std;

int selection_sort(vector<int>& a) {
    int c = 0;
    for (int i = 0; i < a.size(); i++) {
        int minJ = i;
        for (int j = i + 1; j < a.size(); j++) {
            if (a[j] < a[minJ]) {
                minJ = j;
            }
        }
        if (minJ != i) {
            swap(a[i], a[minJ]);
            c++;
        }
    }
    return c;
}

int main() {
    int n;
    cin >> n;
    vector<int> a = vector<int>(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int count = selection_sort(a);
    for (int i = 0; i < a.size(); i++) {
        if (i != 0) {
            cout << " ";
        }
        cout << a[i];
    }
    cout << endl << count << endl;

    return 0;
}
