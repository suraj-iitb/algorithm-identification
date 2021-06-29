#include <iostream>
#include <vector>

using namespace std;

int count=0;

void bubbleSort(vector<int>& a) {
    bool flag = true;
    while(flag) {
        flag = false;
        for(int j=a.size()-1; j>=1; j--) {
            if(a[j]<a[j-1]) {
                swap(a[j], a[j-1]);
                flag = true;
                count++;
            }
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
    bubbleSort(a);
    for(auto it = a.begin(); it!=a.end(); it++) {
        if(next(it)==a.end()) cout << *it << endl;
        else cout << *it << " ";
    }
    cout << count << endl;
    return 0;
}
