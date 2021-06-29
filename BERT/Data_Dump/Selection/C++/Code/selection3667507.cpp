#include<iostream>
using namespace std;
int main() {
    
    int n;
    int count = 0;
    
    cin >> n;
    
    int a[n];
    
    for (int h = 0; h < n; h ++) {
        
        cin >> a[h];
    
    }
    
    for (int i = 0; i < n; i ++) {
        
        int minj = i;
        
        for (int j = i; j < n; j ++) {
            
            if (a[j] < a[minj]) {
                
                minj = j;
                
            }
        }
        
        int k = a[i];
        
        a[i] = a[minj];
        
        a[minj] = k;
        
        if (i != minj) {
            
            count += 1;
            
        }
        
    }
    
    for (int j = 0; j < n; j ++) {
        
        if (j == n-1) {
            
            cout << a[j] << endl;
            
        } else {
            
            cout << a[j] << " ";
            
        }
        
    }
        
        cout << count << endl;
        
    
    
    return 0;

}
