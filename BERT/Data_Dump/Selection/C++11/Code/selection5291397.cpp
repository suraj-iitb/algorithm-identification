#include <iostream>
#include <vector>
using namespace std;

int selectionSort(vector<int> &a, int n) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int minj = i;
        for (int j = i; j < n; j++) {
            if (a[j] < a[minj]) minj = j;
        }
        if (i != minj) {
            swap(a[i], a[minj]);
            cnt += 1;
        }
    }
    return cnt;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    int cnt = selectionSort(a, n);
    
    for (int i = 0; i < n; i++) {
        if (i == 0) cout << a[i];
        else cout << " " << a[i];
    }
    cout << endl;
    
    cout << cnt << endl;
}
