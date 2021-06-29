#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    vector<int> x(n);
    for (int i=0; i<n; i++){
        cin >> x[i];
    }
    
    int cnt = 0;
    
    for (int i=0; i<n-1; i++){
        int mini = i;
        for (int j = i+1; j<n; j++){
            if (x[j]<x[mini]) {
                mini = j;
            }
        }
        if (i != mini) {
            cnt++;
            swap(x[i],x[mini]);
        }
    }
    
    for (int i=0; i<n; i++){
        if (i) cout << " ";
        cout << x[i];
    }
    cout << endl << cnt << endl;
    return 0;
}
