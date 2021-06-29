#include <iostream>
using namespace std;
int main(){
    int n; cin >> n;
    int a[n]; for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 1; i < n; ++i){
        for(int j = 0;j < n; ++j){
            if(j) cout << " ";
            cout << a[j];
        }
        cout << endl;
        int val = a[i];
        int j = i-1;
        while(j >= 0 && val < a[j]){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = val;
    }
    for(int j = 0;j < n; ++j){
        if(j) cout << " ";
        cout << a[j];
    }
    cout << endl;
    return 0;
}
