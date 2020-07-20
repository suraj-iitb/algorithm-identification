#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;
int main() {
    int n,ans=0;
    cin >> n;
    int x[n];
    for(int i=0;i<n;i++){
        cin >> x[i];
    }
    for(int i=0;i<n-1;i++){
        for (int j=n-1; j>i; j--) {
            if(x[j]<x[j-1]){
                swap(x[j], x[j-1]);
                ans++;
            }
        }
    }
    for (int i=0; i<n; i++) {
        if(i==0)cout<< x[i];
        else cout <<" "<< x[i];
    }
    cout << endl << ans << endl;
    
}


