#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void pri(int n, vector<int> &v) {
    for(int i=0;i<n;i++) {
        if(i) cout << " ";
        cout << v[i];
    }
    cout << "\n";
}

void insertion_sort(int n, vector<int> &v) {
    for(int i=0;i<n;i++) {
        for(int j=i-1;j>=0;j--) {
            if(v[j] > v[j+1])swap(v[j+1],v[j]);
        }
        pri(n,v);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++)cin >> v[i];
    insertion_sort(n,v);

    return 0;
}


