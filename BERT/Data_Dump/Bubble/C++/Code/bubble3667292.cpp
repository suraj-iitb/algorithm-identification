#include<iostream>
using namespace std;
int main() {
    
    int n,flag;
    int count = 0;
    
    cin >> n;
    
    int a[n];
    
    for (int h = 0; h < n; h ++) {
        
        cin >> a[h];
        
    }
    
    flag = 1;
    
    while(flag) {
        
        flag = 0;
        
        for (int i = n-1; i > 0; i --) {
            
            if (a[i] < a[i-1]) {
                
                int k = a[i];
                
                a[i] = a[i-1];
                
                a[i-1] = k;
                
                flag = 1;
                
                count += 1;
                
            }
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
