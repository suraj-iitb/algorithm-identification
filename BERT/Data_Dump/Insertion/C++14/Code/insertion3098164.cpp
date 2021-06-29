#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void print(vector<int>& v) {
        for (int i = 0; i < v.size(); ++i) {
            cout << v[i];
            if (i + 1 != v.size()) {
                cout << " ";
            }
        }
        cout << endl;
    }

    void InsertionSort(vector<int>& v) {
        int key = 0;
        for (int i = 1, j = 0; i < v.size(); ++i) {
            key = v[i];

            print(v);

            j = i - 1;
            while (j >= 0 && v[j] > key) {
                v[j + 1] = v[j];
                j--;
            }
            v[j + 1] = key;
        }
        print(v);

    }
};

int main() {
    int n = 0;
    cin >> n;
    vector<int> inp = vector<int>(n ,0);

    for (int i = 0; i < n; ++i) {
        cin >> inp[i];
    }
    (new Solution)->InsertionSort(inp);
}

