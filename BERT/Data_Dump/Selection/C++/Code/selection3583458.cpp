#include <iostream>
#include <vector>

using namespace std;

int count;

void selectionSort(vector<int>& a) {
    for(int i=0; i<a.size(); i++) {
        int minj = i;
        for (int j=i; j<a.size(); j++) {
            if(a[j] < a[minj]) minj = j;
        }
        if(minj!=i){
            swap(a[i], a[minj]);
            count++;
        }
    }
}

int main() {
    int n; cin >> n;
    vector<int> a;
    for(int i=0; i<n; i++) {
        int e; cin>>e;
        a.push_back(e);
    }
    selectionSort(a);
    for(int i=0; i<a.size(); i++) {
        if(i==a.size()-1) cout << a[i] << endl;
        else cout << a[i] << " ";
    }
    cout << count << endl;
    return 0;
}
