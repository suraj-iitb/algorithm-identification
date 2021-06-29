#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int> a) {
    for(int i=1; i<a.size(); i++) {
        int v = a[i];
        int j = i-1;
        while (j>=0 && a[j]>v) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
        for(auto e : a) {
            if(a.back() == e) cout << e << endl;
            else cout << e << " ";
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a;
    for(int i=0; i<n; i++) {
        int e;
        cin >> e;
        a.push_back(e);
    }
    for(auto e : a) {
        if(a.back() == e) cout << e << endl;
        else cout << e << " ";
    }
    insertionSort(a);
    return 0;
}
