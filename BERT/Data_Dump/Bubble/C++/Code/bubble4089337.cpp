#include<bits/stdc++.h>
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
        for (int j = n-1; j>i; j--){
            if (x[j] < x[j-1]) {
                swap(x[j],x[j-1]);
                cnt++;
            }
        }
    }
    
    for (int i=0; i<n; i++){
        if (i) cout << " ";
        cout << x.at(i);
    }
    cout << endl;
    cout << cnt << endl;
    return 0;
}
