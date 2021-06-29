#include<iostream>
using namespace std;
int main() {
    
    int n = 0;
    
    cin >> n;
    
    int array[n];
    
    for (int h = 0; h < n; h ++) {
        
        cin >> array[h];
        
    }
    
    for (int i = 0; i < n; i ++) {
        
        int v = array[i];
        
        int j = i-1;
        
        while((j >= 0) && (array[j] > v)) {
            
            array[j+1] = array[j];
            
            j -= 1;
            
        }
        
        
        
        array[j+1] = v;
        
        
        for (int k = 0; k < n; k ++) {
            
            if (k == n-1) {
                
                cout << array[k] << endl;
                
            } else {
                
                cout << array[k] << " ";
                
            }
            
        }
        
        
        
    }
    
    return 0;
    
}
