#include<iostream>
#include<vector>

using namespace std;

void countingSort(vector<int> &a, vector<int> &b, int k, int n) {
    vector<int> c(k);
    for (int i = 0; i < k; i++) c[i] = 0;
    
    for (int j = 0; j < n; j++) c[a[j]] += 1;
    
    for (int i = 1; i < k; i++) c[i] += c[i-1];
    
    for (int i = n-1; i >= 0; i--) {
        b[c[a[i]]-1] = a[i];
        c[a[i]] -= 1;
    }
}

int main() {
    int n, k = 10001;
    cin >> n;
    
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    countingSort(a, b, k, n);
    
    cout << b[0];
    for (int i = 1; i < n; i++) cout << " " << b[i];
    cout << endl;
    
    return 0;
}
