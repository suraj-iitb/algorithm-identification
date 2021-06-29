#include <bits/stdc++.h> 
using namespace std; 
 
int main()  
{  
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }  
    int i, key, j;  
    for (i = 1; i < n; i++) 
    {  
        for (int m = 0; m < n; m++){
            if(m!=(n-1)){
                cout <<a[m]<<" ";
            }
            else{
                cout << a[m];
            }
        }
        
        cout << endl;
        key = a[i];  
        j = i - 1;  
  
        
        while (j >= 0 && a[j] > key) 
        {  
            a[j + 1] = a[j];  
            j = j - 1;  
        }  
        a[j + 1] = key;  
        
    }
    int x;  
    for (x = 0; x < n; x++){
        if (x != n-1){
            cout << a[x] << " ";
        }
        else{
            cout << a[x] <<endl;
        }
        
    }  
      
  
    return 0;  
}  
