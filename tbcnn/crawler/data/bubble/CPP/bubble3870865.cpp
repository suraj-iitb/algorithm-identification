#include<bits/stdc++.h>
using namespace std;

int bubbleSort(int l[], int n) {
    int count = 0;
    bool flag = 1;
    for(int i=0; flag; ++i) {
        flag = 0;
        for(int j=n-1; j>=1+i; --j) {
            if(l[j]<l[j-1]) {
                swap(l[j], l[j-1]);
                flag = 1;
                count++;
            }
        }
    }
    return count;
}

int main() {
    int n, l[100], count;
    cin >> n;
    for(int i=0; i<n; ++i) cin >> l[i];
    
    count = bubbleSort(l, n);
    
    for(int i=0; i<n; ++i) {
        if(i) cout << " ";
        cout << l[i];
    }
    cout << endl;
    cout << count << endl;
    
    return 0;
}
