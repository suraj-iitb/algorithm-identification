#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int j=0;j<n;j++){
        cin >> a[j];
    }
    cout << a[0];
        for(int k=1; k< n; k++){
            cout << " " << a[k];
        }
        cout << endl;
    for(int i=1;i < n;i++){
        int v = a[i];
        int j = i -1;
        while ( j >= 0 && a[j] > v){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
        cout << a[0];
        for(int k=1; k< n; k++){
            cout << " " << a[k];
        }
        cout << endl;
    }
}
