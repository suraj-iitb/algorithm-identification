#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<int> a;
int num = 0;
int minj;

void selectionSort(int n) {
    for(int i=0; i<n; i++) {
       minj = i;
       for(int j=i; j<n; j++) {
           if(a[j] < a[minj]) {
               minj = j;
           }
       }
       if (a[i] != a[minj]) {
           swap(a[i], a[minj]);
           num++;
       }
    }
    return;
}

int main() {
    cin >> n;
    int tmp;
    for(int i=0; i<n; i++) {
        cin >> tmp;
        a.push_back(tmp);
    }
    selectionSort(n);
    for(int i=0; i<n-1; i++) {
        cout << a[i] << " ";
    }
    cout << a[n-1] << endl;
    cout << num << endl;
}
