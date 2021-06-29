#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void counting_sort(const vector<int> &a, vector<int> &b, int k) {
    vector<int> c(k+1);
    for(auto&& x : a) c[x]++;
    for(int i=1; i<=k; i++) c[i] += c[i-1];
    for(int i=a.size()-1; i>=0; i--) b[--c[a[i]]] = a[i];
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    vector<int> b(n);
    counting_sort(a, b, 10000);
    for(int i=0; i<n; i++) cout << b[i] << (i==n-1 ? "\n" : " ");
}
