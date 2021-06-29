#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> &a, int n) {
    for (int i = 0; i < n; i++) {
        if (i == 0) cout << a[i];
        else cout << " " << a[i];
    }
    cout << endl;
}

void insertSort(vector<int> &a, int n) {
    for (int i = 1; i < n; i++) {
        
        print(a, n);
        
        int v = a[i];
        int j = i;
        for (; j > 0; --j) {
            if (a[j-1] > v) a[j] = a[j-1];
            else break;
        }
        a[j] = v;
    }
}

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    insertSort(a, n);
    
    print(a, n);
}
