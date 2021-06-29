#include <iostream>
using namespace std;
int main(void){
    int n;
    int a[105];
    
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    cout << a[0];
    for(int i=1; i<n; i++) {
        cout << " " << a[i]; 
    }
    cout << endl;
    
    int v;
    
    for(int i=1; i<n; i++) {
        v = a[i];
        int j = i - 1;
        while(j>=0 && a[j]>v) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
        
        cout << a[0];
        for(int i=1; i<n; i++) {
            cout << " " << a[i]; 
        }
        cout << endl;
    }
    return 0;
}

