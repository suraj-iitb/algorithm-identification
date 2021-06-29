#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> a;
int num = 0;

void bubbleSort(int n) {
    bool flag = 1;
    while (flag) {
        flag = 0;
        for (int j=n-1; j>=1; j--) {
            if (a[j] < a[j-1]) {
                swap(a[j], a[j-1]);
                num++;
                flag = 1;
            }
        }
    }
    return ;
}

int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        int t;
        cin >> t;
        a.push_back(t);
    }
    bubbleSort(n);
    for (int i=0; i<n-1; i++) {
        cout << a[i] << " ";
    }
    cout << a[n-1] << endl;
    cout << num << endl;
    return 0;
}
