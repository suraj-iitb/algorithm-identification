#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
 
int main() {
    int n; cin >> n;
    int a[n]; 
    for (int i = 0; i < n; i++) cin >> a[i];
    
    int count= 0;
    for (int i = 0; i < n; i++){
        int minindex = i;
        bool s = false;
        for (int j = i; j < n; j++){
            if (a[minindex] > a[j]){
                minindex = j;
                s = true;
            }
        }
        if (s){
            swap (a[i], a[minindex]);
            count++;
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << a[i];
    }
    cout << endl;
    cout << count << endl;
}
