#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void print(vector<int> a){
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] ;
        if(i != a.size() - 1) cout << " ";
    }
    cout << endl;
}

void insertionSort(vector<int> a){
    for(int i = 1; i < a.size(); i++){
        print(a);
        int v = a[i];
        int j = i -1;
        while(j >= 0 && a[j] > v){
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = v;
    }
    print(a);
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    insertionSort(a);
    return 0;
}
