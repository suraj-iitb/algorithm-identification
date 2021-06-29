#include <iostream>
#include <vector>
using namespace std;

int cnt;

void bubbleSort(vector<int> &a, int n) {
    bool flag = true;
    int i = 0;
    while (flag) {
        flag = false;
        for (int j = n-1; j > i; j--) {
            if (a[j] < a[j-1]) {
                swap(a[j], a[j-1]);
                flag = true;
                cnt++;
            }
        }
        i++;
    }
}

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    cnt = 0;
    bubbleSort(a, n);
    
    for (int i = 0; i < n; i++) {
        if (i == 0) cout << a[i];
        else cout << " " << a[i];
    }
    cout << endl;
    
    cout << cnt << endl;
}
